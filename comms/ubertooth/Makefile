# Created by: George V. Neville-Neil <gnn@freebsd.org>
# $FreeBSD$

PORTNAME=	ubertooth
PORTVERSION=	201808R1
CATEGORIES=	comms

MAINTAINER=	gnn@FreeBSD.org
COMMENT=	Bluetooth Baseband Library

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/../COPYING

BUILD_DEPENDS=	python27:lang/python27 \
		pyside-py27:devel/pyside \
		${PYNUMPY} \
		libbtbb:comms/libbtbb

USES=		cmake:outsource

USE_GITHUB=	yes
GH_ACCOUNT=	greatscottgadgets
GH_TAGNAME=	2018-08-R1

WRKSRC_SUBDIR=	host
.include <bsd.port.mk>
