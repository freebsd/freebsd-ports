# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	couchdb
DISTVERSION=	1.7.2
PORTREVISION=	4
PORTEPOCH=	2
CATEGORIES=	databases
MASTER_SITES=	APACHE/couchdb/source/${DISTVERSION}
DISTNAME=	apache-couchdb-${DISTVERSION}

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Document database server, accessible via a RESTful JSON API

LICENSE=	APACHE20 BSD3CLAUSE ISCL WTFPL OFL11
LICENSE_COMB=	multi

LIB_DEPENDS=	libicudata.so:devel/icu \
		libmozjs185.so:lang/spidermonkey185 \
		libcurl.so:ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/bin/help2man:misc/help2man \
		erlang-runtime19>=19.3:lang/erlang-runtime19
RUN_DEPENDS=	erlang-runtime19>=19.3:lang/erlang-runtime19

USES=		cpe gmake libtool
USE_RC_SUBR=	couchdb
SUB_FILES=	pkg-message
PLIST_SUB=	VERSION=${DISTVERSION}
CPE_VENDOR=	apache
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-erlang=${LOCALBASE}/lib/erlang19/usr/include \
		--localstatedir=/var \
		--disable-init \
		--with-js-include=${LOCALBASE}/include/js \
		--with-js-lib=${LOCALBASE}/lib
CONFIGURE_ENV+=	ERL=${LOCALBASE}/lib/erlang19/bin/erl \
		ERLC=${LOCALBASE}/lib/erlang19/bin/erlc

USERS=		couchdb
GROUPS=		couchdb

# Override default value of ${STRIP} because the underlying Makefile
# erroneously tries to install a shell script with ${STRIP}, causing
# an install error.
STRIP=	#empty

INFO=		CouchDB

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
# DB files are stored by default in /var/db/couchdb
# Ports framework expects info pages to have an info extension
	@${REINPLACE_CMD} '/localstatelibdir=/s|/lib/|/db/|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|\(info_file_inst = CouchDB\)$$|\1.info|' \
		${WRKSRC}/share/doc/build/Makefile.in

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e 's/install-data-am$$//' ${WRKSRC}/Makefile.in

post-configure:
# Cater for parallel Spidermonkey v1.7 and v1.8.5 installs by ensuring that
# jsapi.h gets pulled from /usr/local/include/js/ instead of /usr/local/include
	@${FIND} ${WRKSRC} -name Makefile|${XARGS} ${REINPLACE_CMD} \
		-e 's|include -I/usr/local/include/js|include/js -I/usr/local/include|'
post-install:
	@${MV} ${STAGEDIR}${PREFIX}/lib/couchdb/bin/couchjs ${STAGEDIR}${PREFIX}/bin/couchjs
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/couchdb/bin
	@${MV} ${WRKSRC}/etc/couchdb/local.ini ${STAGEDIR}${PREFIX}/etc/couchdb/local.ini.sample

.include <bsd.port.mk>
