# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-qt5

MASTERDIR=	${.CURDIR}/../ppsspp

OPTIONS_SLAVE=	QT5
# XXX https://github.com/hrydgard/ppsspp/blob/v1.6.3/Qt/QtMain.cpp#L533-L534
OPTIONS_EXCLUDE=VULKAN

.include "${MASTERDIR}/Makefile"
