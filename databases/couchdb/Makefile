# Created by: Ditesh Shashikant Gathani <ditesh@gathani.org>
# $FreeBSD$

PORTNAME=	couchdb
PORTVERSION=	1.6.1
PORTREVISION=	9
PORTEPOCH=	2
CATEGORIES=	databases
MASTER_SITES=	APACHE/couchdb/source/${PORTVERSION}
DISTNAME=	apache-couchdb-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Document database server, accessible via a RESTful JSON API

LICENSE=	APACHE20

LIB_DEPENDS=	libicudata.so:devel/icu \
		libmozjs185.so:lang/spidermonkey185 \
		libcurl.so:ftp/curl
BUILD_DEPENDS=	${LOCALBASE}/bin/help2man:misc/help2man \
		erlang>=15.b.01,2:lang/erlang
RUN_DEPENDS=	erlang>=15.b.01,2:lang/erlang

USERS=		couchdb
GROUPS=		couchdb

USE_RC_SUBR=	couchdb
SUB_FILES=	pkg-message
PLIST_SUB=	VERSION=${PORTVERSION}
USES=		cpe gmake libtool
CPE_VENDOR=	apache
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-erlang=${LOCALBASE}/lib/erlang/usr/include \
		--localstatedir=/var \
		--disable-init \
		--with-js-include=${LOCALBASE}/include/js \
		--with-js-lib=${LOCALBASE}/lib

# Override default value of ${STRIP} because the underlying Makefile
# erroneously tries to install a shell script with ${STRIP}, causing
# an install error.
STRIP=	#empty

INFO=		CouchDB

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
	@${ECHO_MSG} "If you are upgrading CouchDB, please double-check that the datafile is"
	@${ECHO_MSG} "compatible and that you have BACKED UP YOUR DB directory before proceeding!"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Upgrading also might require you to rebuild your views entirely."
	@${ECHO_MSG} ""

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
	@${FIND} ${WRKSRC} -name Makefile|${XARGS} ${REINPLACE_CMD} -e 's|include -I/usr/local/include/js|include/js -I/usr/local/include|'

post-install:
	@${CP} -p ${WRKSRC}/etc/couchdb/local.ini ${STAGEDIR}${PREFIX}/etc/couchdb/local.ini.sample

.include <bsd.port.mk>
