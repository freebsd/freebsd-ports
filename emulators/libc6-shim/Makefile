PORTNAME=	libc6-shim
DISTVERSION=	20251025
CATEGORIES=	emulators

MAINTAINER=	iwtcex@gmail.com
COMMENT=	ABI-compatible glibc shim library
WWW=		https://github.com/shkhln/libc6-shim

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim
RUN_DEPENDS=	libepoll-shim-i386>=0:devel/libepoll-shim@i386

USES=	ruby
USE_GITHUB=	yes
GH_ACCOUNT=	shkhln
GH_PROJECT=	libc6-shim

PORTSCOUT=	ignore:1

post-patch:
	${REINPLACE_CMD} -e 's|../icds|../${DATADIR_REL}/icds|' ${WRKSRC}/bin/nv-sglrun
	${REINPLACE_CMD} -e 's|../lib64|../lib/${PORTNAME}|' -e 's|../lib32|../lib32/${PORTNAME}|' ${WRKSRC}/bin/c6-shim-env

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib32/${PORTNAME}
	${MKDIR} ${STAGEDIR}${DATADIR}/icds/ocl
	${MKDIR} ${STAGEDIR}${DATADIR}/icds/vk
	${INSTALL_SCRIPT} \
		${WRKSRC}/bin/c6-shim-env \
		${WRKSRC}/bin/c6-shim-run-exe \
		${WRKSRC}/bin/nv-sglrun \
		${STAGEDIR}${PREFIX}/bin
	${LN} -s c6-shim-env ${STAGEDIR}${PREFIX}/bin/with-glibc-shim
	${INSTALL_LIB} \
		${WRKSRC}/build/lib64/libc6*.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${INSTALL_LIB} \
		${WRKSRC}/build/lib32/libc6*.so \
		${STAGEDIR}${PREFIX}/lib32/${PORTNAME}
	${INSTALL_DATA} \
		${WRKSRC}/icds/ocl/nv.icd \
		${STAGEDIR}${DATADIR}/icds/ocl
	${INSTALL_DATA} \
		${WRKSRC}/icds/vk/nv.json \
		${STAGEDIR}${DATADIR}/icds/vk

.include <bsd.port.mk>
