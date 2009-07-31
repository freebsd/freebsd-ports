# Ports collection makefile for:  ted
# Date created:			  23 Aug 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ted
PORTVERSION=	2.20
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 based RTF editor

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts

WRKSRC=		${WRKDIR}/Ted-${PORTVERSION}

USE_MOTIF=	yes
USE_XORG=	xext xft
USE_ICONV=	yes
USE_GHOSTSCRIPT_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-MOTIF
MAKE_ENV=	DEF_AFMDIR="-DAFMDIR=\"\\\"${AFMDIR}/\\\"\"" \
		DEF_INDDIR="-DINDDIR=\"\\\"${INDDIR}/\\\"\"" \
		DEF_DOCUMENT_DIR="-DDOCUMENT_DIR=\"\\\"${DOCSDIR}/\\\"\"" \
		DEF_PSSCRIPT_DIR="-DPSSCRIPT_DIR=\"\\\"${DATADIR}/\\\"\""
ALL_TARGET=	compile.shared

MAN1=		Ted.1 rtf2pdf.1 rtf2ps.1

DATADIR=	${PREFIX}/share/Ted
DOCSDIR=	${PREFIX}/share/doc/Ted

AFMDIR=		${DATADIR}/afm
INDDIR=		${DATADIR}/dfa

post-extract:
	@cd ${WRKSRC}/tedPackage && ${TAR} xf TedBindist.tar
	@${INSTALL_SCRIPT} ${FILESDIR}/configure ${WRKSRC}

post-patch:
	@${FIND} ${WRKSRC} -name "configure" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|/usr/X11R6|${LOCALBASE}|g ; \
		 s|/usr/local|${LOCALBASE}|g ; \
		 s|/iconv.so|/libiconv.so|g'
	@${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g' ${WRKSRC}/appUtil/csvsheet.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Ted/Ted ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tedPackage/Ted/rtf2*.sh ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/tedPackage/Ted/Ted.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/tedPackage/Ted/rtf2*.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR} 
	${INSTALL_DATA} ${WRKSRC}/tedPackage/Ted/*.ps ${DATADIR}
	@${MKDIR} ${AFMDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/Ted/afm/*.afm ${AFMDIR}
	@${MKDIR} ${INDDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/Ted/dfa/*.dfa ${INDDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/Ted/TedDocument-en_US.rtf ${DOCSDIR}
.endif

.include <bsd.port.mk>
