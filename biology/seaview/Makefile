# Created by: frankch@waru.life.nthu.edu.tw
# $FreeBSD$

PORTNAME=	seaview
PORTVERSION=	4.4.3
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	http://pbil.univ-lyon1.fr/software/seaview_data/archive/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple DNA/protein sequence alignment editor

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gmake
USE_XORG=	xext xft xinerama
MAKE_ENV=	HELPFILE='-DDEFAULT_HELPFILE=\"${DATADIR}/seaview.html\"' \
		PHYMLNAME='-DPHYMLNAME=\"phyml\"' \
		IFLTK='-I${LOCALBASE}/include' \
		LFLTK='-L${LOCALBASE}/lib' \
		USE_XFT='-DUSE_XFT' \
		OPT="${CFLAGS}"
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/seaview man/man1/seaview.1.gz %%DATADIR%%/seaview.html
PLIST_DIRS=	%%DATADIR%%

DESKTOP_ENTRIES="SeaView" "${COMMENT}" "" \
		"${PORTNAME}" "Biology;Science;" "true"

OPTIONS_DEFINE=		PDFLIB
OPTIONS_DEFAULT=	PDFLIB
PDFLIB_DESC=		PDFlib support
PDFLIB_LIB_DEPENDS=	libpdf.so:${PORTSDIR}/print/pdflib
PDFLIB_MAKE_ENV=	LPDF='-L${LOCALBASE}/lib -lpdf'
PDFLIB_MAKE_ENV_OFF=	PDF_PS_FLAGS='-DNO_PDF'

post-patch:
	@${REINPLACE_CMD} -e \
		's|^\(PDF_PS_FLAGS\) |#\1 | ; \
		 s|^\(FLTK\) |#\1 | ; \
		 s|^\(USE_XFT\) |#\1 | ; \
		 s|^\(CC\) |#\1 | ; \
		 s|^\(CXX\) |#\1 | ; \
		 s|^\(OPT\) |#\1 | ; \
		 s|-lpthread|-pthread|' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} seaview \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} seaview.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} seaview.html \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
