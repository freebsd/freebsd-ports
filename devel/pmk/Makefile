# New ports collection makefile for:	pmk
# Date created:		October 13, 2003
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pmk
PORTVERSION=	0.8.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pmk

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Pre Make Kit, a sane replacement for autoconf

MAN1=	pmk.1 pmkscan.1 pmkinstall.1
MAN5=	pmk.conf.5 pmkfile.5
MAN8=	pmksetup.8

do-configure:
	cd ${WRKSRC}; SYSCONFDIR=${PREFIX}/etc ./pmkcfg.sh

.include <bsd.port.mk>
