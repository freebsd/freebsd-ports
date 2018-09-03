# Created by: George V. Neville-Neil <gnn@freebsd.org>
# $FreeBSD$

PORTNAME=	libbtbb
PORTVERSION=	201808R1
CATEGORIES=	comms

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Bluetooth Baseband Library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BIULD_DEPENDS=	pyside-py27:devel/pyside \
		${PYNUMPY}

USES=		cmake:outsource \
		python

USE_GITHUB=	yes
GH_ACCOUNT=	greatscottgadgets
GH_TAGNAME=	2018-08-R1

.include <bsd.port.mk>
