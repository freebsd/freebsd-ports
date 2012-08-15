# New ports collection makefile for:	fossil
# Date created:		2010-06-15
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fossil
PORTVERSION=	20120808112557
PORTEPOCH=	1
CATEGORIES=	devel www
MASTER_SITES=	http://www.fossil-scm.org/download/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	DSCM with built-in wiki, http interface and server, tickets database

LICENSE=	BSD

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/fossil

HAS_CONFIGURE=	yes

USE_GMAKE=	yes

OPTIONS_DEFINE=	JSON
JSON_DESC=	JSON API support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJSON}
CONFIGURE_ARGS+=	--json
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/fossil ${PREFIX}/bin/fossil

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
