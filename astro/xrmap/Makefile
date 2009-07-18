# New ports collection makefile for:	xrmap
# Date created:				25 Dec 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	xrmap
PORTVERSION=	2.33
PORTREVISION=	5
CATEGORIES=	astro geography
MASTER_SITES=	ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/data/:data \
		ftp://ftp.ac-grenoble.fr/ge/geosciences/xrmap/:src
DISTFILES=	${SRCFILE}:src ${DATAFILES:S|$|:data|} ${CIAFILE}:data ${POPFILE}:data
DIST_SUBDIR=	xrmap
EXTRACT_ONLY=	${SRCFILE} ${DATAFILES}

MAINTAINER=	serge.gagnon.1@ulaval.ca
COMMENT=	Map portions of the earth from a given longitude/latitude

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_BZIP2=	yes
USE_IMAKE=	yes
MANCOMPRESSED=	no
USE_XORG=	xpm

CIAFILE=	CIA_WDB2.jpd.bz2
POPFILE=	population.dat.bz2
SRCFILE=	xrmap-${PORTVERSION}.tar.bz2
DATAFILES=	anthems-1.2.tar.bz2 earthdata_med_res.tar.bz2 \
		factbook_text_2006.tar.bz2 factbook_html_2006.tar.bz2 \
		flags-2.9-eps.tar.bz2 hymns-1.3.tar.bz2 pdfmaps-1.3.tar.bz2

MAN1=		emx.1 xrmap.1
PORTDOCS=	*

MAKE_ARGS=	DESTDIR="${PREFIX}"

post-extract:
	@${BZIP2_CMD} -dc ${_DISTDIR}/${CIAFILE} >${WRKDIR}/CIA_WDB2.jpd
	@${MKDIR} ${WRKDIR}/earthdata/population
	@${BZIP2_CMD} -dc ${_DISTDIR}/${POPFILE} > \
	${WRKDIR}/earthdata/population/population.dat
	@${RM} -f ${WRKDIR}/flags/svg/=

post-patch:
	@${REINPLACE_CMD} -Ee 's|cc |$(CC) $(CFLAGS) |' ${WRKSRC}/tools/Makefile
	@${REINPLACE_CMD} -Ee '/FLAGPATH/ s,/(xpm|svg|eps|png),,' ${WRKSRC}/xrmap.c
	@${REINPLACE_CMD} -e 's|SHAREDIR"/doc"|"${DOCSDIR}"|' ${WRKSRC}/xrmap.h

do-install:
# install xrmap
	${INSTALL_PROGRAM} ${WRKSRC}/xrmap ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xrmap._man ${PREFIX}/man/man1/xrmap.1
	${MKDIR} ${PREFIX}/share/rmap
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/share/rmap/
.for f in Locations Xrmaprc i18n picons pixmaps postscript rc themes
	cd ${WRKSRC} && \
	${FIND} ${f} -type d -exec ${MKDIR} "${PREFIX}/share/rmap/{}" \; && \
	${FIND} ${f} -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/share/rmap/{}" \;
.endfor

# install editkit
	${INSTALL_PROGRAM} ${WRKSRC}/editkit/emx ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/editkit/emx._man ${PREFIX}/man/man1/emx.1
	${MKDIR} ${PREFIX}/share/editkit
	${INSTALL_DATA} ${WRKSRC}/editkit/rc.example ${PREFIX}/share/editkit/rc.common
	cd ${PREFIX}/share/editkit && ${LN} -sf rc.common emxrc

# install earthview
	${INSTALL_PROGRAM} ${WRKSRC}/earthview/earthview ${PREFIX}/bin
.for f in population topography
	${MKDIR} ${PREFIX}/share/rmap/earthdata/${f}
	${INSTALL_DATA} ${WRKSRC}/earthview/data/${f}.cps ${PREFIX}/share/rmap/earthdata/${f}
.endfor

# install extra data
.for f in CIA_WDB2.jpd anthems earthdata factbook flags hymns pdfmaps
	cd ${WRKDIR} && \
	${FIND} ${f} -type d -exec ${MKDIR} "${PREFIX}/share/rmap/{}" \; && \
	${FIND} ${f} -type l -exec ${CP} -Rf "{}" "${PREFIX}/share/rmap/{}" \; && \
	${FIND} ${f} ! -type d ! -type l -exec ${INSTALL_DATA} "{}" "${PREFIX}/share/rmap/{}" \;
.endfor

# install documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for doc in CHANGES MAPEDIT TODO VECTORMAP
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.  endfor
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README.xrmap
	${INSTALL_DATA} ${WRKSRC}/editkit/README ${DOCSDIR}/README.editkit
	${INSTALL_DATA} ${WRKSRC}/earthview/README ${DOCSDIR}/README.earthview
	${INSTALL_DATA} ${WRKSRC}/midi_cfg/README.midi ${DOCSDIR}
.endif

.include <bsd.port.mk>
