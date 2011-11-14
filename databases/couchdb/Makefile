# Ports collection makefile for:	couchdb
# Date created:			17 Nov 2007
# Whom:                         Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	couchdb
PORTVERSION=	1.1.0
PORTREVISION=	2
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
BUILD_DEPENDS=	${LOCALBASE}/bin/help2man:${PORTSDIR}/misc/help2man

USERS=		couchdb
GROUPS=		couchdb

USE_RC_SUBR=	couchdb
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-erlang=${LOCALBASE}/lib/erlang/usr/include \
		--localstatedir=/var \
		--disable-init \
		--with-js-include=${LOCALBASE}/include \
		--with-js-lib=${LOCALBASE}/lib
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS=	ERLANG	"Use lang/erlang instead of lang/erlang-lite"	off

MAN1=	couchdb.1 couchjs.1

.include <bsd.port.options.mk>

.if defined(WITH_ERLANG)
ERLANG_PORT=	${PORTSDIR}/lang/erlang
.else
ERLANG_PORT=	${PORTSDIR}/lang/erlang-lite
.endif

BUILD_DEPENDS+=	erlc:${ERLANG_PORT}
RUN_DEPENDS+=	erl:${ERLANG_PORT}

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

post-install:
.ifndef PACKAGE_BUILDING
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${CAT} ${PKGMESSAGE}

post-deinstall:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDEINSTALL} ${PKGNAME} POST-DEINSTALL

.include <bsd.port.mk>
