# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	4-jdbc

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides Java database Connector backend for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/jdbc
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	jdbc

.include "${MASTERDIR}/Makefile"
