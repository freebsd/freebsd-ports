# New ports collection makefile for:	hanterm3.04
# Date created:		12 Mar 1997
# Whom:			CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#

PORTNAME=	hanterm
PORTVERSION=	3.1.4
PORTREVISION=	1
CATEGORIES=	korean x11
MASTER_SITES=	http://quagga.kaist.ac.kr/hanterm/download/

MAINTAINER=	cjh@FreeBSD.org

RUN_DEPENDS=	${X11BASE}/lib/X11/fonts/local/johabm16.pcf.gz:${PORTSDIR}/korean/johabfonts

USE_IMAKE=	yes
NO_INSTALL_MANPAGES= yes
ALL_TARGET=	hanterm

post-install:
	${MKDIR} ${PREFIX}/share/doc/hanterm
	${INSTALL_DATA} ${WRKSRC}/hanterm.html ${PREFIX}/share/doc/hanterm/
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${PREFIX}/share/doc/hanterm/

.include <bsd.port.mk>
