# Ports collection makefile for:  ted
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ted
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	editors textproc print
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/Ted-${PORTVERSION}

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/Ted
CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	--with-MOTIF
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
	${REINPLACE_CMD} -e 's|/usr/apps|${LOCALBASE}|g' ${WRKSRC}/bitmap/configure

post-configure:
.for dir in appFrame appUtil bitmap ind libreg
	cd ${WRKSRC}/${dir} && \
		${SETENV} ${CONFIGURE_ENV} ./configure ${CONFIGURE_ARGS}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Ted/Ted ${PREFIX}/bin
	@${MKDIR} ${AFMDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/afm/* ${AFMDIR}
	@${MKDIR} ${INDDIR}
	@${MKDIR} ${INFODIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/info/TedDocument.rtf ${INFODIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/info/Ted ${PREFIX}/lib/X11/app-defaults

.include <bsd.port.mk>
