# New ports collection makefile for:	vnc2flv
# Date created:		December 23 2010
# Whom:			Jason Helfman <jhelfman@experts-exchange.com>
#
# $FreeBSD$
#

PORTNAME=	vnc2flv
PORTVERSION=	20100207
CATEGORIES=	deskutils multimedia www python
MASTER_SITES=	${MASTER_SITE_CHEESESHOP}
MASTER_SITE_SUBDIR=	source/v/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jhelfman@experts-exchange.com
COMMENT=	Captures a VNC desktop session and saves as a flv

.if !defined(WITHOUT_X11)
RUN_DEPENDS+=	x11vnc:${PORTSDIR}/net/x11vnc
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	${PORTNAME}
PYDISTUTILS_PKGVERSION=	${PORTVERSION}

.include <bsd.port.mk>
