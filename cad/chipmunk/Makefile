# New ports collection makefile for:	chipmunk
# Date created:		29 July 1995
# Whom:			janek@gaja.ipan.lublin.pl
#
# $FreeBSD$
#

PORTNAME=	chipmunk
PORTVERSION=	5.51
CATEGORIES=	cad
MASTER_SITES=	http://www.cs.berkeley.edu/~lazzaro/chipmunk/pickup/sources/
DISTFILES=	psys-1.51.tar.gz log-5.51.tar.gz netcmpbeta.tar.gz \
		mosisbeta.tar.gz wolbeta.tar.gz wolcompbeta.tar.gz \
		untilbeta.tar.gz util1.1.tar.gz viewbeta.tar.gz \
		Makefile

MAINTAINER=	ports@FreeBSD.org

EXTRACT_ONLY=	psys-1.51.tar.gz log-5.51.tar.gz netcmpbeta.tar.gz \
		mosisbeta.tar.gz wolbeta.tar.gz wolcompbeta.tar.gz \
		untilbeta.tar.gz util1.1.tar.gz viewbeta.tar.gz

USE_XLIB=	yes
DIST_SUBDIR=	chipmunk
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/Makefile ${WRKSRC}/Makefile

post-patch:
	@find ${WRKSRC} -name Makefile -exec \
	  ${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" \{} \;
	@find ${WRKSRC} -name Makefile -exec \
	  ${PERL} -pi -e "s|%%X11BASE%%|${X11BASE}|g" \{} \;

.include <bsd.port.mk>
