# New ports collection makefile for:    xnview
# Date created:         9 Jul 2002
# Whom: Serge Negodyuck <petr@petrovich.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	xnview
PORTVERSION=	1.50
CATEGORIES=	graphics
MASTER_SITES=	ftp://www.zoo-logique.org/xnview/download/
DISTNAME=	XnView-x86-unknown-FreeBSD4.x-static
EXTRACT_SUFX=	.tgz

MAINTAINER=	petr@petrovich.kiev.ua
COMMENT=	An easy graphics viewer / converter

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/XnView-1.50-x86-unknown-FreeBSD4.x-static
INSTALL_SLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xnview ${PREFIX}/bin/xnview
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nview ${PREFIX}/bin/nv
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nconvert ${PREFIX}/bin/nconvert
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libformat.so.3.87 ${PREFIX}/lib/libformat.so.3
	${LN} -sf ${PREFIX}/lib/libformat.so.3 ${PREFIX}/lib/libformat.so
	${INSTALL_DATA} ${WRKSRC}/app-defaults/XnView.ad ${PREFIX}/lib/X11/app-defaults/XnView
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && \
		${INSTALL_DATA} Formats.txt ReadMe.txt Usage.txt WhatsNew.txt \
		${DOCSDIR}
.endif

.include <bsd.port.post.mk>
