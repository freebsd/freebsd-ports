# New ports collection makefile for:	ngspice_rework
# Date created:		2002-01-02
# Whom:			AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ngspice_rework
PORTVERSION=	14
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ngspice
DISTNAME=	ng-spice-rework-${PORTVERSION}

MAINTAINER=	amakawa@jp.FreeBSD.org

USE_AUTOCONF_VER?=	213

pre-configure:
		(cd ${WRKSRC} && ${AUTOHEADER})

.include <bsd.port.mk>
