# ex:ts=8
# Ports collection makefile for:	jtans
# Date created:			Apr 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jtans
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_appli-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A (not so) ancient puzzle

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
USE_JAVA=	1.3+
NO_BUILD=	yes

post-patch:
	@${SED} 's,%%DATADIR%%,${DATADIR},' ${FILESDIR}/jtans > ${WRKSRC}/jtans

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jtans ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jtans_appli-1.0.jar ${DATADIR}

.include <bsd.port.mk>
