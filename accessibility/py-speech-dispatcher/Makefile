# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	accessibility audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Python bindings for Speech Dispatcher

SPEECH_SLAVE=	yes

MASTERDIR=	${.CURDIR:H}/speech-dispatcher

BUILD_WRKSRC=	${WRKSRC}/src/api/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}

PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
