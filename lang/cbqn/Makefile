PORTNAME=		cbqn
DISTVERSIONPREFIX=	v
DISTVERSION=		0.12.0
CATEGORIES=		lang

MAINTAINER=		siva@FreeBSD.org
COMMENT=		BQN implementation in C
WWW=			https://github.com/dzaima/CBQN

LICENSE=		APACHE20 BSL GPLv3 LGPL3 MIT MPL20
LICENSE_COMB=		multi
LICENSE_FILE_APACHE20=	${WRKSRC}/licenses/LICENSE-Apache2
LICENSE_FILE_BSL=	${WRKSRC}/licenses/LICENSE-Boost
LICENSE_FILE_GPLv3=	${WRKSRC}/licenses/LICENSE-GPLv3
LICENSE_FILE_LGPL3=	${WRKSRC}/licenses/LICENSE-LGPLv3
LICENSE_FILE_MIT=	${WRKSRC}/licenses/LICENSE-MIT-sort
LICENSE_FILE_MPL20=	${WRKSRC}/licenses/LICENSE-MPL2

USES=			gmake pkgconfig

USE_GITHUB=		yes
GH_ACCOUNT=		dzaima
GH_PROJECT=		CBQN
GH_TUPLE=		dzaima:replxx:5e3bd870699007b9536d29f60e3a2b0a68ce0a7a:replxx/build/replxxLocal \
			dzaima:cbqnBytecode:156b47caf895f6706811c5c34bbbbaf192b8018b:cbqnBytecode/build/bytecodeLocal \
			mlochbaum:Singeli:5187ed3aa22a2257b63c04a5498ec756fa6263cb:Singeli/build/singeliLocal \
			mlochbaum:BQN:3d8f6876d9fb2a055e164137ab058ba70bffda1c:mlochbaumBQN/test/mlochbaumBQN

MAKEFILE=		makefile
ALL_TARGET=		default
MAKE_ARGS=		notui=1 nogit=1 version=${DISTVERSION}

OPTIONS_DEFINE=		FFI
OPTIONS_DEFAULT=	FFI

FFI_DESC=		FFI support
FFI_MAKE_ARGS_OFF=	FFI=0
FFI_LIB_DEPENDS=	libffi.so:devel/libffi

PLIST_FILES=		bin/bqn \
			include/bqnffi.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bqn

do-test:
	(cd ${WRKSRC} && bqn -M 1000 test/mlochbaumBQN/test/this.bqn)
	(cd ${WRKSRC}/test/cases && ${FIND} . -type f -name '*.bqn' | ${XARGS} bqn ../run.bqn)

.include <bsd.port.mk>
