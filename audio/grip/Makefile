# New ports collection makefile for:	grip
# Date created:				31 May 2000
# Whom:					kbyanc@posi.net
#
# $FreeBSD$
#

PORTNAME=	grip
PORTVERSION=	2.94
CATEGORIES=	audio
MASTER_SITES=	http://www.nostatic.org/grip/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_GMAKE=	yes
MAKE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
ALL_TARGET=	gripnopar gcd

MAN1=		grip.1
MLINKS=		grip.1 gcd.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/grip ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gcd ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/grip.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
.for file in CHANGES CREDITS README TODO
	@${MKDIR} ${PREFIX}/share/doc/grip
	${INSTALL_MAN} ${WRKSRC}/${file} ${PREFIX}/share/doc/grip
.endfor
.endif

.include <bsd.port.mk>
