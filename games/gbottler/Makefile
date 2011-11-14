# New ports collection makefile for:	gbottler
# Date created:				3 Apr 2004
# Whom:					UMENO Takashi
#
# $FreeBSD$
#

PORTNAME=	gbottler
PORTVERSION=	0.1.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	gbottler/45155

MAINTAINER=	umeno@rr.iij4u.or.jp
COMMENT=	SSTP Bottle client

RUN_DEPENDS=	${PYXML}

PLIST_SUB=	VERSION=${PORTVERSION}

USE_GNOME=	pygtk2
USE_PYTHON=	yes
USE_GMAKE=	yes

.include <bsd.port.mk>
