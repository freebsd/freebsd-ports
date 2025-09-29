PORTNAME=	texmacs
PORTVERSION=	1.99.4
PORTREVISION=	11
CATEGORIES=	editors print
MASTER_SITES=	http://www.texmacs.org/Download/ftp/tmftp/source/
DISTNAME=	TeXmacs-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	WYSIWYG scientific text editor
WWW=		https://www.texmacs.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_13=	Kernel/Containers/hashtree.cpp:97:14: error: no member named 'contains' in 'hashtree<K, V>'

RUN_DEPENDS=	fig2dev:print/transfig

USES=		cpe desktop-file-utils gmake guile:1.8,alias iconv \
		localbase pkgconfig python shared-mime-info shebangfix \
		tex xorg
USE_CXXSTD=	c++14
USE_TEX=	tex:run dvipsk:run
USE_XORG=	x11 xext

SHEBANG_FILES=	plugins/asymptote/bin/* plugins/dratex/bin/* \
		plugins/eukleides/bin/* plugins/feynmf/bin/* \
		plugins/mupad/bin/* plugins/texgraph/bin/* \
		plugins/xypic/bin/* \
		plugins/python/bin/tm_python plugins/sage/bin/tm_sage \
		plugins/mathematica/bin/realpath.py

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-optimize="${CXXFLAGS}" --disable-qt

MAKE_ARGS=	CP="${CP} -R -f"
ALL_TARGET=	${PORTNAME:tu}

DATADIR=	${PREFIX}/share/TeXmacs

OPTIONS_DEFINE=	ASPELL FREETYPE GHOSTSCRIPT IMLIB2 PDF SQLITE
OPTIONS_DEFAULT=ASPELL FREETYPE GHOSTSCRIPT IMLIB2 PDF SQLITE
OPTIONS_SUB=	yes

ASPELL_RUN_DEPENDS=	aspell:textproc/aspell
FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CONFIGURE_ENABLE=	freetype
FREETYPE_CONFIGURE_ENV_OFF=	FREETYPE_CFLAGS=" " FREETYPE_LDFLAGS=" " \
				ac_cv_header_ft2build_h=no
GHOSTSCRIPT_USES=	ghostscript:x11
GHOSTSCRIPT_CONFIGURE_ON=	--with-gs=yes
GHOSTSCRIPT_CONFIGURE_OFF=	--with-gs=no
IMLIB2_LIB_DEPENDS=	libImlib2.so:graphics/imlib2
IMLIB2_CONFIGURE_WITH=	imlib2
PDF_IMPLIES=		FREETYPE GHOSTSCRIPT
PDF_CONFIGURE_ENABLE=	pdf-renderer
PDF_LDFLAGS=		-lz
SQLITE_USES=		sqlite
SQLITE_CONFIGURE_ON=	--with-sqlite3

post-patch:
	@${REINPLACE_CMD} -e \
		'/SVNREV\//s|^|#| ; \
		 s|LIBS="-liconv"|LIBS="-liconv $$LIBS"| ; \
		 s|/-liconv}|}| ; \
		 s|"-Wl,-rpath,"|""| ; \
		 s|\[\[ |[ |g ; \
		 s| \]\]| ]|g ; \
		 s|== no|= no| ; \
		 s|$${QT_PLUGINS_LIST/,/ }|${QT_PLUGINS_LIST}|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		 '/require/s|"python"|"${PYTHON_CMD:T}"|' \
		${WRKSRC}/plugins/python/progs/init-python.scm
	@${REINPLACE_CMD} -e \
		 's|int tab=.*)|int tab)|' \
		${WRKSRC}/src/Kernel/Types/tree.hpp
	@${REINPLACE_CMD} -e \
		 's|int dpi=.*)|int dpi)|' \
		${WRKSRC}/src/Typeset/boxes.hpp

post-install:
	@${FIND} ${STAGEDIR}${DATADIR} -name "._*" -delete
	@${FIND} ${STAGEDIR}${DATADIR} -name "*.bak" -delete
.for f in realpath texmacs.bin tm_axiom tm_graphviz tm_maple_5 tm_r tm_shell
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/TeXmacs/bin/${f}
.endfor

.include <bsd.port.mk>
