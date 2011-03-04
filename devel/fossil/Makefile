# New ports collection makefile for:	fossil
# Date created:		2010-06-15
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fossil
PORTVERSION=	20110301190432
PORTEPOCH=	1
CATEGORIES=	devel www
MASTER_SITES=	http://www.fossil-scm.org/download/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	DSCM with built-in wiki, http interface and server, tickets database

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/fossil

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT-BSD2.txt

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fossil ${PREFIX}/bin/fossil

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
