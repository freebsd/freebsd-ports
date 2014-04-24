# Created by: stas
# $FreeBSD$

PORTNAME=	rubinius
PORTVERSION=	2.2.5
CATEGORIES=	lang
MASTER_SITES=	http://releases.rubini.us/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	LLVM based ruby language implementation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Fails to build

BUILD_DEPENDS=	${LOCALBASE}/bin/bundle:${PORTSDIR}/sysutils/rubygem-bundler \
		${LOCALBASE}/bin/llvm-config34:${PORTSDIR}/devel/llvm34 \
		${LOCALBASE}/bin/bison:${PORTSDIR}/devel/bison

HAS_CONFIGURE=	yes
#execinfo is broken for unknow reason
CONFIGURE_ARGS=	-P "${PREFIX}" \
		-I "${PREFIX}/include/rubinius" \
		-L "${PREFIX}/lib/ruby/rubinius" \
		-G "${PREFIX}/lib/ruby/gems/rubinius" \
		-B "${PREFIX}/bin" \
		-M "${PREFIX}/man" \
		--cc ${CC} \
		--cxx ${CXX} \
		--no-bin-links \
		--llvm-config ${LOCALBASE}/bin/llvm-config34 \
		--sitedir "${PREFIX}/lib/ruby/site_ruby/rubinius" \
		--vendordir "${PREFIX}/lib/ruby/vendor_ruby/rubinius" \
		--stagingdir "${STAGEDIR}${PREFIX}"

USE_BZIP2=	yes
USES=		perl5 gmake
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
USE_RAKE=	yes
USE_PERL5=	build
NO_INSTALL=	yes
PLIST_SUB+=	FREEBSD_DIR=${FREEBSD_DIR}

# Hack to prevent rbx from creating $HOME/.rbx during compilation of gems
MAKE_ENV+=	HOME=${WRKSRC}

F_OS=		${OPSYS:L}
F_MAJOR=	${OSREL:C/\..*$//}
FREEBSD_DIR=	${F_ARCH}-${F_OS}-${F_MAJOR}

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.elif ${ARCH} == "amd64"
F_ARCH=		x86_64
.elif ${ARCH} == "i386"
F_ARCH=		x86
.endif

post-patch:
	@${GREP} -Rl '#!.*ruby$$'  ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -e '/^#!.*ruby$$/s/ruby$$/${RUBY_NAME}/g'

pre-configure:
	cd ${WRKSRC} && ${MKDIR} gems && ${LOCALBASE}/bin/bundle install --local --path=${WRKSRC}/gems

do-build:
	# "build" target here installs into ${STAGEDIR}${PREFIX}
	@(cd ${WRKSRC}/; ${SETENV} ${MAKE_ENV} ${RAKE_BIN} -j ${MAKE_JOBS_NUMBER} build)
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ruby/site_ruby/rubinius
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ruby/vendor_ruby/rubinius
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/ruby/site_ruby/rubinius/.keep_me
	@${TOUCH} ${STAGEDIR}${PREFIX}/lib/ruby/vendor_ruby/rubinius/.keep_me

plist:
	truncate -s0 pkg-plist
	@${ECHO_CMD} "bin/rbx" >> pkg-plist
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
