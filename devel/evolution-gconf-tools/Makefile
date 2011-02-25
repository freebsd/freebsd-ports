# New ports collection makefile for:	evolution-gconf-tools
# Date created:		2005-07-22
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/evolution-gconf-tools/Makefile,v 1.2 2005/10/14 20:39:56 adamw Exp $
#

PORTNAME=	evolution-gconf-tools
PORTVERSION=	0.1.6
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://people.redhat.com/dmalcolm/evolution-gconf-tools/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Scripts to make it easier to work with Evolution's configuration

RUN_DEPENDS=	evolution:${PORTSDIR}/mail/evolution

GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomeprefix

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${SH}|' \
		${WRKSRC}/lib/*

.include <bsd.port.mk>
