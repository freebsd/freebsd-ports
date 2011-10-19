# New ports collection makefile for:	ydict
# Date created:		2011-02-08
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	ydict
PORTVERSION=	1.2.5
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
#DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	gslin@gslin.org
COMMENT=	Command line tool of Yahoo! Dict

LICENSE=	GPLv3
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/ydict
USE_PYTHON_RUN=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ydict ${PREFIX}/bin/

.include <bsd.port.mk>
