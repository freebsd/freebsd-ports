# ex:ts=8
# Ports collection makefile for:	planets
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	planets
PORTVERSION=	0.1.12
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://planets.homedns.org/dist/ \
		http://sheepkiller.nerim.net/ports/${PORTNAME}/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An orbital simulator

BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}

MAN1=	planets.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/planets.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in KEYBINDINGS.txt getting_started.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
