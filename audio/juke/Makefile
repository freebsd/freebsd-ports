# New ports collection makefile for:    juke
# Version required:     0.5
# Date created:         2 May 1999
# Whom:                 oyvindmo@initio.no
#
# $FreeBSD$
#

DISTNAME=		juke-0.5
CATEGORIES=		audio
MASTER_SITES=		http://www.nocrew.org/software/juke/archive/

MAINTAINER=		oyvindmo@initio.no

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/juke.conf ${PREFIX}/etc/juke.conf.sample
	@${SED} 's,PREFIX,${PREFIX},' ${PKGDIR}/MESSAGE > ${WRKSRC}/MESSAGE
	@${CAT} ${WRKSRC}/MESSAGE

.include <bsd.port.mk>
