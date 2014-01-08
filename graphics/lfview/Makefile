# Created by: Yuu Yashiki
# $FreeBSD$

PORTNAME=	lfview
PORTVERSION=	1.1a
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://hoshina.denpa.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphic viewer for Leaf products

USES=		imake
USE_XORG=	x11 xext
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS
DOCSDIR=	${PREFIX}/share/doc/ja/lfview

.include <bsd.port.options.mk>

.if ${ARCH} != i386
CFLAGS+=	-fPIC
MAKE_ENV+=	SHLIBGLOBALSFLAGS=-fPIC
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lfview ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/plugins/liblfv_leaf.so.1 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf liblfv_leaf.so.1 ${STAGEDIR}${PREFIX}/lib/liblfv_leaf.so
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
