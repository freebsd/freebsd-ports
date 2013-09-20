# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	leafpak
PORTVERSION=	1.1.1
CATEGORIES=	graphics
MASTER_SITES=	http://hoshina.denpa.org/

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Graphic file cutter for LEAF/AQUAPLUS PAK format archives

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/leafpak ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/leafpak2 ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ja/leafpak
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/leafpak
.endif

.include <bsd.port.mk>
