# New ports collection makefile for:	viewcvs
# Date created:				Sun 02 Jul 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	viewvc
PORTVERSION=	1.1.5
CATEGORIES=	devel python
MASTER_SITES=	http://viewvc.tigris.org/files/documents/3330/47458/ \
  LOCAL/pgollucci

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Web-based Version Control Repository Browsing

OPTIONS=\
		SUBVERSION 	"use svn binding" 						on \
		APACHE 		"use ${APACHE_PORT} as webserver"		on \
		LIGHTTPD 	"use Lighttp as webserver" 				off \
		MODPYTHON3 	"enable mod_python3 support" 			off \
		MYSQL 		"enable experimental MYSQL support" 	off

NO_BUILD=	yes
USE_PYTHON=	yes
SUB_FILES=	pkg-message
SUB_LIST=	INSTDIR="${PREFIX}/${INSTDIR}" \
			PYTHON_CMD=${PYTHON_CMD}

INSTDIR?=	${PORTNAME}
PLIST_SUB=	INSTDIR=${INSTDIR}

.include <bsd.port.options.mk>

.if !defined(WITH_APACHE) && !defined(WITH_LIGHTTPD)
USE_RC_SUBR=	viewvc
.endif

RUN_DEPENDS+=	${LOCALBASE}/bin/pygmentize:${PORTSDIR}/textproc/py-pygments

# viewvc can support CVS or SVN, controlled with the parameter
# cvs_roots (for CVS), svn_roots (for Subversion) in viewvc.conf
.if defined (WITH_SUBVERSION)
RUN_DEPENDS+=	${PYTHON_LIBDIR}/site-packages/svn/__init__.py:${PORTSDIR}/devel/py-subversion
.endif

.if defined (WITH_APACHE)
USE_APACHE=	2.0+
.endif

.if defined(WITH_LIGHTTPD)
RUN_DEPENDS+=	lighttpd:${PORTSDIR}/www/lighttpd
.endif

.if defined(WITH_MODPYTHON3)
RUN_DEPENDS+=	${LOCALBASE}/${APACHEMODDIR}/mod_python.so:${PORTSDIR}/www/mod_python3
.endif

# This feature is a clone of the Mozilla Project's Bonsai database.
# It catalogs every commit in the CVS or Subversion repository into a SQL database.
# In fact, the databases are 100% compatible.
.if defined(WITH_MYSQL)
RUN_DEPENDS+=	${PYTHON_LIBDIR}/site-packages/_mysql.so:${PORTSDIR}/databases/py-MySQLdb
.endif

pre-everything::
.if defined(WITH_APACHE) && defined(WITH_LIGHTTPD)
	@${ECHO_CMD} "It doesn't make sense to depend on Apache *and* LighHTTPD choose only one."
	@${FALSE}
.endif

.if defined(WITH_MODPYTHON3) && !defined(WITH_APACHE) && defined(WITH_LIGHTTPD)
	@${ECHO_CMD} "mod_python3 needs Apache, please select Apache and deselect LighHTTPD"
	@${FALSE}
.elif defined(WITH_MODPYTHON3) && !defined(WITH_APACHE)
	@${ECHO_CMD} "mod_python3 needs Apache, please select Apache"
	@${FALSE}
.endif

do-install:
	@(cd ${WRKSRC} && ${PYTHON_CMD} viewvc-install --prefix=${PREFIX}/${INSTDIR} --destdir="" --clean-mode=false)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
