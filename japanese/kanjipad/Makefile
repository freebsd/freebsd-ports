# Created by: Christophe Juniet <cjuniet@entreview.com>
# $FreeBSD$

PORTNAME=	kanjipad
PORTVERSION=	2.0.0
PORTREVISION=	8
CATEGORIES=	japanese x11
MASTER_SITES=	http://fishsoup.net/software/kanjipad/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Handwriting recognition

USES=		gmake gnome perl5 pkgconfig
USE_GNOME=	gtk20
MAKE_ARGS=	OPTIMIZE="${CFLAGS}" PREFIX="${PREFIX}" \
		GTKINC="`pkg-config --cflags gtk+-2.0`"
LDFLAGS+=	-lm

PORTDOCS=	README
PLIST_FILES=	bin/kanjipad bin/kpengine %%DATADIR%%/jdata.dat

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kanjipad ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/kpengine ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jdata.dat ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
