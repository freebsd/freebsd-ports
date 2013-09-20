# Created by: Serge Negodyuck <petr@petrovich.kiev.ua>
# $FreeBSD$

PORTNAME=	xnview
PORTVERSION=	1.70
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://download.xnview.com/
DISTFILES=	XnView-x86-unknown-FreeBSD5.x-static.tgz

MAINTAINER=	petr@petrovich.kiev.ua
COMMENT=	An easy graphics viewer / converter

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/XnView-${PORTVERSION}-x86-unknown-FreeBSD5.x-static
INSTALL_SLIB=	yes

MAN1=		xnview.1 nview.1
MLINKS=		nview.1 nv.1 \
		nview.1	nconvert.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
DISTFILES+=	NConvert-x86-unknown-FreeBSD6.x.tgz
WRKSRC_NC=	${WRKDIR}/NConvert

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xnview ${PREFIX}/bin/xnview
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nview ${PREFIX}/bin/nv
	${INSTALL_PROGRAM} ${WRKSRC_NC}/nconvert ${PREFIX}/bin/nconvert
	${INSTALL_DATA} ${WRKSRC}/app-defaults/XnView.ad ${PREFIX}/lib/X11/app-defaults/XnView
	cd ${WRKSRC}/man && ${INSTALL_MAN} xnview.1 nview.1 ${PREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC_NC} && \
		${INSTALL_DATA} Formats.txt ReadMe.txt Usage.txt WhatsNew.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
