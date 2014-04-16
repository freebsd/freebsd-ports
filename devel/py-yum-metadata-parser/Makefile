# Created by: Anders F Bjorklund <afb@rpm5.org>
# $FreeBSD$

PORTNAME=	yum-metadata-parser
PORTVERSION=	1.1.4
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://yum.baseurl.org/download/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	afb@rpm5.org
COMMENT=	A fast metadata parser for yum

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		glib-2.0:${PORTSDIR}/devel/glib20

USES=		pkgconfig
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_AUTOPLIST=	yes

.include <bsd.port.mk>
