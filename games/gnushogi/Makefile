# New ports collection makefile for:   gnushogi
# Version required:    1.2p03
# Date created:        9 October 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1997/01/03 11:33:00 obrien Exp $
#

DISTNAME=	gnushogi-1.2p03
PKGNAME=	gnushogi-1.2.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	nacai@iname.com

DOCFILES= BOOKFILES CHANGES CONTRIB COPYING GENERAL INSTALL PORTING \
	README-FIRST listserv.ref shogi.rules tutorial1.gam tutorial2.gam
MAN6=		gnushogi.6

post-configure:
	echo "DISTDIR=${WRKDIR}" >> ${WRKSRC}/src/${MAKEFILE}
	echo "prefix=${PREFIX}" >> ${WRKSRC}/src/${MAKEFILE}

do-build:
	(cd ${WRKSRC}/src; \
	make gnushogir; \
	make gnushogi.bbk; \
	make gnushogi; \
	make gnushogix )

do-install:
	@${MKDIR} ${PREFIX}/share/gnushogi
	${INSTALL_PROGRAM} ${WRKSRC}/src/gnushogi ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/gnushogir ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/gnushogix ${PREFIX}/libexec
	${INSTALL_DATA} ${WRKSRC}/src/gnushogi.bbk ${PREFIX}/share/gnushogi
	${INSTALL_MAN} ${WRKSRC}/doc/gnushogi.1 ${PREFIX}/man/man6/gnushogi.6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gnushogi
.for doc in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${doc} ${PREFIX}/share/doc/gnushogi
.endfor
.endif

.include <bsd.port.mk>
