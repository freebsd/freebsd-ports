# New ports collection makefile for:	Dodgin' Diamond 2
# Date created:			15 Jul 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		dodgindiamond2
PORTVERSION=		0.2.2
PORTREVISION=	3
CATEGORIES=		games
MASTER_SITES=		http://www.usebox.net/jjm/dd2/releases/
DISTNAME=		dd2-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		An old school shoot'em up game

USE_SDL=		sdl image mixer
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--localstatedir=/var/games

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|COPYING||g' ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} '/install-data-am:/s/install-docsDATA//' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	${MKDIR} ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/src/data/dd2.cfg ${PREFIX}/etc/dd2.cfg.sample
.if !exists(${PREFIX}/etc/dd2.cfg)
	${INSTALL_DATA} ${WRKSRC}/src/data/dd2.cfg ${PREFIX}/etc
.endif
	${CHGRP} games ${PREFIX}/bin/dd2
	${CHMOD} g+s ${PREFIX}/bin/dd2
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
