# Ports collection makefile for:	couchdb
# Date created:			17 Nov 2007
# Whom:                         Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	couchdb
PORTVERSION=	1.2.0
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	couchdb/releases/${PORTVERSION}
DISTNAME=	apache-couchdb-${PORTVERSION}

MAINTAINER=	till@php.net
COMMENT=	A document database server, accessible via a RESTful JSON API

LIB_DEPENDS=	icudata:${PORTSDIR}/devel/icu \
		js:${PORTSDIR}/lang/spidermonkey \
		curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/bin/help2man:${PORTSDIR}/misc/help2man \
		erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang

USERS=		couchdb
GROUPS=		couchdb

USE_RC_SUBR=	couchdb
SUB_FILES=	pkg-message
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-erlang=${LOCALBASE}/lib/erlang/usr/include \
		--localstatedir=/var \
		--disable-init \
		--with-js-include=${LOCALBASE}/include \
		--with-js-lib=${LOCALBASE}/lib
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAN1=	couchdb.1 couchjs.1

.include <bsd.port.options.mk>

# This stanza could be removed around version 1.7
pre-everything::
	@if [ -f ${PREFIX}/etc/couchdb/local.ini -a \
	    ! -f ${PREFIX}/etc/couchdb/local.ini.sample ] && \
	    ${PKG_INFO} -qX '${PKGBASE}-[01].[^2-6][0-9]*(\.[0-9a-z]*)*(,1)?'; \
	   then ${ECHO_MSG} Please see UPDATING note 20120702 to avoid loss of your local.ini ; \
		exit 2 ; \
	fi

pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you are upgrading CouchDB, please double-check that the datafile is compatible"
	@${ECHO_MSG} "and that you have BACKED UP YOUR DB directory before proceeding!"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Upgrading also might require you to rebuild your views entirely."
	@${ECHO_MSG} ""

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/install-data-am$$//' ${WRKSRC}/Makefile.in
.endif

post-configure:
	@${REINPLACE_CMD} -e '179s|install  -s|install|' ${WRKSRC}/src/couchdb/priv/Makefile
	@${REINPLACE_CMD} -e '480,482d' ${WRKSRC}/etc/couchdb/Makefile

pre-install:
	@${REINPLACE_CMD} -e '6s|database_dir = /var/lib/couchdb|database_dir = /var/db/couchdb|' ${WRKSRC}/etc/couchdb/default.ini
	@${REINPLACE_CMD} -e '7s|view_index_dir = /var/lib/couchdb|view_index_dir = /var/db/couchdb|' ${WRKSRC}/etc/couchdb/default.ini

post-install:
.ifndef PACKAGE_BUILDING
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CP} -p ${WRKSRC}/etc/couchdb/local.ini ${PREFIX}/etc/couchdb/local.ini.sample

	@if [ ! -f ${PREFIX}/etc/couchdb/local.ini ]; then \
		${CP} -p ${PREFIX}/etc/couchdb/local.ini.sample ${PREFIX}/etc/couchdb/local.ini; \
		${CHOWN} couchdb:couchdb ${PREFIX}/etc/couchdb/local.ini; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
