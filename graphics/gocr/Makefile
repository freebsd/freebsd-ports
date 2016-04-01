# Created by: Kay Lehmann
# $FreeBSD$

PORTNAME=	gocr
PORTVERSION=	0.50
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www-e.uni-magdeburg.de/jschulen/ocr/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	OCR (Optical Character Recognition) program

LICENSE=	GPLv2

LIB_DEPENDS=	libnetpbm.so:graphics/netpbm

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-netpbm=${LOCALBASE}
MAKE_ARGS=	prefix=${PREFIX} exec_prefix=${PREFIX} DESTDIR=${DESTDIR}

PLIST_FILES=	bin/gocr \
		man/man1/gocr.1.gz

PORTDOCS=	*

DOCSRCDIR1=	${WRKSRC}
DOC_FILES1=	AUTHORS BUGS CREDITS HISTORY README READMEde.txt TODO

DOCSRCDIR2=	${WRKSRC}/doc
DOCSDIR2=	${DOCSDIR}/doc
DOC_FILES2=	*.dtd *.xml *.html *.txt *.fig *.png

OPTIONS_DEFINE=	X11 DOCS
OPTIONS_DEFAULT=	X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USES+=		tk
PLIST_FILES+=	bin/gocr.tcl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|@LIBS@|-L${LOCALBASE}/lib @LIBS@|g' ${WRKSRC}/src/Makefile.in
.if !  ${PORT_OPTIONS:MX11}
	@${REINPLACE_CMD} -e '/gocr.tcl/d' ${WRKSRC}/src/Makefile.in
.else
	@${REINPLACE_CMD} -e 's|exec wish|exec ${WISH}|' ${WRKSRC}/bin/gocr.tcl
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gocr
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}
.endif

.include <bsd.port.mk>
