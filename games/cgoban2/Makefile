# New ports collection makefile for:   cgoban2
# Date created:		30 October 2003
# Whom:			smazanek@steffen-mazanek.de
#
# $FreeBSD$
#

PORTNAME=	cgoban2
PORTVERSION=	2.6.4
CATEGORIES=	games
MASTER_SITES=	http://kgs.kiseido.com/
DISTNAME=	cgoban-unix-${PORTVERSION}

MAINTAINER=	smazanek@steffen-mazanek.de
COMMENT=	Internet Go Server client and game editor

WRKSRC=		${WRKDIR}/cgoban
INSTALLDIR=	${PREFIX}/share/java/cgoban2

USE_JAVA=	1.3+
NO_BUILD=	yes

PLIST_FILES=	bin/cgoban2 share/java/cgoban2/cgoban.jar
PLIST_DIRS=	share/java/cgoban2

post-patch:
	${SED} -e 's|_DIR=.|_DIR=${INSTALLDIR}| ; s|^java|javavm|'\
		< ${WRKSRC}/cgoban.sh.in > ${WRKSRC}/cgoban2

do-install:
	${MKDIR} ${INSTALLDIR}
	${INSTALL_DATA} ${WRKSRC}/cgoban.jar ${INSTALLDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cgoban2 ${PREFIX}/bin/cgoban2

.include <bsd.port.mk>
