# $FreeBSD$

PORTNAME=	python-rrdtool
PORTVERSION=	1.4.7
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	robak@FreeBSD.org
COMMENT=	Python bindings for RRDTool, the graphing and logging utility

LICENSE=	LGPL3

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

LIB_DEPENDS=	librrd.so:databases/rrdtool

USES=		gnome groff pkgconfig python:2.7
USE_GNOME=	cairo glib20 libxml2 pango
USE_PYTHON=	distutils autoplist

LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
