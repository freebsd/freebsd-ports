# Created by: Serge Negodyuck <petr@petrovich.kiev.ua>
# $FreeBSD$

PORTNAME=	xnview
PORTVERSION=	1.70
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://download.xnview.com/
DISTFILES=	XnView-x86-unknown-FreeBSD5.x-static.tgz

MAINTAINER=	petr@petrovich.kiev.ua
COMMENT=	Easy graphics viewer / converter

USES=		cpe
ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/XnView-${PORTVERSION}-x86-unknown-FreeBSD5.x-static
INSTALL_SLIB=	yes

OPTIONS_DEFINE=	DOCS

LIB_DEPENDS+=	libc.so.5:misc/compat5x
DISTFILES+=	NConvert-x86-unknown-FreeBSD6.x.tgz
WRKSRC_NC=	${WRKDIR}/NConvert

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xnview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nview ${STAGEDIR}${PREFIX}/bin/nv
	${INSTALL_PROGRAM} ${WRKSRC_NC}/nconvert ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/app-defaults/XnView.ad \
		${STAGEDIR}${PREFIX}/lib/X11/app-defaults/XnView
	cd ${WRKSRC}/man && ${INSTALL_MAN} xnview.1 nview.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC_NC} && \
		${INSTALL_DATA} Formats.txt ReadMe.txt Usage.txt WhatsNew.txt \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
