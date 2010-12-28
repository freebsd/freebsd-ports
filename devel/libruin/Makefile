# ex:ts=8
# Ports collection makefile for:	libruin
# Date created:			Mar 22, 2007
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libruin
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	devel scheme
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Renderer for User Interfaces in Ncurses

BUILD_DEPENDS=	${LOCALBASE}/share/guile/site/config/load.scm:${PORTSDIR}/devel/guile-lib
RUN_DEPENDS=	${LOCALBASE}/share/guile/site/config/load.scm:${PORTSDIR}/devel/guile-lib

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN3=	ruin.3
INFO=	libruin

.include <bsd.port.mk>
