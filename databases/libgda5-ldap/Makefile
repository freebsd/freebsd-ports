PORTREVISION=	4
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
