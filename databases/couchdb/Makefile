# Ports collection makefile for:	couchdb
# Date created:			17 Nov 2007
# Whom:                         Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	couchdb
PORTVERSION=	1.0.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	couchdb/${PORTVERSION}
DISTNAME=	apache-couchdb-${PORTVERSION}

MAINTAINER=	till@php.net
COMMENT=	A document database server, accessible via a RESTful JSON API

LIB_DEPENDS=	icudata:${PORTSDIR}/devel/icu \
		js:${PORTSDIR}/lang/spidermonkey \
		curl.6:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/lib/erlang/usr/include/erl_driver.h:${PORTSDIR}/lang/erlang-lite
RUN_DEPENDS=	${BUILD_DEPENDS}

COUCH_VARDIR?=	/var
COUCH_DBDIR?=	${COUCH_VARDIR}/db/couchdb
COUCH_LOGDIR?=	${COUCH_VARDIR}/log/couchdb
COUCH_LIBDIR?=	${COUCH_VARDIR}/lib/couchdb
COUCH_USER?=	couchdb

USE_RC_SUBR=	couchdb
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-erlang=${LOCALBASE}/lib/erlang/usr/include \
		--localstatedir=/var \
		--disable-init \
		--with-js-include=${LOCALBASE}/include \
		--with-js-lib=${LOCALBASE}/lib
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAN1=	couchdb.1 couchjs.1

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you are upgrading CouchDB, please double-check that the datafile is compatible."
	@${ECHO_MSG} "Upgrading also might require you to rebuild your views entirely."
	@${ECHO_MSG} ""

post-patch:
	${REINPLACE_CMD} -e '169s|@INSTALL_PROGRAM@|@INSTALL_SCRIPT@|' ${WRKSRC}/src/couchdb/priv/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/install-data-am$$//' ${WRKSRC}/Makefile.in
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PORTNAME} PRE-INSTALL

post-install:
	@${CAT} ${PKGMESSAGE}
	${MKDIR} ${COUCH_DBDIR}
	${CHOWN} ${COUCH_USER} ${COUCH_DBDIR}
	${CHOWN} ${COUCH_USER} ${COUCH_LOGDIR}
	${CHOWN} ${COUCH_USER} ${COUCH_LIBDIR}

.include <bsd.port.mk>
