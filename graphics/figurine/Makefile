# New ports collection makefile for:	figurine
# Date created:		15 September 2002
# Whom:			Marc Fonvieille <blackend@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	figurine
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A drawing program for X11

RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

GNU_CONFIGURE=	yes
USE_XORG=	xpm

MAN1=		figurine.1

.include <bsd.port.pre.mk>

# Optimizations produce bad assembly code on sparc64
.if ${ARCH} == "sparc64"
CFLAGS+=	-O0
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|Doc examples src|src|" \
		${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's|datadir = @datadir@|datadir = @datadir@/doc|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/src/Makefile.in \
		${WRKSRC}/Doc/Makefile.in \
		${WRKSRC}/examples/Makefile.in

.include <bsd.port.post.mk>
