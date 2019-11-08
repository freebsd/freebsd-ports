# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	dodgindiamond2
PORTVERSION=	0.2.2
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	http://www.usebox.net/jjm/dd2/releases/
DISTNAME=	dd2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Old school shoot'em up game

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		sdl
USE_SDL=	sdl image mixer
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games

DATADIR=	${PREFIX}/share/dd2

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|COPYING||g' ${WRKSRC}/Makefile.in

post-patch-DOCS-off:
	@${REINPLACE_CMD} '/install-data-am:/s/install-docsDATA//' \
		${WRKSRC}/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/src/data/dd2.cfg ${STAGEDIR}${PREFIX}/etc/dd2.cfg.sample
	@${MKDIR} ${STAGEDIR}/var/games
	${TOUCH} ${STAGEDIR}/var/games/dd2-hiscore.sample

.include <bsd.port.mk>
