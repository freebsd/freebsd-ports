# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/databases/libgda5-jdbc/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTREVISION=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	5-jdbc

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides Java DB Connector backend for the libgda5 library

MASTERDIR=	${.CURDIR}/../libgda5
BUILD_WRKSRC=	${WRKSRC}/providers/jdbc
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA5_SLAVE=	jdbc

.include "${MASTERDIR}/Makefile"
