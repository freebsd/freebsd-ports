# Created by: will
# $FreeBSD$

PORTNAME=	viewvc
PORTVERSION=	1.1.21
CATEGORIES=	devel python
MASTER_SITES=	http://www.viewvc.org/ \
		LOCAL/ohauer

MAINTAINER=	ohauer@FreeBSD.org
COMMENT=	Web-based Version Control Repository Browsing

LICENSE=	BSD

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=		WEBSRV APMOD SVN MYSQL
OPTIONS_DEFAULT=	WEBSRV APACHE SVN

OPTIONS_SINGLE=		WEBSRV APMOD
OPTIONS_SINGLE_WEBSRV=	APACHE LIGHTTPD
OPTIONS_SINGLE_APMOD=	MODPYTHON3 MODWSGI3

WEBSRV_DESC=		Enable web server support
APMOD_DESC=		depend on optional Apache module

MODWSGI3_DESC=		Enable mod_wsgi3 support
MODPYTHON3_DESC=	Enable mod_python3 support
MYSQL_DESC=		Bonsai-like repository query facilities

APACHE_USE=		APACHE_RUN=22+
LIGHTTPD_RUN_DEPENDS=	lighttpd:${PORTSDIR}/www/lighttpd
MODPYTHON3_RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_python>=3.3:${PORTSDIR}/www/mod_python3
MODWSGI3_RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_wsgi3>=3.3:${PORTSDIR}/www/mod_wsgi3
SVN_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}subversion>=0:${PORTSDIR}/devel/py-subversion
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:${PORTSDIR}/databases/py-MySQLdb

.include <bsd.port.options.mk>

NO_BUILD=	yes
USE_RC_SUBR=	viewvc
USE_PYTHON=	2
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		ECHO=${ECHO} EGREP=${EGREP} TOUCH=${TOUCH} \
		CHOWN=${CHOWN} RM=${RM}

RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pygments>=1.6:${PORTSDIR}/textproc/py-pygments

pre-everything::
.if ${PORT_OPTIONS:MAPMOD} && !${PORT_OPTIONS:MAPACHE}
IGNORE=	apache module needs Apache server, please re-run 'make config' then choose WEBSRV and APACHE
.endif

do-install:
	@(cd ${WRKSRC} && ${PYTHON_CMD} viewvc-install --prefix=${PREFIX}/${PORTNAME} --destdir="${STAGEDIR}" --clean-mode=false)

.include <bsd.port.mk>
