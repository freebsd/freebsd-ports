# New ports collection makefile for:    StarLogo
# Date created:		14th November 1999
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	starlogo
PORTVERSION=	2.0.2
CATEGORIES=	lang java
MASTER_SITES=	http://education.mit.edu/starlogo/download/
DISTNAME=	${PORTNAME}-2.0

MAINTAINER=	java@freebsd.org

USE_JAVA=       1.2+

USE_ZIP=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/java/starlogo
	@${INSTALL_SCRIPT} ${FILESDIR}/starlogo ${PREFIX}/bin/starlogo
	@${REINPLACE_CMD} -e \
		"s|%%PREFIX%%|${PREFIX}|g ; s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${PREFIX}/bin/starlogo
	@${RM} ${PREFIX}/bin/starlogo.bak
	@(cd ${WRKSRC} && ${TAR} -c -f - .) \
		| (cd ${PREFIX}/share/java/starlogo && ${TAR} --unlink -x -f -)

.include <bsd.port.mk>
