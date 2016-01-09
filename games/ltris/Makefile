# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ltris
PORTVERSION=	1.0.19
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Tetris clone but a good one with bunch of cool features

USE_SDL=	mixer sdl
GNU_CONFIGURE=	yes
USES=		gmake localbase
CONFIGURE_ARGS=	--localstatedir=/var/games

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's/\/icons/\/pixmaps/g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/= @mixer_flag@/= @INTLLIBS@ @mixer_flag@/g ; \
		 s/--mode=666//g' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's/^inline //' \
		${WRKSRC}/src/sdl.h ${WRKSRC}/src/tools.h

post-install:
	${MV$} ${STAGEDIR}/var/games/ltris.hscr ${STAGEDIR}/var/games/ltris.hscr.sample

.include <bsd.port.mk>
