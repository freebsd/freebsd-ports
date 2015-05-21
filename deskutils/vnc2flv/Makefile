# $FreeBSD$

PORTNAME=	vnc2flv
PORTVERSION=	20100207
PORTREVISION=	1
CATEGORIES=	deskutils multimedia www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Captures a VNC desktop session and saves as a flv

.if empty(PORT_OPTIONS:MX11)
RUN_DEPENDS+=	x11vnc:${PORTSDIR}/net/x11vnc
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
