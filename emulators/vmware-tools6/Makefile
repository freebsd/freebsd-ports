# New ports collection makefile for:	VMware tools for FreeBSD
# Date created:		10 Aug 2000
# Whom:			matusita@jp.FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	vmware
#PORTREVISION?=	0
MASTER_SITES=	# bundled with VMware Workstation
PKGNAMESUFFIX?=	-tools

COMMENT=VMware Tools for guest OS (VMware Workstation 6.x, FreeBSD version)

MASTERDIR=	${.CURDIR}/../vmware-guestd6
DESCR=		${PKGDIR}/pkg-descr.tools
PLIST=		${PKGDIR}/pkg-plist.tools

VMWARE_X_PORTS=	YES

.include "${MASTERDIR}/Makefile"
