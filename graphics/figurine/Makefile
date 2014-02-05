# Created by: Marc Fonvieille <blackend@FreeBSD.org>
# $FreeBSD$

PORTNAME=	figurine
PORTVERSION=	1.0.5
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Drawing program for X11

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

GNU_CONFIGURE=	yes
USE_XORG=	xpm

PLIST_FILES=	bin/figurine \
		man/man1/figurine.1.gz

PORTDOCS=	*

.include <bsd.port.options.mk>

# Optimizations produce bad assembly code on sparc64
.if ${ARCH} == "sparc64"
CFLAGS+=	-O0
.endif

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e "s|Doc examples src|src|" \
		${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|datadir = @datadir@|datadir = @datadir@/doc|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/Doc/Makefile.in \
		${WRKSRC}/examples/Makefile.in

.include <bsd.port.mk>
