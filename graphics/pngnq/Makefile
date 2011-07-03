# New ports collection makefile for:   pngnq
# Date created:        10 May 2009
# Whom:                stb@lassitu.de
#
# $FreeBSD$
#

PORTNAME=	pngnq
PORTVERSION=	1.1
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	stb@lassitu.de
COMMENT=	A tool for quantizing PNG images in RGBA format

LICENSE=	BSD

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" LIBS=-lpng

USE_GNOME=	pkgconfig

PORTDOCS=	README COPYING
PLIST_FILES=	bin/pngcomp bin/pngnq
MAN1=		pngnq.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
