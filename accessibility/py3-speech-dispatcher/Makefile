# $FreeBSD$

PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	Common interface to speech synthesis python bindings

SPEECH_SLAVE=	yes

MASTERDIR=	${.CURDIR}/../speech-dispatcher

BUILD_WRKSRC=	${WRKSRC}/src/api/python
INSTALL_WRKSRC=	${WRKSRC}/src/api/python

PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
