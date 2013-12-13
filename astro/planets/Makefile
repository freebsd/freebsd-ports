# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	planets
PORTVERSION=	0.1.13
CATEGORIES=	astro
MASTER_SITES=	GENTOO/distfiles \
		http://planets.homedns.org/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Orbital simulator

LICENSE=	GPLv2

BUILD_DEPENDS=	ocaml:${PORTSDIR}/lang/ocaml

USES=		gmake
USE_XORG=	x11
ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	KEYBINDINGS.txt getting_started.html
PLIST_FILES=	bin/planets man/man1/planets.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/planets.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
