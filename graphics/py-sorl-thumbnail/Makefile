# New ports collection makefile for:	py-sorl-thumbnail
# Date created:				24 November 2009
# Whom:					Kevin Golding <ports@caomhin.org>
#
# $FreeBSD$
#

PORTNAME=	sorl-thumbnail
PORTVERSION=	3.2.5
PORTREVISION=	3
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Sorl-thumbnail provides an easy way to generate image thumbnails

LICENSE=	BSD

RUN_DEPENDS=	${LOCALBASE}/bin/pildriver.py:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS=	DJANGO "Enable Django" On \
		PDF "Enable PDF Thumbnails" Off \
		WORD "Enable Word Document thumbnail handling" Off

.include <bsd.port.options.mk>

.if !defined(WITHOUT_DJANGO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django
.endif

.if defined(WITH_PDF)
RUN_DEPENDS+=	${LOCALBASE}/bin/Magick-config:${PORTSDIR}/graphics/ImageMagick
.endif

.if defined(WITH_WORD)
RUN_DEPENDS+=	wvVersion:${PORTSDIR}/textproc/wv
.endif

.include <bsd.port.mk>
