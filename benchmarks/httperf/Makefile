# New ports collection makefile for:	httperf
# Date created:		28 Jul 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	httperf
PORTVERSION=	0.6
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A tool for measuring webserver performance

USE_GMAKE=	yes
MAN1=		httperf.1

# there is no "install" target in the Makefile.
# chmod'ing httperf as it could be exploited by normal users to overload
# a webserver, instead of for its actual purpose.

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/httperf ${PREFIX}/bin
	${CHMOD} 750 ${PREFIX}/bin/httperf
	@${INSTALL_MAN} ${WRKSRC}/httperf.man ${PREFIX}/man/man1/httperf.1
	@${MKDIR} ${PREFIX}/share/doc/httperf
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/httperf
	@${INSTALL_MAN} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/doc/httperf
	@${INSTALL_MAN} ${WRKSRC}/NEWS ${PREFIX}/share/doc/httperf
	@${INSTALL_MAN} ${WRKSRC}/TODO ${PREFIX}/share/doc/httperf
	@${INSTALL_MAN} ${WRKSRC}/ChangeLog ${PREFIX}/share/doc/httperf

.include <bsd.port.mk>
