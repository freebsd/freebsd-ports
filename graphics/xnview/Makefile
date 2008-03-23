# New ports collection makefile for:    xnview
# Date created:         9 Jul 2002
# Whom: Serge Negodyuck <petr@petrovich.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	xnview
PORTVERSION=	1.70
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.xnview-download.de/download/
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

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
    LIB_DEPENDS+=       c.5:${PORTSDIR}/misc/compat5x
    DISTFILES+=	NConvert-x86-unknown-FreeBSD6.x.tgz
    WRKSRC_NC=	${WRKDIR}/NConvert
.endif

.if ${OSVERSION} >= 700000
    LIB_DEPENDS+=	c.6:${PORTSDIR}/misc/compat6x
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xnview ${PREFIX}/bin/xnview
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nview ${PREFIX}/bin/nv
.if ${OSVERSION} >= 600000
	${INSTALL_PROGRAM} ${WRKSRC_NC}/nconvert ${PREFIX}/bin/nconvert
.else
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nconvert ${PREFIX}/bin/nconvert
.endif
	${INSTALL_DATA} ${WRKSRC}/app-defaults/XnView.ad ${PREFIX}/lib/X11/app-defaults/XnView
	cd ${WRKSRC}/man && ${INSTALL_MAN} xnview.1 nview.1 ${PREFIX}/man/man1

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.if ${OSVERSION} >= 600000
	cd ${WRKSRC_NC} && \
		${INSTALL_DATA} Formats.txt ReadMe.txt Usage.txt WhatsNew.txt ${DOCSDIR}
.else
	cd ${WRKSRC} && \
		${INSTALL_DATA} Formats.txt ReadMe.txt Usage.txt WhatsNew.txt ${DOCSDIR}
.endif
.endif

.include <bsd.port.post.mk>
