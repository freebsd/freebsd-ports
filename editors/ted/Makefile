PORTNAME=	ted
DISTVERSION=	2.23
PORTREVISION=	9
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/ \
		https://ftp.nluug.nl/pub/editors/ted/
PKGNAMESUFFIX=	${${FLAVOR} == motif:?:-${FLAVOR}}
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	mce@FreeBSD.org
COMMENT=	X11 based RTF editor
WWW=		https://www.nllgg.nl/Ted/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl.txt

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpaper.so:print/libpaper \
		libpcre.so:devel/pcre \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	gsfonts>0:print/gsfonts

FLAVORS=	motif gtk2
FLAVOR?=	${FLAVORS:[1]}

USES=		ghostscript:x11,run iconv jpeg pkgconfig xorg \
		${${FLAVOR} == motif:?motif:gnome}
USE_GNOME=	${${FLAVOR} == motif:?:gtk20}
USE_XORG=	ice sm x11 xext xft xmu xorgproto xpm xt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/share \
		--with-${${FLAVOR} == motif:?MOTIF:GTK}

MAKE_ENV=	DEF_AFMDIR="-DAFMDIR=\"\\\"${AFMDIR}/\\\"\"" \
		DEF_DOCUMENT_DIR="-DDOCUMENT_DIR=\"\\\"${DOCSDIR}/\\\"\"" \
		DEF_INDDIR="-DINDDIR=\"\\\"${INDDIR}/\\\"\"" \
		DEF_PSSCRIPT_DIR="-DPSSCRIPT_DIR=\"\\\"${DATADIR}/\\\"\""
ALL_TARGET=	compile.shared

CONFLICTS_INSTALL=	${PORTNAME}${${FLAVOR} == motif:?-gtk2:}

DATADIR=	${PREFIX}/share/Ted
DOCSDIR=	${PREFIX}/share/doc/Ted

WRKSRC=		${WRKDIR}/Ted-${DISTVERSION}

AFMDIR=		${DATADIR}/afm
INDDIR=		${DATADIR}/dfa

.include <bsd.port.pre.mk>

post-extract:
	@cd ${WRKSRC}/tedPackage && ${TAR} xf TedDatadir.tar
	@${INSTALL_SCRIPT} ${FILESDIR}/configure ${WRKSRC}

post-patch:
	@${FIND} ${WRKSRC} -name "configure" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		's|/usr/X11R6|${LOCALBASE}|g ; \
		 s|/usr/local|${LOCALBASE}|g ; \
		 /paper.h/s|/usr/include|${LOCALBASE}/include|g ; \
		 /paper.h/s|/usr/lib|${LOCALBASE}/lib|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Ted/Ted ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tedPackage/examples/rtf2*.sh \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/tedPackage/doc/Ted.1 \
		${WRKSRC}/tedPackage/doc/rtf2*.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR} ${STAGEDIR}${AFMDIR} \
		${STAGEDIR}${INDDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/ps/*.ps ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/afm/*.afm ${STAGEDIR}${AFMDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/dfa/*.dfa ${STAGEDIR}${INDDIR}
	${INSTALL_DATA} ${WRKSRC}/tedPackage/TedDocument-en_US.rtf \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
