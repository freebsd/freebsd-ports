PORTREVISION=	3
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	5-postgresql

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides postgresql access for the libgda5 library

MASTERDIR=	${.CURDIR}/../libgda5
BUILD_WRKSRC=	${WRKSRC}/providers/postgres/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA5_SLAVE=	postgresql

.include "${MASTERDIR}/Makefile"
