# Created by: stas
# $FreeBSD$

PORTNAME=	rubinius
PORTVERSION=	3.86
CATEGORIES=	lang
MASTER_SITES=	http://releases.rubini.us/:source
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	LLVM based ruby language implementation

LICENSE=	MPL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/bundle:sysutils/rubygem-bundler \
		${LOCALBASE}/bin/bison:devel/bison \
		${LLVM_CONFIG_PATH}:${LLVM_PORT}
LIB_DEPENDS=	libyaml.so:textproc/libyaml

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-P "${PREFIX}" \
		-I "${PREFIX}/include/rubinius" \
		-L "${PREFIX}/lib/ruby/rubinius" \
		-G "${PREFIX}/lib/ruby/gems/rubinius" \
		-B "${PREFIX}/bin" \
		-M "${PREFIX}/man" \
		--cc ${LLVM_CC_PATH} \
		--cxx ${LLVM_CXX_PATH} \
		--llvm-config ${LLVM_CONFIG_PATH} \
		--no-bin-links \
		--without-dtrace --release-build \
		--sitedir "${PREFIX}/lib/ruby/site_ruby/rubinius" \
		--vendordir "${PREFIX}/lib/ruby/vendor_ruby/rubinius" \
		--stagingdir "${STAGEDIR}${PREFIX}" --with-execinfo \
		--system-name ${OPSYS}

OPTIONS_RADIO=		LLVM
OPTIONS_DEFAULT=	LLVM40
OPTIONS_RADIO_LLVM=	LLVM38 LLVM39 LLVM40

ONLY_FOR_ARCHS=	amd64

LLVM38_DESC=	LLVM 3.8
LLVM39_DESC=	LLVM 3.9
LLVM40_DESC=	LLVM 4.0

USES=		gmake perl5 readline tar:bzip2 libedit ssl
USE_LOCALE=	en_US.UTF-8
USE_RUBY=	yes
RUBY_NO_RUN_DEPENDS=	yes
USE_PERL5=	build
NO_INSTALL=	yes
PLIST_SUB+=	FREEBSD_DIR=${FREEBSD_DIR}
GEM_PATH=	${WRKSRC}/gems/ruby/${RUBY_VER}
RAKE_BIN=	${GEM_PATH}/bin/rake

# https://github.com/rubinius/rubinius/issues/3716
CFLAGS+=	-Qunused-arguments
CPPFLAGS+=	-Qunused-arguments
CXXFLAGS+=	-Qunused-arguments

# Hack to prevent rbx from creating $HOME/.rbx during compilation of gems
MAKE_ENV+=	HOME=${WRKSRC}

# Hack to switch to a local gem path so locally activated rake can be used
MAKE_ENV+=	GEM_PATH=${GEM_PATH}

F_OS=		${OPSYS:tl}
F_MAJOR=	${OSREL:C/\..*$//}
FREEBSD_DIR=	${F_ARCH}-${F_OS}-${F_MAJOR}
LLVM_CC_PATH=	${LOCALBASE}/bin/${LLVM_CC}
LLVM_CXX_PATH=	${LOCALBASE}/bin/${LLVM_CXX}
LLVM_CONFIG_PATH=	${LOCALBASE}/bin/${LLVM_CONFIG}

LLVM38_VARS=	LLVM_CONFIG=llvm-config38 \
		LLVM_PORT=devel/llvm38 \
		LLVM_CC=clang38 \
		LLVM_CXX=clang++38
LLVM39_VARS=	LLVM_CONFIG=llvm-config39 \
		LLVM_PORT=devel/llvm39 \
		LLVM_CC=clang39 \
		LLVM_CXX=clang++39
LLVM40_VARS=	LLVM_CONFIG=llvm-config40 \
		LLVM_PORT=devel/llvm40 \
		LLVM_CC=clang40 \
		LLVM_CXX=clang++40

.include <bsd.port.pre.mk>

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
	@${CP} ${FILESDIR}/build-tool.c ${WRKDIR}

post-patch:
	@${GREP} -Rl '#!.*ruby$$'  ${WRKSRC} |${XARGS} ${REINPLACE_CMD} -e '/^#!.*ruby$$/s/ruby$$/${RUBY_NAME}/g'
	@${REINPLACE_CMD} -e "s,%%CC%%,${LLVM_CC_PATH}," ${WRKSRC}/configure ${WRKDIR}/build-tool.c
	@${REINPLACE_CMD} -e "s,%%CXX%%,${LLVM_CXX_PATH}," ${WRKSRC}/configure ${WRKDIR}/build-tool.c

pre-configure:
	@cd ${WRKSRC} && ${MKDIR} gems && ${LOCALBASE}/bin/bundle install --local --path=${WRKSRC}/gems

post-configure:
	# Setup paths to compilers
	@${CC} -o ${WRKSRC}/build/bin/build-tool ${WRKDIR}/build-tool.c
	@${LN} -sf ${WRKSRC}/build/bin/build-tool ${WRKSRC}/build/bin/cc
	@${LN} -sf ${WRKSRC}/build/bin/build-tool ${WRKSRC}/build/bin/c++

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

.include <bsd.port.post.mk>
