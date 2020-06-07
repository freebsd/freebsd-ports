# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ltris
PORTVERSION=	1.0.20
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tetris clone but a good one with bunch of cool features

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake localbase sdl
USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var/games

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's/\/icons/\/pixmaps/g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/= @mixer_flag@/= @INTLLIBS@ @mixer_flag@/g ; \
		 s/--mode=666//g' ${WRKSRC}/src/Makefile.in

post-install:
	${MV$} ${STAGEDIR}/var/games/ltris.hscr ${STAGEDIR}/var/games/ltris.hscr.sample

.include <bsd.port.mk>
