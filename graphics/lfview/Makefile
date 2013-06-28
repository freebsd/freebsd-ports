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
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
MAKE_ENV=	"SHLIBGLOBALSFLAGS=-fPIC"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lfview ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/plugins/liblfv_leaf.so.1 ${PREFIX}/lib
	${LN} -s ${PREFIX}/lib/liblfv_leaf.so.1 ${PREFIX}/lib/liblfv_leaf.so
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${PREFIX}/share/doc/ja/lfview
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/ja/lfview
.endif

.include <bsd.port.post.mk>
