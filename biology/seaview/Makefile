# Created by: frankch@waru.life.nthu.edu.tw
# $FreeBSD$

PORTNAME=	seaview
PORTVERSION=	4.4.0
PORTEPOCH=	1
CATEGORIES=	biology
MASTER_SITES=	http://pbil.univ-lyon1.fr/software/seaview_data/archive/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiple DNA/protein sequence alignment editor

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		fltk:${PORTSDIR}/x11-toolkits/fltk \
		xcb:${PORTSDIR}/x11/libxcb

OPTIONS_DEFINE=	PDFLIB
OPTIONS_DEFAULT=PDFLIB
PDFLIB_DESC=	PDFlib support

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	x11 xau xdmcp xext xft xinerama xrender
USE_GMAKE=	yes
MAKE_ENV=	HELPFILE='-DDEFAULT_HELPFILE=\"${DATADIR}/seaview.html\"' \
		PHYMLNAME='-DPHYMLNAME=\"phyml\"' \
		IFLTK='-I${LOCALBASE}/include' \
		LFLTK='-L${LOCALBASE}/lib' \
		USE_XFT='-DUSE_XFT' \
		OPT="${CFLAGS}"
ALL_TARGET=	${PORTNAME}
MAKE_JOBS_SAFE=	yes

DESKTOP_ENTRIES="SeaView" "${COMMENT}" "" \
		"${PORTNAME}" "Biology;Science;" "true"

PLIST_FILES=	bin/seaview %%DATADIR%%/seaview.html
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPDFLIB}
LIB_DEPENDS+=	pdf:${PORTSDIR}/print/pdflib
MAKE_ENV+=	LPDF='-L${LOCALBASE}/lib -lpdf'
.else
MAKE_ENV+=	PDF_PS_FLAGS='-DNO_PDF'
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^PDF_PS_FLAGS |#PDF_PS_FLAGS | ; \
		 s|^FLTK |#FLTK | ; \
		 s|^USE_XFT |#USE_XFT | ; \
		 s|^CC |#CC | ; \
		 s|^CXX |#CXX | ; \
		 s|^OPT |#OPT | ; \
		 s|-lpthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/seaview.html ${DATADIR}

.include <bsd.port.mk>
