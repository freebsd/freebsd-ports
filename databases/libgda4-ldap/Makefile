# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgda4-ldap/Makefile,v 1.3 2011/10/15 15:18:35 kwm Exp $

PORTREVISION=	2
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	4-ldap

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides ldap access for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/ldap/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	ldap

.include "${MASTERDIR}/Makefile"
