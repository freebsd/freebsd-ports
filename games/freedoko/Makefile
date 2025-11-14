PORTNAME=	freedoko
DISTVERSION=	0.8.1
CATEGORIES=	games
MASTER_SITES=	SF/free-doko/source
DISTNAME=	FreeDoko_${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Play the card game Doppelkopf
WWW=		https://free-doko.sourceforge.net/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS+=	a2x:textproc/asciidoc \
		w3m:www/w3m \
		rsync:net/rsync \
		dos2unix:converters/unix2dos
LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		gettext-runtime gettext-tools gmake gnome localbase \
		pkgconfig zip:infozip openal:al,alut tex
USE_GNOME=	gdkpixbuf gtkmm30
USE_TEX=	pdftex:build dvipsk:build

ALL_TARGET=	compile documentation
LDFLAGS_i386=	-Wl,-znotext
WRKSRC=		${WRKDIR}/${DISTNAME:R}

post-install:
	${RM} ${STAGEDIR}${DATADIR}/doc
	${RLN} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DATADIR}/doc

.include <bsd.port.mk>
