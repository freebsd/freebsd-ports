# New ports collection makefile for:	bg5ps
# Date created:		17 June 1998
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bg5ps
PORTVERSION=	1.3.0p3
CATEGORIES=	chinese print
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/
DISTNAME=	bg5ps-1.3.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Chinese-Big5/GB encoded files to Postscript, using TTF fonts

USE_FREETYPE=	yes
USE_PYTHON=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/doc/bg5ps
	@${MKDIR} ${PREFIX}/share/examples/bg5ps
	${INSTALL_SCRIPT} ${WRKSRC}/bg5ps ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ttf2psm ${PREFIX}/bin
	${CP} -R ${WRKSRC}/doc/* ${PREFIX}/share/doc/bg5ps
	${INSTALL_DATA} ${WRKSRC}/bg5ps.conf ${PREFIX}/etc/bg5ps.conf.sample
	${INSTALL_DATA} ${WRKSRC}/gb2312-bg5ps.conf ${PREFIX}/etc/gb2312-bg5ps.conf.sample
	${INSTALL_DATA} ${WRKSRC}/examples/netscape.ps ${PREFIX}/share/examples/bg5ps
	${INSTALL_DATA} ${WRKSRC}/examples/test.big5 ${PREFIX}/share/examples/bg5ps
	${INSTALL_DATA} ${WRKSRC}/examples/test.gb2312 ${PREFIX}/share/examples/bg5ps
	${INSTALL_SCRIPT} ${WRKSRC}/examples/test.sh ${PREFIX}/share/examples/bg5ps

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
