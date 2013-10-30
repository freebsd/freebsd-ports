# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	cheech
PORTVERSION=	0.8
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplayer Chinese Checkers game

LIB_DEPENDS=	libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libgnet-2.0.so:${PORTSDIR}/net/gnet2

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:env

OPTIONS_DEFINE=	DOCS

DESKTOP_ENTRIES=	"cheech" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
			"cheech" \
			"Game;BoardGame;" \
			"false"

INSTALL_TARGET=	install install-cheechdocDATA

post-patch:
	@${REINPLACE_CMD} -e "s|doc/cheech|share/doc/cheech|g" \
		-e "s|: install-cheechdocDATA|:|g" \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|connect(SigC::slot|connect(sigc::mem_fun|g ; \
		s|#include <sigc++\/compatibility\.h>||g' \
			${WRKSRC}/src/*.cc

pre-configure:
	@${LN} -sf ${AUTOMAKE_DIR}/install-sh ${WRKSRC}

.include <bsd.port.mk>
