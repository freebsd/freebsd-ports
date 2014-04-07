# $FreeBSD$

PORTNAME=	fossil
PORTVERSION=	1.28
DISTVERSION=	20140127173344
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

USE_RC_SUBR=	fossil

OPTIONS_DEFINE=	JSON STATIC
JSON_DESC=	JSON API support

JSON_CONFIGURE_ON=	--json
STATIC_CONFIGURE_ON=	--static

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fossil

.include <bsd.port.mk>
