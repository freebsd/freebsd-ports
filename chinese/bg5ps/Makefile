# New ports collection makefile for:	bg5ps
# Date created:		17 June 1998
# Whom:			J.T. Jang (keith@freebsd.sinica.edu.tw)
#
# $FreeBSD$
#

PORTNAME=	bg5ps
PORTVERSION=	1.1b2
CATEGORIES=	chinese print
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/ \
		http://students.washington.edu/~cschin/bg5ps/bg5ps-1.1b2/
EXTRACT_SUFX=	.tgz

MAINTAINER=	keith@freebsd.sinica.edu.tw

RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${X11BASE}/lib/X11/fonts/TrueType/moe_kai.ttf:${PORTSDIR}/chinese/moettf

NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/doc/bg5ps
	@${MKDIR} ${PREFIX}/share/examples/bg5ps
	${INSTALL_SCRIPT} ${WRKSRC}/bg5ps ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ttf2psm ${PREFIX}/bin
	${CP} -R ${WRKSRC}/doc/* ${PREFIX}/share/doc/bg5ps
	${RM} ${PREFIX}/share/doc/bg5ps/COPYING.txt
	${INSTALL_DATA} ${WRKSRC}/bg5ps.conf ${PREFIX}/share/doc/bg5ps/bg5ps.conf
	${INSTALL_DATA} ${WRKSRC}/examples/netscape.ps ${PREFIX}/share/examples/bg5ps
	${INSTALL_DATA} ${WRKSRC}/examples/test.big5 ${PREFIX}/share/examples/bg5ps
	${INSTALL_SCRIPT} ${WRKSRC}/examples/test.sh ${PREFIX}/share/examples/bg5ps

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
