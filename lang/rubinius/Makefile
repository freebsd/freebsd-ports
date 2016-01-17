# Created by: stas
# $FreeBSD$

PORTNAME=	rubinius
PORTVERSION=	2.5.2
CATEGORIES=	lang
MASTER_SITES=	http://releases.rubini.us/:source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	LLVM based ruby language implementation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/bundle:${PORTSDIR}/sysutils/rubygem-bundler \
		${LOCALBASE}/bin/llvm-config35:${PORTSDIR}/devel/llvm35 \
		${LOCALBASE}/bin/bison:${PORTSDIR}/devel/bison

BROKEN_FreeBSD_9=	does not build
BROKEN_FreeBSD_11=	does not build

BROKEN_RUBY23=	yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-P "${PREFIX}" \
		-I "${PREFIX}/include/rubinius" \
		-L "${PREFIX}/lib/ruby/rubinius" \
		-G "${PREFIX}/lib/ruby/gems/rubinius" \
		-B "${PREFIX}/bin" \
		-M "${PREFIX}/man" \
		--cc ${CC} \
		--cxx ${CXX} \
		--no-bin-links \
		--llvm-config ${LOCALBASE}/bin/llvm-config35 \
		--with-fibers --without-dtrace --release-build \
		--sitedir "${PREFIX}/lib/ruby/site_ruby/rubinius" \
		--vendordir "${PREFIX}/lib/ruby/vendor_ruby/rubinius" \
		--stagingdir "${STAGEDIR}${PREFIX}" --with-execinfo \
		--system-name ${OPSYS}

USES=		perl5 gmake tar:bzip2 readline compiler:c++11-lib libedit
USE_OPENSSL=	yes
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
USE_PERL5=	build
NO_INSTALL=	yes
PLIST_SUB+=	FREEBSD_DIR=${FREEBSD_DIR}
GEM_PATH=	${WRKSRC}/gems/ruby/${RUBY_VER}
RAKE_BIN=	${GEM_PATH}/bin/rake

# Hack to prevent rbx from creating $HOME/.rbx during compilation of gems
MAKE_ENV+=	HOME=${WRKSRC}

# Hack to switch to a local gem path so locally activated rake can be used
MAKE_ENV+=	GEM_PATH=${GEM_PATH}

# Hack to build under a UTF-8 locale
MAKE_ENV+=	LANG=en_US.UTF-8

F_OS=		${OPSYS:tl}
F_MAJOR=	${OSREL:C/\..*$//}
FREEBSD_DIR=	${F_ARCH}-${F_OS}-${F_MAJOR}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
LIB_DEPENDS+=		libexecinfo.so:${PORTSDIR}/devel/libexecinfo
CONFIGURE_ARGS+=	--with-opt-dir "${LOCALBASE}"
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.elif ${ARCH} == "amd64"
F_ARCH=		x86_64
.elif ${ARCH} == "i386"
F_ARCH=		x86
.endif

post-extract:
.for DF in ${DISTFILES:N*\:source}
	@${LN} -s ${DISTDIR}/${DF:C/:gems//g} ${WRKSRC}/vendor/cache/
.endfor

post-patch:
	@${GREP} -Rl '#!.*ruby$$'  ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -e '/^#!.*ruby$$/s/ruby$$/${RUBY_NAME}/g'

pre-configure:
	@cd ${WRKSRC} && ${MKDIR} gems && ${LOCALBASE}/bin/bundle install --local --path=${WRKSRC}/gems

do-build:
	# "build" target here installs into ${STAGEDIR}${PREFIX}
	@(cd ${WRKSRC}/; ${SETENV} ${MAKE_ENV} ${RAKE_BIN} -j ${MAKE_JOBS_NUMBER} build)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ruby/site_ruby/rubinius
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ruby/vendor_ruby/rubinius
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/ruby/site_ruby/rubinius/.keep_me
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/ruby/vendor_ruby/rubinius/.keep_me
	@${MV} ${STAGEDIR}${PREFIX}/bin/testrb ${STAGEDIR}${PREFIX}/bin/testrbx
	@${FIND} ${STAGEDIR} -type f -name '*.so' |${XARGS} ${STRIP_CMD}
	@${FIND} ${STAGEDIR} -type f -name 'gem_make.out' -delete
	@${FIND} ${STAGEDIR} -type f -name 'mkmf.log' -delete
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rbx

plist:
	@truncate -s0 pkg-plist
	@${ECHO_CMD} "bin/rbx" >> pkg-plist
	@${ECHO_CMD} "bin/testrbx" >> pkg-plist
#
# Includes
#
	@${FIND} -ds ${STAGEDIR}${PREFIX}/include/rubinius ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/*,,' >> pkg-plist
	@${FIND} -ds ${STAGEDIR}${PREFIX}/include/rubinius -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/*,@dirrm ,' >> pkg-plist
#
# Libs
#
	@${FIND} -ds ${STAGEDIR}${PREFIX}/lib/ruby/rubinius ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/*,,' >> pkg-plist
	@${FIND} -ds ${STAGEDIR}${PREFIX}/lib/ruby/rubinius -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/*,@dirrm ,' >> pkg-plist
#
# Kernel and Runtime
#
	@${FIND} -ds ${STAGEDIR}${PREFIX}/rubinius ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/*,,' >> pkg-plist
	@${FIND} -ds ${STAGEDIR}${PREFIX}/rubinius -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/*,@dirrm ,' >> pkg-plist
#
# Gems
#
	@${FIND} -ds ${STAGEDIR}${PREFIX}/lib/ruby/gems/rubinius ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/*,,' >> pkg-plist
	@${FIND} -ds ${STAGEDIR}${PREFIX}/lib/ruby/gems/rubinius -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/*,@dirrm ,' >> pkg-plist
#
# Site libs and vendor libs
#
	@${FIND} -ds ${STAGEDIR}${PREFIX}/lib/ruby/site_ruby/rubinius ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/*,,' >> pkg-plist
	@${FIND} -ds ${STAGEDIR}${PREFIX}/lib/ruby/site_ruby/rubinius -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/*,@dirrm ,' >> pkg-plist
	@${FIND} -ds ${STAGEDIR}${PREFIX}/lib/ruby/vendor_ruby/rubinius ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/*,,' >> pkg-plist
	@${FIND} -ds ${STAGEDIR}${PREFIX}/lib/ruby/vendor_ruby/rubinius -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/*,@dirrm ,' >> pkg-plist
#
# Shared dirs
#
	@${ECHO_CMD} "@dirrmtry lib/ruby/site_ruby" >> pkg-plist
	@${ECHO_CMD} "@dirrmtry lib/ruby/vendor_ruby" >> pkg-plist
	@${ECHO_CMD} "@dirrmtry lib/ruby/gems" >> pkg-plist
	@${ECHO_CMD} "@dirrmtry lib/ruby" >> pkg-plist

.include <bsd.port.post.mk>
