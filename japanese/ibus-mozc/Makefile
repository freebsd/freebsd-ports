PKGNAMEPREFIX=	ja-ibus-

COMMENT=	Mozc engine for IBus

DATADIR=	${PREFIX}/share/ibus-${PORTNAME}

MASTERDIR=	${.CURDIR}/../../japanese/mozc-server
SUB_FILES=	pkg-message-ibus
PKGMESSAGE=	${WRKDIR}/pkg-message-ibus

BUILD_MOZC_LIST=	ibus_mozc

.include "${MASTERDIR}/Makefile"
