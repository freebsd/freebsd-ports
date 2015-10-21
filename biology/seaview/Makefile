# Created by: frankch@waru.life.nthu.edu.tw
# $FreeBSD$

PORTNAME=	seaview
PORTVERSION=	4.5.4.8
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://pbil.univ-lyon1.fr/pub/mol_phylogeny/seaview/archive/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Multiple DNA/protein sequence alignment editor

LICENSE=	GPLv3

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk \
		libpng.so:${PORTSDIR}/graphics/png

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake
USE_XORG=	xext xft xinerama
MAKE_ENV=	HELPFILE='-DDEFAULT_HELPFILE=\"${DATADIR}/seaview.html\"' \
		PHYMLNAME='-DPHYMLNAME=\"phyml\"' \
		IFLTK='-I${LOCALBASE}/include' \
		LFLTK='-L${LOCALBASE}/lib' \
		USE_XFT='-DUSE_XFT' \
		OPT="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/seaview man/man1/seaview.1.gz %%DATADIR%%/seaview.html \
		share/pixmaps/seaview.xpm

DESKTOP_ENTRIES="SeaView" "" "${PREFIX}/share/pixmaps/seaview.xpm" "seaview" \
		"Biology;Science;" true

post-patch:
	${REINPLACE_CMD} -e \
		's|^\(CC\) |#\1 | ; s|-ldl || ; \
		s|^\(CXX\) |#\1 |' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} seaview \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} seaview.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} seaview.html \
		${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} seaview.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
