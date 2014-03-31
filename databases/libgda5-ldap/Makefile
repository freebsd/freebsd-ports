# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/databases/libgda5-ldap/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTREVISION=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	5-ldap

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides ldap access for the libgda5 library

MASTERDIR=	${.CURDIR}/../libgda5
BUILD_WRKSRC=	${WRKSRC}/providers/ldap/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA5_SLAVE=	ldap

.include "${MASTERDIR}/Makefile"
