# Ports collection makefile for:  ted
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ted
PORTVERSION=	2.14
PORTREVISION=	1
CATEGORIES=	editors textproc print
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	j.e.drews@att.net
COMMENT=	X11 based RTF editor

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/Fontmap:${PORTSDIR}/print/gsfonts

WRKSRC=		${WRKDIR}/Ted-${PORTVERSION}
CONFIGURE_WRKSRC=	${WRKSRC}/Ted

USE_X_PREFIX=	yes
USE_MOTIF=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}"
MAKE_ENV=	DEF_AFMDIR="-DAFMDIR=\"\\\"${AFMDIR}\\\"\"" \
		DEF_INDDIR="-DINDDIR=\"\\\"${INDDIR}\\\"\"" \
		DEF_DOCUMENT_DIR="-DDOCUMENT_DIR=\"\\\"${INFODIR}/\\\"\""
ALL_TARGET=	compile.shared

AFMDIR=		${PREFIX}/share/Ted/afm
INDDIR=		${PREFIX}/share/Ted/ind
INFODIR=	${PREFIX}/share/doc/Ted

post-extract:
	cd ${WRKSRC}/tedPackage && ${TAR} xf TedBindist.tar

post-patch:
	${FIND} ${WRKSRC} -name "configure" | ${XARGS} ${REINPLACE_CMD} -e \
		's|/usr/apps|${LOCALBASE}|g ; '
	${REINPLACE_CMD} \
		's|DEF_PKGDIR|DEF_DOCUMENT_DIR|g' ${WRKSRC}/Ted/makefile.in

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
	${INSTALL_DATA} ${WRKSRC}/tedPackage/ind/US_English.ind ${INDDIR}
	@${MKDIR} ${INFODIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/Ted/TedDocument-en_US.rtf ${INFODIR}

.include <bsd.port.mk>
