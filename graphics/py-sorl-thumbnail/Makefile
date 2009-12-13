# New ports collection makefile for:	py-sorl-thumbnail
# Date created:				24 November 2009
# Whom:					Kevin Golding <ports@caomhin.org>
#
# $FreeBSD$
#

PORTNAME=	sorl-thumbnail
PORTVERSION=	3.2.5
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	The sorl-thumbnail package provides an easy way to generate image thumbnails.

RUN_DEPENDS=	${LOCALBASE}/bin/pildriver.py:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS=	DJANGO "Enable Django" On \
		PDF "Enable PDF Thumbnails" Off \
		WORD "Enable Word Document thumbnail handling" Off \
		DOCS "Install HTML documentation (requires Sphinx)" Off

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

.if defined(WITH_DOCS)
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sphinx>0:${PORTSDIR}/textproc/py-sphinx
PORTDOCS=	*
.endif

post-build:
.if defined(WITH_DOCS)
	cd ${WRKSRC}/docs && ${MAKE} html
.endif

post-install:
.if defined(WITH_DOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/_build/html ${DOCSDIR}
.endif

.include <bsd.port.mk>
