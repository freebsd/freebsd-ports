PORTNAME=	readur
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.6
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	LOCAL/dtxdf/${PORTNAME}/
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}.frontend${EXTRACT_SUFX} \
		swagger-ui-${SWAGGER_TAG}.zip

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Quick, painless, intuitive OCR platform
WWW=		https://github.com/readur/${PORTNAME}

LICENSE=	MIT

LIB_DEPENDS=	libleptonica.so:graphics/leptonica \
		libtesseract.so:graphics/tesseract
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}ocrmypdf>=0:textproc/py-ocrmypdf@${PY_FLAVOR} \
		poppler-utils>=0:graphics/poppler-utils

USES=		cargo llvm:build pkgconfig python ssl
USE_GITHUB=	yes
USE_RC_SUBR=	${PORTNAME}

CARGO_INSTALL_ARGS=	--bin ${PORTNAME}

MAKE_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib \
		SWAGGER_UI_DOWNLOAD_URL=file:${DISTDIR}/swagger-ui-${SWAGGER_TAG}.zip

SUB_FILES=	pkg-message
SUB_LIST=	USER=${READUR_USER}

PLIST_SUB=	GROUP=${READUR_GROUP} \
		HOMEDIR=${READUR_HOMEDIR} \
		USER=${READUR_USER}

READUR_USER=	www
READUR_GROUP=	${READUR_USER}
READUR_HOMEDIR=	/var/db/${PORTNAME}

SWAGGER_TAG=	v5.17.14

post-patch:
	@${REINPLACE_CMD} -e 's|%%WWWDIR%%|${WWWDIR}|' \
		${WRKSRC}/src/main.rs

post-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKDIR}/readur-frontend && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}${READUR_HOMEDIR}

.include <bsd.port.mk>
