# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ted
PORTVERSION=	2.23
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		http://fossies.org/linux/misc/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	X11 based RTF editor

LICENSE=	GPLv2

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		paper:${PORTSDIR}/print/libpaper
RUN_DEPENDS=	gsfonts>0:${PORTSDIR}/print/gsfonts

OPTIONS_DEFINE=	GTK2 DOCS
GTK2_DESC=	Use GTK2 instead of MOTIF

WRKSRC=		${WRKDIR}/Ted-${PORTVERSION}

USE_XORG=	xext xft
USES=		iconv
USE_GHOSTSCRIPT_RUN=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include/libpng15
MAKE_ENV=	DEF_AFMDIR="-DAFMDIR=\"\\\"${AFMDIR}/\\\"\"" \
		DEF_INDDIR="-DINDDIR=\"\\\"${INDDIR}/\\\"\"" \
		DEF_DOCUMENT_DIR="-DDOCUMENT_DIR=\"\\\"${DOCSDIR}/\\\"\"" \
		DEF_PSSCRIPT_DIR="-DPSSCRIPT_DIR=\"\\\"${DATADIR}/\\\"\""
ALL_TARGET=	compile.shared
MAKE_JOBS_SAFE=	yes

MAN1=		Ted.1 rtf2pdf.1 rtf2ps.1

DATADIR=	${PREFIX}/share/Ted
DOCSDIR=	${PREFIX}/share/doc/Ted

AFMDIR=		${DATADIR}/afm
INDDIR=		${DATADIR}/dfa

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME=	gtk20
CONFIGURE_ARGS+=--with-GTK
.else
USES+=		motif
CONFIGURE_ARGS+=--with-MOTIF
.endif

post-extract:
	@cd ${WRKSRC}/tedPackage && ${TAR} xf TedDatadir.tar
	@${INSTALL_SCRIPT} ${FILESDIR}/configure ${WRKSRC}

post-patch:
	@${FIND} ${WRKSRC} -name "configure" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|/usr/X11R6|${LOCALBASE}|g ; \
		 s|/usr/local|${LOCALBASE}|g ; \
		 /paper.h/s|/usr/include|${LOCALBASE}/include|g ; \
		 /paper.h/s|/usr/lib|${LOCALBASE}/lib|g ; \
		 s|/iconv.so|/libiconv.so|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Ted/Ted ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tedPackage/examples/rtf2*.sh ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/tedPackage/doc/Ted.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/tedPackage/doc/rtf2*.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/ps/*.ps ${DATADIR}
	@${MKDIR} ${AFMDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/afm/*.afm ${AFMDIR}
	@${MKDIR} ${INDDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/dfa/*.dfa ${INDDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/TedDocument-en_US.rtf ${DOCSDIR}
.endif

.include <bsd.port.mk>
