# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#	$MCom: ports/graphics/py-cairo/Makefile,v 1.28 2010/11/15 14:12:13 kwm Exp $

PORTNAME=	cairo
PORTVERSION=	1.8.10
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	http://cairographics.org/releases/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py2${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python 2 bindings for Cairo

WRKSRC=		${WRKDIR}/py${PORTNAME}-${PORTVERSION}
USE_PYTHON=	2
USES=		gmake pathfix pkgconfig shebangfix
USE_GNOME=	cairo
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

python_OLD_CMD?=	/usr/bin/env python
python_CMD?=		${LOCALBASE}/bin/python2
SHEBANG_FILES=		examples/*.py examples/*/*.py setup.py test/*.py

post-patch:
	@${REINPLACE_CMD} -e 's|SUBDIRS = cairo examples test|SUBDIRS = cairo examples|g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
