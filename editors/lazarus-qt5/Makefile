PORTREVISION=	0

PKGNAMESUFFIX?=  -qt5

COMMENT=	Portable Delphi-like IDE for the FreePascal compiler (QT5)

CONFLICTS=	lazarus-gtk2 lazarus-gtk2-devel lazarus-qt5-devel lazarus-qt6 \
		lazarus-qt6-devel

LIB_DEPENDS=	libQt5Pas.so:x11-toolkits/qt5pas

LCL_PLATFORM=	qt5

MASTERDIR=	${.CURDIR}/../../editors/lazarus

.include "${MASTERDIR}/Makefile"
