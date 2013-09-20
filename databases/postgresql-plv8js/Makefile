# Created by: vanilla@
# $FreeBSD$

PORTNAME=	plv8js
PORTVERSION=	1.4.1
CATEGORIES=	databases
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	postgresql-
DISTNAME=	plv8-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	PL/v8js procedural language for PostgreSQL database

LIB_DEPENDS+=	libv8.so:${PORTSDIR}/lang/v8

USES=		gmake perl5
USE_PERL5=	build
USE_ZIP=	yes
USE_PGSQL=	yes
WANT_PGSQL_VER=	91+
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKSRC}/pkg-message

NO_STAGE=	yes
post-install:
	@${ECHO_MSG} ''
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ''

.include <bsd.port.mk>
