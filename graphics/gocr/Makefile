# Created by: Kay Lehmann
# $FreeBSD$

PORTNAME=	gocr
PORTVERSION=	0.50
CATEGORIES=	graphics
MASTER_SITES=	http://www-e.uni-magdeburg.de/jschulen/ocr/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	OCR (Optical Character Recognition) program

LICENSE=	GPLv2

LIB_DEPENDS=	netpbm.1:${PORTSDIR}/graphics/netpbm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-netpbm=${LOCALBASE}
USE_GMAKE=	yes
MAKE_ARGS=	prefix=${PREFIX} exec_prefix=${PREFIX} DESTDIR=${DESTDIR}

PLIST_FILES=	bin/gocr

MAN1=	gocr.1
PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS BUGS CREDITS HISTORY README READMEde.txt TODO

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	*.dtd *.xml *.html *.txt *.fig *.png

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=	X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_TK_WRAPPER=	yes
PLIST_FILES+=	bin/gocr.tcl
.endif

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|@LIBS@|-L${LOCALBASE}/lib @LIBS@|g' ${WRKSRC}/src/Makefile.in
.if !  ${PORT_OPTIONS:MX11}
	@${REINPLACE_CMD} -e '/gocr.tcl/d' ${WRKSRC}/src/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${DOCSDIR2}
.endif

.include <bsd.port.mk>
