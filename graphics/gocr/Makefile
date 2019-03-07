# Created by: Kay Lehmann
# $FreeBSD$

PORTNAME=	gocr
PORTVERSION=	0.52
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

X11_USES=		tk
X11_PLIST_FILES=	bin/gocr.tcl

post-patch:
	@${REINPLACE_CMD} -e 's|@LIBS@|-L${LOCALBASE}/lib @LIBS@|g' ${WRKSRC}/src/Makefile.in

post-patch-X11-off:
	@${REINPLACE_CMD} -e '/gocr.tcl/d' ${WRKSRC}/src/Makefile.in

post-patch-X11-on:
	@${REINPLACE_CMD} -e 's|exec wish|exec ${WISH}|' ${WRKSRC}/bin/gocr.tcl

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/gocr

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOC_FILES1:S|^|${DOCSRCDIR1}/|} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR2}
	${INSTALL_DATA} ${DOC_FILES2:S|^|${DOCSRCDIR2}/|} ${STAGEDIR}${DOCSDIR2}

.include <bsd.port.mk>
