# New ports collection makefile for:    xine_d4d_plugin
# Date created:         28 Aug 2001
# Whom:                 HIYAMA Takeshi <gibbon@cocoa.freemail.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	xine_d4d_plugin
PORTVERSION=	0.3.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.geocities.com/captain_css/

MAINTAINER=	gibbon@cocoa.freemail.ne.jp

LIB_DEPENDS=	xine.0:${PORTSDIR}/graphics/libxine

GNU_CONFIGURE=	yes
USE_X_PREFIX=		yes
INSTALLS_SHLIB=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
