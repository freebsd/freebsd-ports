# Ports collection makefile for:  ted
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ted
PORTVERSION=	2.10
CATEGORIES=	editors textproc print
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/
DISTNAME=	ted-${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/Ted-${PORTVERSION}
USE_MOTIF=	yes
ALL_TARGET=	compile.shared

AFMDIR=		${PREFIX}/share/Ted/afm
INDDIR=		${PREFIX}/share/Ted/ind
INFODIR=	${PREFIX}/share/doc/Ted

post-extract:
	cd ${WRKSRC}/tedPackage && ${TAR} xf TedBindist.tar

post-patch:
	cd ${WRKSRC}/tedPackage/info && \
	    ${SED} -e 's,/usr/local/afm,${AFMDIR},' \
		-e 's,/usr/local/ind,${INDDIR},' \
		-e 's,/usr/local/info,${INFODIR},' \
		Ted.ad.sample >Ted
	for d in ${WRKSRC}/Ted ${WRKSRC}/appFrame; do \
    	cd $$d && \
		${MV} -f config.h.in config.h.in.bak && \
		${ECHO} '#define PREFIX "${PREFIX}"' >config.h.in && \
		${ECHO} '#define INFODIR "${INFODIR}"' >>config.h.in && \
		${ECHO} '#define INDDIR "${INDDIR}"' >>config.h.in && \
		${ECHO} '#define AFMDIR "${AFMDIR}"' >>config.h.in && \
		${CAT} config.h.in.bak >>config.h.in; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Ted/Ted ${PREFIX}/bin/Ted
	${MKDIR} ${AFMDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/afm/* ${AFMDIR}
	${MKDIR} ${INDDIR}
	${MKDIR} ${INFODIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/info/TedDocument.rtf ${INFODIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/info/Ted ${PREFIX}/lib/X11/app-defaults

.include <bsd.port.mk>
