# New ports collection makefile for:	VMware tools for FreeBSD
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware
MASTER_SITES=	# bundled with VMware itself
PKGNAMESUFFIX?=	-tools

COMMENT=VMware tools for guest OS (for VMware 4.x, FreeBSD version)

MASTERDIR=	${.CURDIR}/../vmware-guestd4
DESCR=		${PKGDIR}/pkg-descr.tools
PLIST=		${PKGDIR}/pkg-plist.tools

VMWARE_X_PORTS=	YES

.include "${MASTERDIR}/Makefile"
