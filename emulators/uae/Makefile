# New ports collection makefile for: uae
# Date created: 22 May 2000
# Whom: Simon Dick <simond@irrelevant.org>
#
# $FreeBSD$
#

PORTNAME=	uae
PORTVERSION=	0.8.15
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.freiburg.linux.de/pub/uae/sources/develop/ \
		http://www.users.globalnet.co.uk/~simd/

MAINTAINER=	simond@irrelevant.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sound
USE_XLIB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uae ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/readdisk ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/doc/uae
	${INSTALL_DATA} ${WRKSRC}/docs/COMPATIBILITY ${PREFIX}/share/doc/uae
	${INSTALL_DATA} ${WRKSRC}/docs/CREDITS ${PREFIX}/share/doc/uae
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${PREFIX}/share/doc/uae
	${INSTALL_DATA} ${WRKSRC}/docs/NEWS ${PREFIX}/share/doc/uae
	${INSTALL_DATA} ${WRKSRC}/docs/README ${PREFIX}/share/doc/uae
	${INSTALL_DATA} ${WRKSRC}/docs/README.PROGRAMMERS ${PREFIX}/share/doc/uae
	${INSTALL_DATA} ${WRKSRC}/docs/unix/README ${PREFIX}/share/doc/uae/README.unix

.include <bsd.port.mk>
