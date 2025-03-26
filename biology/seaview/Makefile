PORTNAME=	seaview
DISTVERSION=	5.1
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://pbil.univ-lyon1.fr/pub/mol_phylogeny/seaview/archive/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Multiple DNA/protein sequence alignment editor
WWW=		https://doua.prabi.fr/software/seaview

LICENSE=	GPLv3

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png

USES=		gmake jpeg xorg
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

MAKE_ENV=	HELPFILE='-DDEFAULT_HELPFILE=\"${DATADIR}/seaview.html\"' \
		IFLTK='-I${LOCALBASE}/include' \
		LFLTK='-L${LOCALBASE}/lib' \
		OPT="${CFLAGS}" \
		PHYMLNAME='-DPHYMLNAME=\"phyml\"' \
		USE_XFT='-DUSE_XFT'
ALL_TARGET=	${PORTNAME}

DESKTOP_ENTRIES=	"SeaView" \
			"" \
			"${PREFIX}/share/pixmaps/seaview.xpm" \
			"seaview" \
			"Biology;Science;" \
			true
PORTSCOUT=	skipv:4.6.1.3

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e \
		's|^\(CC\) |#\1 | ; s|-ldl || ; \
		s|^\(CXX\) |#\1 |' ${WRKSRC}/Makefile
	${ECHO_CMD} 'boolean javarun;' >> ${WRKSRC}/csrc/phylip.c

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} seaview \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} seaview.1 \
		${STAGEDIR}${PREFIX}/share/man/man1)
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} seaview.html \
		${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} seaview.xpm \
		${STAGEDIR}${PREFIX}/share/pixmaps)

.include <bsd.port.mk>
