# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	FSM
PORTVERSION=	1.4.0
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Finite State Machine

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=	pear

OPTIONS_DEFINE=	PEAR_GRAPGHVIZ
PEAR_GRAPGHVIZ_DESC=	PEAR::GraphViz support

PEAR_GRAPGHVIZ_RUN_DEPENDS=	${PEARDIR}/GraphViz.php:graphics/pear-Image_GraphViz@${PHP_FLAVOR}

.include <bsd.port.mk>
