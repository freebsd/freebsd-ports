# New ports collection makefile for:	pyDict
# Date created:		25 Oct 1999
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyDict
PORTVERSION=	0.2.5
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/
DISTNAME=	pyDict-0.2.5.1

MAINTAINER=	keith@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/include/pygtk/pygtk.h:${PORTSDIR}/x11-toolkits/py-gtk \
		${X11BASE}/lib/X11/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf

USE_X_PREFIX=	yes

WRKSRC=		${WRKDIR}/dict
NO_BUILD=	yes
SHAREMODE=	644
DICTDIR=	${PREFIX}/lib/X11/pyDict
DOCDIR=		${PREFIX}/share/doc/pyDict

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${DICTDIR}
	@${INSTALL_DATA} ${WRKSRC}/[a-z].lib ${WRKSRC}/dict.xpm ${WRKSRC}/yaba.xpm ${WRKSRC}/HELP ${DICTDIR}
	@${INSTALL_DATA} ${FILESDIR}/gtkrc.zh_TW.big5.sample ${DICTDIR}
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/COPYING ${WRKSRC}/README ${DOCDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/dict.py ${PREFIX}/bin/pydict

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
