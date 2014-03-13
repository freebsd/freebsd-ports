# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	leafpak
PORTVERSION=	1.1.1
CATEGORIES=	graphics
MASTER_SITES=	http://hoshina.denpa.org/

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Graphic file cutter for LEAF/AQUAPLUS PAK format archives

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/leafpak ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/leafpak2 ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ja/leafpak
	${INSTALL_DATA} ${WRKSRC}/README \
		${STAGEDIR}${PREFIX}/share/doc/ja/leafpak

.include <bsd.port.mk>
