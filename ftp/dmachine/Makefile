# ex:ts=8
# Ports collection makefile for:	dmachine
# Date Created:			Dec 15, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dmachine
PORTVERSION=	0.19
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A non interactive, non graphical, batch download manager

USE_JAVA=	1.1+
WRKSRC=		${WRKDIR}/${DISTNAME}/src
ALL_TARGET=	dmachine

do-install:
	@${SED} 's|%%DATADIR%%|${DATADIR}|' ${FILESDIR}/dmachine > ${WRKSRC}/dmachine
	${INSTALL_SCRIPT} ${WRKSRC}/dmachine ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.class ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../dmachine.cnf ${DOCSDIR}
.endif

.include <bsd.port.mk>
