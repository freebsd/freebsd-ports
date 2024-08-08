PORTREVISION=	1
PKGNAMESUFFIX=	-qt5

MASTERDIR=	${.CURDIR}/../ppsspp

# XXX No VULKAN per https://github.com/hrydgard/ppsspp/blob/v1.10/Qt/QtMain.cpp#L711-L712
OPTIONS_EXCLUDE=	${OPTIONS_DEFINE}
OPTIONS_SLAVE=		QT5

.include "${MASTERDIR}/Makefile"
