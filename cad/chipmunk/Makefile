# New ports collection makefile for:	chipmunk
# Version required:	5.10
# Date created:		29 July 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $Id: Makefile,v 1.2 1995/10/04 15:26:17 asami Exp $
#

DISTNAME=	chipmunk-5.10
CATEGORIES+=	cad
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/chipmunk/
DISTFILES=	psys-1.10.tar.Z log-5.10.tar.Z netcmpbeta.tar.Z \
		mosisbeta.tar.Z wolbeta.tar.Z wolcompbeta.tar.Z \
		untilbeta.tar.Z viewbeta.tar.Z Makefile
EXTRACT_ONLY=	psys-1.10.tar.Z log-5.10.tar.Z netcmpbeta.tar.Z \
		mosisbeta.tar.Z wolbeta.tar.Z wolcompbeta.tar.Z \
		untilbeta.tar.Z viewbeta.tar.Z

DIST_SUBDIR=	chipmunk
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes

post-extract:
	cp ${DISTDIR}/Makefile ${WRKSRC}/Makefile

.include <bsd.port.mk>
