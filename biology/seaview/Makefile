PORTNAME=	seaview
DISTVERSION=	5.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	https://doua.prabi.fr/software/seaview_data/
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Multiple DNA/protein sequence alignment editor
WWW=		https://doua.prabi.fr/software/seaview

LICENSE=	GPLv3

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png

USES=		gmake jpeg localbase xorg
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

MAKE_ENV=	HELPFILE='-DDEFAULT_HELPFILE=\"${DATADIR}/seaview.html\"' \
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

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/seaview      ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN}     ${WRKSRC}/seaview.1    ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA}    ${WRKSRC}/seaview.html ${STAGEDIR}${DATADIR}
	${INSTALL_DATA}    ${WRKSRC}/seaview.xpm  ${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
