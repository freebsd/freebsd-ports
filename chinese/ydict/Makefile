# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	ydict
PORTVERSION=	1.2.6
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	gslin@gslin.org
COMMENT=	Command line tool of Yahoo! Dict

LICENSE=	GPLv3

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/ydict
USE_PYTHON_RUN=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ydict ${STAGEDIR}/${PREFIX}/bin/

.include <bsd.port.mk>
