# Ports collection makefile for:	couchdb
# Date created:			17 Nov 2007
# Whom:                         Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	couchdb
PORTVERSION=	0.7.0
CATEGORIES=	databases
MASTER_SITES=	http://couchdb.googlecode.com/files/

MAINTAINER=	ditesh@gathani.org
COMMENT=	A document database server, accessible via a RESTful JSON API

LIB_DEPENDS=	icudata:${PORTSDIR}/devel/icu
BUILD_DEPENDS=	${LOCALBASE}/lib/erlang/usr/include/erl_driver.h:${PORTSDIR}/lang/erlang
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-erlang=${LOCALBASE}/lib/erlang/usr/include \
		--localstatedir=/var \

post-patch:
	@${REINPLACE_CMD} -e "s|),Linux|),FreeBSD|g" ${WRKSRC}/src/js/config.mk

MAN1=	couchdb.1 couchjs.1

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		does not compile
.endif

.include <bsd.port.post.mk>
