PORTREVISION=	2
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	5-mysql

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides mysql backend for the libgda5 library

MASTERDIR=	${.CURDIR}/../libgda5
BUILD_WRKSRC=	${WRKSRC}/providers/mysql/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA5_SLAVE=	mysql

.include "${MASTERDIR}/Makefile"
