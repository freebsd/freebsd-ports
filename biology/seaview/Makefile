# Created by: frankch@waru.life.nthu.edu.tw
# $FreeBSD$

PORTNAME=	seaview
PORTVERSION=	4.4.2
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	http://pbil.univ-lyon1.fr/software/seaview_data/archive/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple DNA/protein sequence alignment editor

LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk

OPTIONS_DEFINE=	PDFLIB
OPTIONS_DEFAULT=PDFLIB
PDFLIB_DESC=	PDFlib support

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	xext xft xinerama
USE_GMAKE=	yes
MAKE_ENV=	HELPFILE='-DDEFAULT_HELPFILE=\"${DATADIR}/seaview.html\"' \
		PHYMLNAME='-DPHYMLNAME=\"phyml\"' \
		IFLTK='-I${LOCALBASE}/include' \
		LFLTK='-L${LOCALBASE}/lib' \
		USE_XFT='-DUSE_XFT' \
		OPT="${CFLAGS}"
ALL_TARGET=	${PORTNAME}
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/seaview %%DATADIR%%/seaview.html
PLIST_DIRS=	%%DATADIR%%

DESKTOP_ENTRIES="SeaView" "${COMMENT}" "" \
		"${PORTNAME}" "Biology;Science;" "true"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPDFLIB}
LIB_DEPENDS+=	pdf:${PORTSDIR}/print/pdflib
MAKE_ENV+=	LPDF='-L${LOCALBASE}/lib -lpdf'
.else
MAKE_ENV+=	PDF_PS_FLAGS='-DNO_PDF'
.endif

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
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} seaview ${PREFIX}/bin)
	@${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} seaview.html ${DATADIR})

.include <bsd.port.mk>
