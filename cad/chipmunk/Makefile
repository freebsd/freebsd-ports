# New ports collection makefile for:	chipmunk
# Version required:	5.10
# Date created:		29 July 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $Id: Makefile,v 1.1.1.1 1995/08/25 10:04:31 asami Exp $
#

DISTNAME=	chipmunk-5.10
CATEGORIES+=	cad
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/chipmunk/ \
		ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/chipmunk/
DISTFILES=	psys-1.10.tar.Z log-5.10.tar.Z netcmpbeta.tar.Z \
		mosisbeta.tar.Z wolbeta.tar.Z wolcompbeta.tar.Z \
		untilbeta.tar.Z viewbeta.tar.Z Makefile
EXTRACT_ONLY=	psys-1.10.tar.Z log-5.10.tar.Z netcmpbeta.tar.Z \
		mosisbeta.tar.Z wolbeta.tar.Z wolcompbeta.tar.Z \
		untilbeta.tar.Z viewbeta.tar.Z

USE_GMAKE=	yes
NO_WRKSUBDIR=	yes
DISTDIR=	${PORTSDIR}/distfiles/chipmunk
.if defined(MASTER_SITE_OVERRIDE)
MASTER_SITES:=	${MASTER_SITE_OVERRIDE}/chipmunk/
.undef MASTER_SITE_OVERRIDE
.endif


post-extract:
	cp ${DISTDIR}/Makefile ${WRKSRC}/Makefile

.include <bsd.port.mk>
