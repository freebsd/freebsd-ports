PORTNAME=	paperless-ngx
PORTVERSION=	2.11.0
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils python
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/:webui \
		GH:gh
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${EXTRACT_SUFX}:webui

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Community-supported supercharged version of paperless
WWW=		https://docs.paperless-ngx.com

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}bleach>=6.1.0:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}concurrent-log-handler>=0.9.19:sysutils/py-concurrent-log-handler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateparser>=1.1.4:devel/py-dateparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}channels-redis>=4.2.0:www/py-channels-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-allauth>=0.59.0:www/py-django-allauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-auditlog>=2.3.0:www/py-django-auditlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-celery-results>=2.5.1:www/py-django-celery-results@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-compression-middleware>=0.5.0:www/py-django-compression-middleware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-cors-headers>=4.3.1:www/py-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-extensions>=3.2.3:www/py-django-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-filter>=23.5:www/py-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-multiselectfield>=0.1.12:www/py-django-multiselectfield@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-soft-delete>=1.0.13:www/py-django-soft-delete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework-guardian>=0.3.0:www/py-djangorestframework-guardian@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}drf-writable-nested>=0.7.0:www/py-drf-writable-nested@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.13.1:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flower>=2.0.1:www/py-flower@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gotenberg-client>=0.5.0:converters/py-gotenberg-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=21.2.0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h2>=4.1.0:www/py-h2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hiredis>=2.0.0:databases/py-hiredis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httptools>=0.6.1:www/py-httptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imap-tools>=1.5.0:mail/py-imap-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inotifyrecursive>=0.3.5_1:devel/py-inotifyrecursive@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langdetect>=1.0.9:textproc/py-langdetect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mysqlclient>=2.2.1:databases/py-mysqlclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>=3.8.1:textproc/py-nltk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ocrmypdf>=15.4.4:textproc/py-ocrmypdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathvalidate>=3.2.0:devel/py-pathvalidate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdf2image>=1.17.0:graphics/py-pdf2image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdftotext>=2.2.2:textproc/py-pdftotext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.9.9:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.0.0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gnupg>=0.5.1:security/py-python-gnupg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ipware>=2.0.1:net/py-python-ipware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>=0.4.27:devel/py-python-magic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzbar>=0.1.9:graphics/py-pyzbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>=3.6.1:devel/py-rapidfuzz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.4.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.3.2:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tika-client>=0.5.0:textproc/py-tika-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>=0.25.0:www/py-uvicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvloop>=0.17.0:devel/py-uvloop@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>=4.0.0:devel/py-watchdog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchfiles>=0.21.0:devel/py-watchfiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=12.0:devel/py-websockets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whitenoise>=6.2.0:www/py-whitenoise@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whoosh>=2.7.4:textproc/py-whoosh@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.1:devel/py-pyyaml@${PY_FLAVOR}
RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	gpg2:security/gnupg \
		liberation-fonts-ttf>=2.1.3:x11-fonts/liberation-fonts-ttf \
		optipng:graphics/optipng \
		tesseract:graphics/tesseract \
		unpaper:graphics/unpaper

USES=		python shebangfix tar:xz
USE_GITHUB=	yes
GH_ACCOUNT=	paperless-ngx
USE_RC_SUBR=	paperless-beat paperless-consumer paperless-flower \
		paperless-migrate paperless-webui paperless-worker

SHEBANG_FILES=	${WRKSRC}/src/manage.py

CONFLICTS_INSTALL=	${PYTHON_PKGNAMEPREFIX}*paperless

NO_ARCH=	yes

SUB_FILES=	nginx.conf paperless paperless-ngx.7 pkg-message README sshd_config
SUB_LIST=	CHOWN=${CHOWN} \
		ECHO=${ECHO} \
		EGREP=${EGREP} \
		PKGBASE=${PKGBASE} \
		PYTHON_CMD=${PYTHON_CMD} \
		PYTHONPREFIX_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR} \
		RM=${RM:Q} \
		TOUCH=${TOUCH}

USERS=		paperless
GROUPS=		paperless

PORTDOCS=	*

OPTIONS_DEFINE=		DOCS EXAMPLES
OPTIONS_DEFAULT=	IMAGICK7_X11
OPTIONS_SINGLE=		IMAGICK
OPTIONS_SINGLE_IMAGICK=	IMAGICK6_NOX11 IMAGICK6_X11 IMAGICK7_NOX11 IMAGICK7_X11

IMAGICK6_NOX11_DESC=	ImageMagick6 without X11 support
IMAGICK6_X11_DESC=	ImageMagick6 with X11 support
IMAGICK7_NOX11_DESC=	ImageMagick7 without X11 support
IMAGICK7_X11_DESC=	ImageMagick7 with X11 support
IMAGICK_DESC=		${IMAGEMAGICK_DESC}

IMAGICK6_NOX11_USES=	magick:6,run,nox11
IMAGICK6_X11_USES=	magick:6,run
IMAGICK7_NOX11_USES=	magick:7,run,nox11
IMAGICK7_X11_USES=	magick:7,run

PAPERLESS_STATICDIR=	${WRKSRC}/static

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/src/paperless/settings.py

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-x ".*/tests/" \
		-f ${WRKSRC}/src
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-x ".*/tests/" \
		-f ${WRKSRC}/src
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py \
		-d ${PYTHONPREFIX_SITELIBDIR} \
		-f ${WRKSRC}/gunicorn.conf.py
	@${RM} -r ${PAPERLESS_STATICDIR}
	@${SETENV} \
		PAPERLESS_STATICDIR=${PAPERLESS_STATICDIR} \
		${PYTHON_CMD} ${WRKSRC}/src/manage.py collectstatic -i tests

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/paperless
	@cd ${WRKSRC}/resources && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	@cd ${WRKSRC}/src && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PYTHON_SITELIBDIR}/paperless
	@cd ${WRKSRC} && ${COPYTREE_SHARE} gunicorn.conf.py \
		${STAGEDIR}${PYTHON_SITELIBDIR}/paperless
	@${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.orig' -delete
	@cd ${WRKDIR} && ${INSTALL_SCRIPT} paperless ${STAGEDIR}${PREFIX}/bin
	@${SED} -e 's|%%WWWDIR%%|${WWWDIR}|g;' \
		${WRKSRC}/paperless.conf.example \
		> ${STAGEDIR}${PREFIX}/etc/paperless.conf.sample
	@${MKDIR} ${STAGEDIR}/var/db/paperless/consume/input \
		${STAGEDIR}/var/db/paperless/data/log \
		${STAGEDIR}/var/db/paperless/media \
		${STAGEDIR}/var/db/paperless/nltkdata
	${INSTALL_MAN} ${WRKDIR}/paperless-ngx.7 ${STAGEDIR}${PREFIX}/share/man/man7
	${MKDIR} ${STAGEDIR}${WWWDIR}
	@cd ${WRKDIR}/${PORTNAME} && ${COPYTREE_SHARE} static ${STAGEDIR}${WWWDIR}
	@${MKDIR} ${STAGEDIR}/var/run/paperless

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}/docs && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} \
		${WRKDIR}/README \
		${WRKDIR}/nginx.conf \
		${WRKDIR}/sshd_config \
		${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
