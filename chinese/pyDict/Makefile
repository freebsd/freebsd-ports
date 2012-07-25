# New ports collection makefile for:	pyDict
# Date created:		25 Oct 1999
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pyDict
PORTVERSION=	0.2.6.3
PORTREVISION=	8
CATEGORIES=	chinese
MASTER_SITES=	LOCAL/chinsan/pyDict/ \
		http://www.525183.com/freebsd/pyDict/ \
		http://www.chinatinco.com/freebsd/pyDict/ \
		http://525183.serverbox.org/freebsd/pyDict/

MAINTAINER=	sunrychen@gmail.com
COMMENT=	A Chinese <-> English dictionary under both, console and X11

RUN_DEPENDS=	${LOCALBASE}/include/pygtk/pygtk.h:${PORTSDIR}/x11-toolkits/py-gtk \
		${LOCALBASE}/lib/X11/fonts/TrueType/bsmi00lp.ttf:${PORTSDIR}/chinese/arphicttf

WRKSRC=		${WRKDIR}/dict
NO_BUILD=	yes
SHAREMODE=	644
DICTDIR=	${PREFIX}/lib/X11/pyDict
DOCDIR=		${PREFIX}/share/doc/pyDict
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

pre-patch:
	${REINPLACE_CMD} -e 's,/bin/grep,${GREP},g' \
		-e 's,--after-context=20,-A 20,g' \
		-e 's,/usr/X11R6,${PREFIX},g' ${WRKSRC}/dict.py

do-install:
	@${MKDIR} ${DICTDIR}
	@${INSTALL_DATA} ${WRKSRC}/[a-z].lib ${WRKSRC}/dict.xpm ${WRKSRC}/yaba.xpm ${WRKSRC}/HELP ${DICTDIR}
	@${INSTALL_DATA} ${FILESDIR}/gtkrc.zh_TW.big5.sample ${DICTDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${WRKSRC}/COPYING ${WRKSRC}/README ${DOCDIR}
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/dict.py ${PREFIX}/bin/pydict

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
