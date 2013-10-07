# Created by: Christophe Juniet <cjuniet@entreview.com>
# $FreeBSD$

PORTNAME=	kanjipad
PORTVERSION=	2.0.0
PORTREVISION=	7
CATEGORIES=	japanese x11
MASTER_SITES=	http://fishsoup.net/software/kanjipad/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Handwriting recognition

USES=		perl5 gmake pkgconfig
USE_GNOME=	gtk20
MAKE_ARGS=	OPTIMIZE="${CFLAGS}" PREFIX="${PREFIX}" \
		GTKINC="`pkg-config --cflags gtk+-2.0`"
LDFLAGS+=	-lm

PORTDOCS=	README
PLIST_FILES=	bin/kanjipad bin/kpengine %%DATADIR%%/jdata.dat
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kanjipad ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/kpengine ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/jdata.dat ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
