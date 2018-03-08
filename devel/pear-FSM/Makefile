# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	FSM
PORTVERSION=	1.4.0
CATEGORIES=	devel www pear

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PEAR Finite State Machine

OPTIONS_DEFINE=	PEAR_GRAPGHVIZ
PEAR_GRAPGHVIZ_DESC=	PEAR::GraphViz support

USES=		pear

PEAR_GRAPGHVIZ_RUN_DEPENDS=	${PEARDIR}/GraphViz.php:graphics/pear-Image_GraphViz@${PHP_FLAVOR}

.include <bsd.port.mk>
