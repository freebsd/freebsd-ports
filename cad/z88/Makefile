# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	z88
PORTVERSION=	13.0
PORTREVISION=	4
CATEGORIES=	cad
MASTER_SITES=	http://www.z88.uni-bayreuth.de/download/
DISTFILES=	${PORTNAME}130${EXTRACT_SUFX} ${PORTNAME}mane.pdf
DIST_SUBDIR=	z88
EXTRACT_ONLY=	${PORTNAME}130${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compact Finite Element Analysis System

LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

NO_WRKSUBDIR=	yes
USES=		pkgconfig
USE_GL=		glu
USE_GNOME=	gtk20

#These defaults can be changed in z88.fcd too
BROWSER?=	firefox3
XEDITOR?=	gedit

Z88_BINS=	z88f z88i1 z88i2 z88com z88d z88e z88g z88h z88n z88o	\
		z88x z88v
Z88_DATA=	z88.fcd z88.dyn *.dxf *.txt

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${CP} ${WRKSRC}/z88.fcd.linux ${WRKSRC}/z88.fcd
	@${CP} ${WRKSRC}/z88.mk.kernel.gcc32 ${WRKSRC}/z88.kernel.mk
	@${CP} ${WRKSRC}/z88.mk.other.gcc32 ${WRKSRC}/z88.other.mk
	@${CP} ${WRKSRC}/z88.mk.gtk.gcc32 ${WRKSRC}/z88.gtk.mk
	@${CP} ${FILESDIR}/z88.sh ${WRKSRC}/z88.sh
	@${CP} ${FILESDIR}/z88.sh ${WRKSRC}/z88.sh
	@${REINPLACE_CMD} -e 's+%%DOCSDIR%%+${DOCSDIR}+g; \
	s+firefox+${BROWSER}+ ; \
	s+joe+${XEDITOR}+ ;' \
		${WRKSRC}/z88.fcd
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+g ; s+%%CFLAGS%%+${CFLAGS}+g' \
		${WRKSRC}/z88.kernel.mk
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+g ; s+%%CFLAGS%%+${CFLAGS}+g ; \
	s+%%LOCALBASE%%+${LOCALBASE}+g;' \
		${WRKSRC}/z88.other.mk
	@${REINPLACE_CMD} -e 's+%%CC%%+${CC}+g ; s+%%CFLAGS%%+${CFLAGS}+g' \
		${WRKSRC}/z88.gtk.mk
	@${REINPLACE_CMD} -e 's+%%PREFIX%%+${PREFIX}+g; ' \
		${WRKSRC}/z88.sh

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} -f z88.kernel.mk kernel)
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} -f z88.other.mk other clean)
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} -f z88.gtk.mk gtk)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/z88.sh ${STAGEDIR}${PREFIX}/bin/z88
	${INSTALL_PROGRAM} ${Z88_BINS:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${Z88_DATA:S|^|${WRKSRC}/|} ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.htm ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.gif ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.jpg ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/z88mane.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
