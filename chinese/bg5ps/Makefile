# New ports collection makefile for:	bg5ps
# Version required:	1.1b
# Date created:		17 June 1998
# Whom:			J.T. Jang (keith@email.gcn.net.tw)
#
# $FreeBSD$
#

DISTNAME=	bg5ps-1.1b
PKGNAME=	zh-bg5ps-1.1b
CATEGORIES=	chinese print
MASTER_SITES=	http://weber.u.washington.edu/~cschin/bg5ps/bg5ps-1.1b/
EXTRACT_SUFX=	.tgz

MAINTAINER=	keith@email.gcn.net.tw

RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_WRKSUBDIR=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/doc/bg5ps
	${INSTALL_SCRIPT} ${WRKSRC}/bg5ps ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ttf2psm ${PREFIX}/bin
.for doc in README bg5ps.conf test.big5 test.sh ttf2ps.doc
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/bg5ps
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
