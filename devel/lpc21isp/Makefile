# New ports collection makefile for:	lpc21isp
# Date created:		2009-01-30
# Whom:			Steve Franks
#
# $FreeBSD$
#

PORTNAME=	lpc21isp
PORTVERSION=	1.64
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	bahamasfranks@gmail.com
COMMENT=	ISP programmer tool for flashing NXP & Analog Devices ARM7 CPUs

USE_GMAKE=	yes

PLIST_FILES=	bin/lpc21isp

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
