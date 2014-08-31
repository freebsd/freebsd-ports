# Created by: ijliao
# $FreeBSD$

PORTNAME=	libruin
PORTVERSION=	0.1.4
PORTREVISION=	2
CATEGORIES=	devel scheme
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Renderer for User Interfaces in Ncurses

BUILD_DEPENDS=	${LOCALBASE}/share/guile/site/config/load.scm:${PORTSDIR}/devel/guile-lib
RUN_DEPENDS=	${LOCALBASE}/share/guile/site/config/load.scm:${PORTSDIR}/devel/guile-lib

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=	libruin

.include <bsd.port.mk>
