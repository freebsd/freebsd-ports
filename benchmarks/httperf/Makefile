# New ports collection makefile for:	httperf
# Version required:	0.6
# Date created:		28 Jul 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	httperf-0.6
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.hpl.hp.com/pub/httperf/

MAINTAINER=	will@FreeBSD.org

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_GMAKE=	yes

# there is no "install" target in the Makefile.
# also, installing relevant help files, as there is no manpage yet.
# chmod'ing httperf as it could be exploited by normal users to overload
# a webserver, instead of for its actual purpose.

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/httperf ${PREFIX}/bin
	${CHMOD} 750 ${PREFIX}/bin/httperf
	@${MKDIR} ${PREFIX}/share/httperf
	@${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/httperf
	@${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${PREFIX}/share/httperf
	@${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/httperf
	@${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/httperf
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/share/httperf

.include <bsd.port.mk>
