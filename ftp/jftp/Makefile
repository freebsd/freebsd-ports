# ex:ts=8
# Ports collection makefile for:	jftp
# Date created:			June 14, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	jftp
PORTVERSION=	1.38
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	j-ftp
DISTNAME=	j-ftp-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Java Network Browser

WRKSRC=		${WRKDIR}/j-ftp
USE_JAVA=	1.3+
NO_BUILD=	yes

JAVAVM=		${LOCALBASE}/bin/javavm

post-patch:
	@${SED} -e "s,%%DATADIR%%,${DATADIR},; \
		s,%%JAVAVM%%,${JAVAVM}," \
		${FILESDIR}/jftp > ${WRKSRC}/jftp

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/jftp ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/build/jars/jftp.jar ${DATADIR}

.include <bsd.port.mk>
