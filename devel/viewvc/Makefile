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

WEBSRV_DESC=	Enable web server support
APMOD_DESC=	Enable Apache module OPTIONS
APMOD_DESC=	depend on optional Apache module

MODWSGI3_DESC=	Enable mod_wsgi3 support
MODPYTHON3_DESC=Enable mod_python3 support

NO_BUILD=	yes
USE_PYTHON=	2.5-2.7
SUB_FILES=	pkg-message
SUB_LIST=	INSTDIR="${PREFIX}/${INSTDIR}" \
		PYTHON_CMD=${PYTHON_CMD} \
		ECHO=${ECHO} EGREP=${EGREP} TOUCH=${TOUCH} \
		CHOWN=${CHOWN} RM=${RM}

INSTDIR?=	${PORTNAME}
PLIST_SUB=	INSTDIR=${INSTDIR}

.include <bsd.port.options.mk>

# standalone script is usefull even if a webserver was choosen.
USE_RC_SUBR=	viewvc

RUN_DEPENDS+=	${LOCALBASE}/bin/pygmentize:${PORTSDIR}/textproc/py-pygments

# viewvc supports CVS and SVN, controlled with the parameter
# cvs_roots (for CVS), svn_roots (for Subversion) in viewvc.conf
.if ${PORT_OPTIONS:MSVN}
RUN_DEPENDS+=	${PYTHON_LIBDIR}/site-packages/svn/__init__.py:${PORTSDIR}/devel/py-subversion
.endif

.if ${PORT_OPTIONS:MAPACHE}
USE_APACHE_RUN=	22+
.endif

.if ${PORT_OPTIONS:MLIGHTTPD}
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

.if ${PORT_OPTIONS:MMODPYTHON3}
RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_python>=3.3:${PORTSDIR}/www/mod_python3
.endif

.if ${PORT_OPTIONS:MMODWSGI3}
RUN_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_wsgi>=3.3:${PORTSDIR}/www/mod_wsgi3
.endif

# This feature is a clone of the Mozilla Project's Bonsai database.
# It catalogs every commit in the CVS or Subversion repository into a MYSQL database.
# In fact, the databases are 100% compatible.
.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=0:${PORTSDIR}/databases/py-MySQLdb
.endif

pre-everything::
.if ${PORT_OPTIONS:MAPMOD} && empty(PORT_OPTIONS:MAPACHE)
IGNORE=	apache module needs Apache server, please re-run 'make config' then choose WEBSRV and APACHE
. endif

do-install:
	@(cd ${WRKSRC} && ${PYTHON_CMD} viewvc-install --prefix=${PREFIX}/${INSTDIR} --destdir="" --clean-mode=false)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
