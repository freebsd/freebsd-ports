# New ports collection makefile for: bzflag
# Date created:		2000/08/12
# Whom:			makeport.pl
#
# $FreeBSD$
#

PORTNAME=	bzflag
PORTVERSION=	1.7d.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bzflag
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	nbm@FreeBSD.org

WRKSRC=		${WRKDIR}/bzflag

MAN6=	bzflag.6 bzfrelay.6 bzfls.6 bzfs.6

do-configure:
	@${CP} ${FILESDIR}/config-sys ${WRKSRC}/

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin/
	@${INSTALL_MAN}	${WRKSRC}/man/*.6 ${PREFIX}/man/man6/

.include <bsd.port.mk>
