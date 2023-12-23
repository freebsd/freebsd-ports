PORTREVISION=	0

PKGNAMESUFFIX?=  -qt6

COMMENT=	Portable Delphi-like IDE for the FreePascal compiler (QT6)

CONFLICTS=	lazarus-gtk2 lazarus-gtk2-devel lazarus-qt5 lazarus-qt5-devel \
		lazarus-qt6-devel

LIB_DEPENDS=	libQt6Pas.so:x11-toolkits/qt6pas

LCL_PLATFORM=	qt6

MASTERDIR=	${.CURDIR}/../../editors/lazarus

.include "${MASTERDIR}/Makefile"
