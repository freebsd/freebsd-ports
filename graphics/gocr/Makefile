# New ports collection makefile for:	gocr
# Date created:				03 June 2002
# Whom:					Kay Lehmann
#
# $FreeBSD$
#

PORTNAME=	gocr
PORTVERSION=	0.47
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/jocr

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	An OCR (Optical Character Recognition) program

LIB_DEPENDS=	netpbm.1:${PORTSDIR}/graphics/netpbm

USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-netpbm=${LOCALBASE}
MAKE_ARGS=	prefix=${PREFIX} exec_prefix=${PREFIX} DESTDIR=${DESTDIR}

MAN1=		gocr.1
PORTDOCS=	examples.txt gocr.html unicode.txt
PLIST_FILES=	bin/gocr

.if !defined(WITHOUT_X11)
USE_TK_WRAPPER=	yes
PLIST_FILES+=	bin/gocr.tcl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@LIBS@|-L${LOCALBASE}/lib @LIBS@|g' ${WRKSRC}/src/Makefile.in
.if defined(WITHOUT_X11)
	@${REINPLACE_CMD} -e '/gocr.tcl/d' ${WRKSRC}/src/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

.include <bsd.port.mk>
