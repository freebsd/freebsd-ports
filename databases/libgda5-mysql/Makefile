PORTREVISION=	2
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	5-mysql

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides mysql backend for the libgda5 library

MASTERDIR=	${.CURDIR}/../libgda5
BUILD_WRKSRC=	${WRKSRC}/providers/mysql/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist
MYSQL_VARS=	IGNORE_WITH_MYSQL="84"
LIBGDA5_SLAVE=	mysql

.include "${MASTERDIR}/Makefile"
