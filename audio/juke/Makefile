# Created by: Oyvind Moll <oyvindmo@initio.no>
# $FreeBSD$

PORTNAME=	juke
PORTVERSION=	0.7
CATEGORIES=	audio
MASTER_SITES=	http://www.moll.no/oyvind/distfiles/ \
		http://www.orakel.ntnu.no/~oyvindmo/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple (n)curses based juke box program

GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	VI_BINDINGS
VI_BINDINGS_DESC=	Use vi-like key bindings

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVI_BINDINGS}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-vi
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/juke.conf ${STAGEDIR}${PREFIX}/etc/juke.conf.sample

.include <bsd.port.mk>
