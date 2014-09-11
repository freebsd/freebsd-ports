# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=		dodgindiamond2
PORTVERSION=		0.2.2
PORTREVISION=	9
CATEGORIES=		games
MASTER_SITES=		http://www.usebox.net/jjm/dd2/releases/
DISTNAME=		dd2-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		Old school shoot'em up game

USE_SDL=		sdl image mixer
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--localstatedir=/var/games

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|COPYING||g' ${WRKSRC}/Makefile.in
.if empty(PORT_OPTIONS:MDOCS)
	@${REINPLACE_CMD} '/install-data-am:/s/install-docsDATA//' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/src/data/dd2.cfg ${STAGEDIR}${PREFIX}/etc/dd2.cfg.sample

.include <bsd.port.mk>
