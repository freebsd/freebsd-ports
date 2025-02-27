CATEGORIES=	accessibility audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python bindings for Speech Dispatcher

MASTERDIR=	${.CURDIR:H}/speech-dispatcher

BUILD_WRKSRC=	${WRKSRC}/src/api/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST=		${.CURDIR}/pkg-plist

_SD_PYTHON=	yes

.include "${MASTERDIR}/Makefile"
