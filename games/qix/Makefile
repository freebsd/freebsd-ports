# New ports collection makefile for:    qix
# Date created:         6 June 2000
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	qix
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jmz

MAINTAINER=	jmz@FreeBSD.org

USE_X_PREFIX=	yes
MAN1=		qix.1

FONTSDIR=	lib/X11/fonts/local
PLIST_SUB=	FONTSDIR=${FONTSDIR}

do-configure:
	@${CP} ${WRKSRC}/Makefile ${WRKSRC}/Makefile~
	@${SED} -e s:/usr/local:${PREFIX}: -e s:/usr/X11R6:${PREFIX}: \
	  < ${WRKSRC}/Makefile~ > ${WRKSRC}/Makefile

.include <bsd.port.mk>
