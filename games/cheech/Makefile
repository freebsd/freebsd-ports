# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	cheech
PORTVERSION=	0.8
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplayer Chinese Checkers game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnet-2.0.so:net/gnet2

OPTIONS_DEFINE=	DOCS

USES=		gmake pkgconfig tar:tgz
USE_GNOME=	gtkmm24
USE_AUTOTOOLS=	automake:env
GNU_CONFIGURE=	yes

DESKTOP_ENTRIES="cheech" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"cheech" \
		"Game;BoardGame;" \
		"false"

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${prefix}/doc|$$(datadir)/doc| ; \
		 /^cheechdoc_DATA/s|COPYING||' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		'/^AM_CXXFLAGS/s|[[:blank:]]-g||' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|\([[:blank:]]\)usleep|\1Glib::usleep|' ${WRKSRC}/src/utility.cc
	@${REINPLACE_CMD} -e \
		's|connect(SigC::slot|connect(sigc::mem_fun|g ; \
		 s|#include <sigc++\/compatibility\.h>||g' ${WRKSRC}/src/*.cc

pre-configure:
	@${LN} -sf ${AUTOMAKE_DIR}/install-sh ${WRKSRC}

.include <bsd.port.mk>
