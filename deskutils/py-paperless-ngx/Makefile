PORTNAME=	paperless-ngx
DISTVERSIONPREFIX=	v
DISTVERSION=	2.18.2
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

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.6:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=6.2.0:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}concurrent-log-handler>=0.9.19:sysutils/py-concurrent-log-handler@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateparser>=1.2.2:devel/py-dateparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-channels-redis>=4.3.0:www/py-dj51-channels-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-allauth>=65.11.0:www/py-dj51-django-allauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-auditlog>=3.0.0:www/py-dj51-django-auditlog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-celery-results>=2.6.0:www/py-dj51-django-celery-results@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-compression-middleware>=0.5.0:www/py-dj51-django-compression-middleware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-cors-headers>=4.7.0:www/py-dj51-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-extensions>=3.2.3:www/py-dj51-django-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-filter>=25.1:www/py-dj51-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-multiselectfield>=0.1.13:www/py-dj51-django-multiselectfield@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-soft-delete>=1.0.16:www/py-dj51-django-soft-delete@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-djangorestframework-guardian>=0.3.0:www/py-dj51-djangorestframework-guardian@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-drf-spectacular>=0.28.0:www/py-dj51-drf-spectacular@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-drf-writable-nested>=0.7.2:www/py-dj51-drf-writable-nested@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}filelock>=3.17.0:sysutils/py-filelock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flower>=2.0.1:www/py-flower@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gotenberg-client>=0.10.0:converters/py-gotenberg-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}granian>=2.5.0:www/py-granian@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}h2>=4.1.0:www/py-h2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}hiredis>=3.0.0:databases/py-hiredis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httptools>=0.6.4:www/py-httptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}httpx-oauth>=0.10.1:www/py-httpx-oauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}imap-tools>=1.11.0:mail/py-imap-tools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}inotifyrecursive>=0.3.5_2:devel/py-inotifyrecursive@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}langdetect>=1.0.9:textproc/py-langdetect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mysqlclient>=2.2.7:databases/py-mysqlclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nltk>=3.8.1:textproc/py-nltk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ocrmypdf>=16.10.1:textproc/py-ocrmypdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathvalidate>=3.3.1:devel/py-pathvalidate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdf2image>=1.17.0:graphics/py-pdf2image@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdftotext>=3.0.0:textproc/py-pdftotext@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.9.10:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dotenv>=1.1.0:www/py-python-dotenv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-gnupg>=0.5.1:security/py-python-gnupg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ipware>=2.0.3:net/py-python-ipware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-magic>=0.4.27:devel/py-python-magic@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyzbar>=0.1.9:graphics/py-pyzbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapidfuzz>=3.13.0:devel/py-rapidfuzz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scikit-learn>=1.4.0:science/py-scikit-learn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setproctitle>=1.3.3:devel/py-setproctitle@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tika-client>=0.7.0:textproc/py-tika-client@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvloop>=0.21.0:devel/py-uvloop@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchdog>=6.0.0:devel/py-watchdog@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}watchfiles>=0.24.0:devel/py-watchfiles@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockets>=15.0.1:devel/py-websockets@${PY_FLAVOR} \
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
