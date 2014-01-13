# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

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

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DJANGO PDF WORD
DJANGO_DESC=	Enable Django
PDF_DESC=	PDF Thumbnails
WORD_DESC=	Word Document thumbnail handling

OPTIONS_DEFAULT=	DJANGO

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDJANGO}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/django/bin/django-admin.py:${PORTSDIR}/www/py-django
.endif

.if ${PORT_OPTIONS:MPDF}
RUN_DEPENDS+=	${LOCALBASE}/bin/Magick-config:${PORTSDIR}/graphics/ImageMagick
.endif

.if ${PORT_OPTIONS:MWORD}
RUN_DEPENDS+=	wvVersion:${PORTSDIR}/textproc/wv
.endif

.include <bsd.port.mk>
