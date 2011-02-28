# ports collection makefile for:	xpx
# Date created:		25 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	xpx
PORTVERSION=	1.41
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.oersted.co.jp/~yav/soft/xpx/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple pixel editing tool to make datas for KISS

BROKEN=		does not build

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_IMAKE=	yes
USE_XORG=	x11 xext
XMKMF=		xmkmf
CPP=		#

DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}
PORTDOCS=	xpx.doc xpxrc.eg
PLIST_FILES=	bin/xpx

post-patch:
	@${REINPLACE_CMD} -e 's|myname|my_name|g' ${WRKSRC}/magtoppm.c
	@${REINPLACE_CMD} -e '/edit_mode/d' ${WRKSRC}/work.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
