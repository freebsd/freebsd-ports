# Created by: Anders F Bjorklund <afb@rpm5.org>
# $FreeBSD$

PORTNAME=	yum-metadata-parser
PORTVERSION=	1.1.4
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	http://yum.baseurl.org/download/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	afb@rpm5.org
COMMENT=	Fast metadata parser for yum

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libsqlite3.so:databases/sqlite3 \
		libglib-2.0.so:devel/glib20

USES=		pkgconfig python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
