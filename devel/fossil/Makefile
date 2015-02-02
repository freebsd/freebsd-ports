# $FreeBSD$

PORTNAME=	fossil
PORTVERSION=	1.30
DISTVERSION=	20150119112900
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	devel www
MASTER_SITES=	http://www.fossil-scm.org/download/
DISTVERSIONPREFIX=	src-

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	DSCM with built-in wiki, http interface and server, tickets database

LICENSE=	BSD2CLAUSE

PLIST_FILES=	bin/fossil

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

USE_OPENSSL=	yes
USE_RC_SUBR=	fossil

CONFIGURE_ARGS=	--disable-lineedit

OPTIONS_DEFINE=	JSON FUSE STATIC
OPTIONS_DEFAULT=	JSON
JSON_DESC=	JSON API support
FUSE_DESC=	Enable fossil fusefs command

JSON_CONFIGURE_ON=	--json
STATIC_CONFIGURE_ON=	--static
FUSE_CONFIGURE_OFF=	--disable-fusefs
FUSE_LIB_DEPENDS=	libfuse.so:${PORTSDIR}/sysutils/fusefs-libs
FUSE_CFLAGS=		-I${LOCALBASE}/include -L${LOCALBASE}/lib

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fossil

.include <bsd.port.mk>
