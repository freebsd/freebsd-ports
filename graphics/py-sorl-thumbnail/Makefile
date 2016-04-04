# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	sorl-thumbnail
PORTVERSION=	3.2.5
PORTREVISION=	6
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Sorl-thumbnail provides an easy way to generate image thumbnails

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow

USES=		python
USE_PYTHON=	autoplist distutils

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

OPTIONS_DEFINE=	DJANGO PDF WORD
DJANGO_DESC=	Enable Django
PDF_DESC=	PDF Thumbnails
WORD_DESC=	Word Document thumbnail handling

OPTIONS_DEFAULT=	DJANGO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDJANGO}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:www/py-django18
.endif

.if ${PORT_OPTIONS:MPDF}
RUN_DEPENDS+=	${LOCALBASE}/bin/Magick-config:graphics/ImageMagick
.endif

.if ${PORT_OPTIONS:MWORD}
RUN_DEPENDS+=	wvVersion:textproc/wv
.endif

.include <bsd.port.mk>
