# $FreeBSD$

PORTNAME=	paperless
PORTVERSION=	2.7.0
PORTREVISION=	4
CATEGORIES=	deskutils python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Index and archive scanned paper documents

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateparser>=0.7.1:devel/py-dateparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-cors-headers>=2.4.0:www/py-dj22-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-crispy-forms>=1.7.2:www/py-dj22-django-crispy-forms@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-extensions>=2.1.6:www/py-dj22-django-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-filter>=2.0.0:www/py-dj22-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-djangoql>=0.12.4:www/py-dj22-djangoql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-djangorestframework>=3.9.0:www/py-dj22-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fuzzywuzzy>=0.15.1:devel/py-fuzzywuzzy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langdetect>=1.0.7:textproc/py-langdetect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdftotext>=2.1.1:textproc/py-pdftotext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyocr>=0.5.3:graphics/py-pyocr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=0.10.1:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gnupg>=0.4.3:security/py-python-gnupg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>=0.4.10:devel/py-python-magic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	gpg2:security/gnupg \
		optipng:graphics/optipng \
		tesseract:graphics/tesseract \
		unpaper:graphics/unpaper

USES=		python:3.5+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	the-paperless-project
GH_PROJECT=	paperless
USE_RC_SUBR=	paperless-consumer

SHEBANG_FILES=	${WRKSRC}/src/manage.py

SUB_FILES=	README nginx.conf paperless.7 pkg-message sshd_config uwsgi.ini
SUB_LIST=	PKGBASE=${PKGBASE} PYTHON_CMD=${PYTHON_CMD} \
		PYTHONPREFIX_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR} \
		ECHO=${ECHO} EGREP=${EGREP} TOUCH=${TOUCH} \
		CHOWN=${CHOWN} RM=${RM:Q}

NO_ARCH=	yes

USERS=		paperless
GROUPS=		paperless

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_SINGLE=		IMAGICK
OPTIONS_SINGLE_IMAGICK=	IMAGICK6_NOX11 IMAGICK6_X11 IMAGICK7_NOX11 IMAGICK7_X11
OPTIONS_DEFAULT=	IMAGICK6_X11

IMAGICK_DESC=		${IMAGEMAGICK_DESC}
IMAGICK6_NOX11_DESC=	ImageMagick6 without X11 support
IMAGICK6_X11_DESC=	ImageMagick6 with X11 support
IMAGICK7_NOX11_DESC=	ImageMagick7 without X11 support
IMAGICK7_X11_DESC=	ImageMagick7 with X11 support

DOCS_BUILD_DEPENDS=	${PY_SPHINX}
DOCS_USES=		gmake

IMAGICK6_X11_RUN_DEPENDS=	convert:graphics/ImageMagick6
IMAGICK6_NOX11_RUN_DEPENDS=	convert:graphics/ImageMagick6-nox11
IMAGICK7_X11_RUN_DEPENDS=	convert:graphics/ImageMagick7
IMAGICK7_NOX11_RUN_DEPENDS=	convert:graphics/ImageMagick7-nox11

PORTDOCS=	*

PAPERLESS_STATICDIR=	${WRKSRC}/static

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${WRKSRC}/src
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${WRKSRC}/src
	@${RM} -r ${PAPERLESS_STATICDIR}
	@${SETENV} \
		PAPERLESS_STATICDIR=${PAPERLESS_STATICDIR} \
		${PYTHON_CMD} ${WRKSRC}/src/manage.py collectstatic

do-build-DOCS-on:
	cd ${WRKSRC}/docs && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} html SPHINXBUILD=sphinx-build-${PYTHON_VER}

post-build-DOCS-on:
	@${RM} ${WRKSRC}/docs/_build/html/.buildinfo

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/paperless
	@cd ${WRKSRC}/resources && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/src && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/paperless
	@${RLN} ${STAGEDIR}${PYTHON_SITELIBDIR}/paperless/manage.py \
		${STAGEDIR}${PREFIX}/bin/paperless
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKSRC} && \
		${COPYTREE_SHARE} static ${STAGEDIR}${WWWDIR}
	@${SED} -e 's|%%WWWDIR%%|${WWWDIR}|g;' \
		${WRKSRC}/paperless.conf.example \
		> ${STAGEDIR}${PREFIX}/etc/paperless.conf.sample
	@${MKDIR} ${STAGEDIR}/var/db/paperless/consume/input \
		${STAGEDIR}/var/db/paperless/media \
		${STAGEDIR}/var/db/paperless/sqlite
	${INSTALL_MAN} ${WRKDIR}/paperless.7 ${STAGEDIR}${MANPREFIX}/man/man7

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/presentation
	@cd ${WRKSRC}/docs/_build/html && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/presentation && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/presentation

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} \
		${WRKDIR}/README \
		${WRKDIR}/nginx.conf \
		${WRKDIR}/sshd_config \
		${WRKDIR}/uwsgi.ini \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
