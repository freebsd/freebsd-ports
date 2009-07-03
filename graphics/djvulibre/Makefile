# New ports collection makefile for:	libdjvu++
# Date Created:		20 July 1999
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	djvulibre
PORTVERSION=	3.5.22
PORTREVISION=	0
CATEGORIES=	graphics www
MASTER_SITES=	SF/djvu

MAINTAINER=	stas@FreeBSD.org
COMMENT=	DjVu viewers and browser plugin

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		djvulibre.22:${PORTSDIR}/graphics/djvulibre-nox11

USE_ICONV=	yes
USE_GNOME=	gnomehack gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	JPEG_CFLAGS="-I${LOCALBASE}/include" \
		JPEG_LIBS="-L${LOCALBASE}/lib -ljpeg" \
		TIFF_CFLAGS="-I${LOCALBASE}/include" \
		TIFF_LIBS="-L${LOCALBASE}/lib -ltiff" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		LOCALBASE="${LOCALBASE}" \
		CXX="${CXX}"
CONFIGURE_ARGS=	--enable-threads=pthread --enable-shared
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-gui install-i18n

USE_QT_VER=	3
CONFIGURE_ENV+=	QTLIBS="-L${QT_PREFIX}/lib -lqt-mt"
MANLANG=	"" ja
MAN1=		djview3.1 nsdejavu.1
MLINKS=		djview3.1 djview.1
DESKTOPDIR=	${PREFIX}/share/djvu/djview3/desktop

USE_WEBPLUGINS=		gecko*
WEBPLUGINS_DIR=		${PREFIX}/lib/djvulibre/plugins
WEBPLUGINS_FILES=	nsdejavu.so

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,(SUBDIRS_FIRST[[:space:]]+=[[:space:]]+).*,\1,' \
		-e 's,(SUBDIRS_XML[[:space:]]+=[[:space:]]+).*,\1,' \
		${WRKSRC}/Makefile.in
	@${FIND} ${WRKSRC}/i18n/ -name "Makefile.in" | \
		${XARGS} ${REINPLACE_CMD} -E -e \
		's,(MANFILES[[:space:]]*=[[:space:]]*).*,\1$${MANFILES_GUI},'
	@${REINPLACE_CMD} -E -e \
		's,(LIBDJVU[[:space:]]+=[[:space:]]+).*,\1-ldjvulibre,' \
		${WRKSRC}/gui/djview/Makefile.in \
		${WRKSRC}/gui/bin2cpp/Makefile.in \
		${WRKSRC}/tools/Makefile.in \
		${WRKSRC}/xmltools/Makefile.in
	@${REINPLACE_CMD} -e '/-O\*/d ; \
		 s|$$OPTS -O3|$$OPTS|g ; \
		 s|$$OPTS -O2|$$OPTS|g ; \
		 s|$$OPTS $$opt|$$OPTS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's,/netscape/,/djvulibre/,' \
		 ${WRKSRC}/gui/nsdejavu/nsdejavu.1.in
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|= @CPPFLAGS|= $${FLAGS} @CPPFLAGS|g ; \
		 s|@ $${FLAGS}|@|g ; \
		 s|} $${FLAGS}|}|g ; \
		 s|/netscape/|/djvulibre/|g ; \
		 s|eucjp|eucJP|g ; \
		 s|_PROGRAM} -m|} -m|g'

post-install:
#
# Install desktop files.
#
	${MKDIR} ${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/desktopfiles/djvulibre-djview3.desktop \
		${WRKSRC}/desktopfiles/hi32-djview3.png \
		${DESKTOPDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/desktopfiles/register-djview-menu \
		${DESKTOPDIR}

.include <bsd.port.post.mk>
