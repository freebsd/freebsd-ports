# Created by: will
# $FreeBSD$

PORTNAME=	viewvc
DISTVERSION=	1.1.26
CATEGORIES=	devel python

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Web-based Version Control Repository Browsing

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=		WEBSRV APMOD SVN MYSQL
OPTIONS_DEFAULT=	WEBSRV APACHE SVN

OPTIONS_SINGLE=		WEBSRV APMOD
OPTIONS_SINGLE_WEBSRV=	APACHE LIGHTTPD
OPTIONS_SINGLE_APMOD=	MODPYTHON33 MODPYTHON35 MODWSGI

WEBSRV_DESC=		Enable web server support
APMOD_DESC=		depend on Apache module

MODWSGI_DESC=		Add mod_wsgi to the list of package dependencies
MODPYTHON33_DESC=	Add mod_python33 to the list of package dependencies
MODPYTHON35_DESC=	Add mod_python35 to the list of package dependencies
MYSQL_DESC=		Bonsai-like repository query facilities

APACHE_USE=		APACHE_RUN=22+
LIGHTTPD_RUN_DEPENDS=	lighttpd:www/lighttpd
MODPYTHON33_RUN_DEPENDS=${APACHE_PKGNAMEPREFIX}mod_python33>=3.3:www/mod_python33
MODPYTHON35_RUN_DEPENDS=${APACHE_PKGNAMEPREFIX}mod_python35>=3.5:www/mod_python35
MODWSGI_RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}${PYTHON_PKGNAMEPREFIX}mod_wsgi4>=4.4.13:www/mod_wsgi4@${PY_FLAVOR}
SVN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subversion>=0:devel/py-subversion@${PY_FLAVOR}
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:databases/py-MySQLdb@${PY_FLAVOR}

.include <bsd.port.options.mk>

USES=		cpe python:2.7
NO_BUILD=	yes
USE_RC_SUBR=	viewvc
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		ECHO=${ECHO} EGREP=${EGREP} TOUCH=${TOUCH} \
		CHOWN=${CHOWN} RM=${RM:Q}

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:textproc/py-pygments@${PY_FLAVOR}

pre-everything::
.if ${PORT_OPTIONS:MAPMOD} && !${PORT_OPTIONS:MAPACHE}
IGNORE=	apache module needs Apache server, please re-run 'make config' then choose WEBSRV and APACHE
.endif

post-patch:
.for i in cvsgraph.conf mimetypes.conf viewvc.conf
	${MV} ${WRKSRC}/conf/${i}.dist ${WRKSRC}/conf/${i}.sample
	${REINPLACE_CMD} -e '/"${i}"/d' ${WRKSRC}/viewvc-install
.endfor
	${REINPLACE_CMD} -e 's/conf.dist/conf.sample/g' \
		${WRKSRC}/viewvc-install \
		${WRKSRC}/bin/standalone.py
# to much files, use own shebangfix
	${FIND} ${WRKSRC} -type f | ${GREP} -v -e 'png' -e 'images' \
		| ${XARGS} ${SED} -i '' \
		-e '1s|^\#![[:space:]]*/usr/bin/env python|\#!${PYTHON_CMD}|' \
		-e '1s|^\#![[:space:]]*/usr/bin/python|\#!${PYTHON_CMD}|'

do-install:
	@(cd ${WRKSRC} && ${PYTHON_CMD} viewvc-install --prefix=${PREFIX}/${PORTNAME} --destdir="${STAGEDIR}" --clean-mode=false)

.include <bsd.port.mk>
