# New ports collection makefile for:	makeself
# Date created:		22 Oct 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	makeself
PORTVERSION=	1.5.3
CATEGORIES=	archivers
MASTER_SITES=	http://www.lokigames.com/~megastep/makeself/
DISTNAME=	makeself
EXTRACT_SUFX=	.gz.sh

MAINTAINER=	will@FreeBSD.org

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_BUILD=	yes
WRKSRC=                ${WRKDIR}/${PKGNAME}

# The DISPLAY thing is to prevent the script from trying to launch a xterm
# just to extract the source.
pre-patch:
	(cd ${WRKDIR} && ${SETENV} DISPLAY="" ${SH} ${DISTNAME}${EXTRACT_SUFX})

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/makeself.sh ${PREFIX}/bin/makeself

.include <bsd.port.mk>
