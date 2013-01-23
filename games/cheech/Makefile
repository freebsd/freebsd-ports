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

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gnet-2.0.0:${PORTSDIR}/net/gnet2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	automake:env

DESKTOP_ENTRIES=	"cheech" \
			"${COMMENT}" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
			"cheech" \
			"Game;BoardGame;" \
			"false"

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-cheechdocDATA
.endif

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
