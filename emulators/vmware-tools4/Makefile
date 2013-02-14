# Created by: matusita@jp.FreeBSD.org
# $FreeBSD$

PORTNAME=	vmware
MASTER_SITES=	# bundled with VMware itself
PKGNAMESUFFIX?=	-tools

COMMENT=VMware tools for guest OS (for VMware 4.x, FreeBSD version)

DEPRECATED=	No more supported upstream
EXPIRATION_DATE=	2013-03-14

MASTERDIR=	${.CURDIR}/../vmware-guestd4
DESCR=		${PKGDIR}/pkg-descr.tools
PLIST=		${PKGDIR}/pkg-plist.tools

VMWARE_X_PORTS=	YES

.include "${MASTERDIR}/Makefile"
