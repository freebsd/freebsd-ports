# ex:ts=8
# Ports collection makefile for:	planets
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	planets
PORTVERSION=	0.1.13
CATEGORIES=	astro
MASTER_SITES=	GENTOO/distfiles \
		http://planets.homedns.org/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An orbital simulator

LICENSE=	GPLv2

BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

USE_GMAKE=	yes
ALL_TARGET=	${PORTNAME}

MAN1=		planets.1
PORTDOCS=	KEYBINDINGS.txt getting_started.html
PLIST_FILES=	bin/planets

.if defined(WITHOUT_X11)
BROKEN=		Does not build without X11 support
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/planets.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
