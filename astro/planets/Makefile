# ex:ts=8
# Ports collection makefile for:	planets
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	planets
PORTVERSION=	0.1.5
CATEGORIES=	astro
MASTER_SITES=	http://planets.homedns.org/dist/${PORTVERSION}/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An orbital simulator

BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in KEYBINDINGS.txt getting_started.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
