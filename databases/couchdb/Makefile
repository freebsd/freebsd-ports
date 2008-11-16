# Ports collection makefile for:	couchdb
# Date created:			17 Nov 2007
# Whom:                         Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	couchdb
PORTVERSION=	0.9.0a
CATEGORIES=	databases
MASTER_SITES=	http://people.apache.org/~nslater/build/latest/
DISTNAME=	apache-couchdb-0.9.0a-incubating

MAINTAINER=	jan@apache.org
COMMENT=	A document database server, accessible via a RESTful JSON API

LIB_DEPENDS=	icudata:${PORTSDIR}/devel/icu \
		js:${PORTSDIR}/lang/spidermonkey
BUILD_DEPENDS=	${LOCALBASE}/lib/erlang/usr/include/erl_driver.h:${PORTSDIR}/lang/erlang-lite
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-erlang=${LOCALBASE}/lib/erlang/usr/include \
		--localstatedir=/var \

MAN1=	couchdb.1 couchjs.1

PLIST_SUB=	COUCHVERSION=couch-${PORTVERSION}-incubating

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's/install-data-am$$//' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
