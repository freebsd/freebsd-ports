PORTNAME=	jvim
PORTVERSION=	3.0.j2.1b
PORTREVISION=	3
CATEGORIES=	japanese editors
MASTER_SITES=	https://ftp.st.ryukoku.ac.jp/pub/editor/vim/unix/:vim \
		https://ftp.st.ryukoku.ac.jp/pub/editor/jvim/jvim3/2.1b/:jvim
DISTFILES=	vim-3.0.tar.gz:vim jvim.2.1b.tar.gz:jvim

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanized Vim-3.0
WWW=		https://ftp.st.ryukoku.ac.jp/pub/editor/jvim/jvim3/vim.html

EXTRA_PATCHES=	${WRKDIR}/${PORTNAME}.diff
WRKSRC=		${WRKDIR}/vim
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src
MAKEFILE=	makjunix.mak
ALL_TARGET=	# empty
PLIST_SUB=	VERSION=${PORTVERSION}
MAKE_ARGS=	FEPOPT='${FEPOPT}' \
		FEPLIBS="${FEPLIBS}" \
		FEPOBJS="${FEPOBJS}" \
		LIBS="${LIBS}"

OPTIONS_DEFINE=	DIRECT_CANNA DOCS X11
OPTIONS_DEFAULT=X11
DIRECT_CANNA_DESC=	Canna support (direct)
DIRECT_CANNA_LIB_DEPENDS=	libcanna.so:japanese/canna-lib

PORTDOCS=	cygwin.txt differen.doc fepctrl.doc readme.doc \
		termcap.dos uganda.jp vim-jp.htm vim32.ini tutor.j

CPPFLAGS+=	-DBSD_UNIX -DUSE_LOCALE
LIBS+=		-ltermlib -L${LOCALBASE}/lib

X11_USES=	xorg
X11_USE=	XORG=x11
X11_CPPFLAGS=	-DUSE_X11 -I${LOCALBASE}/include
X11_LIBS=	-lX11 -L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDIRECT_CANNA}
FEPOPT=		-DJP_DEF=\"EEE\" -DFEPCTRL -DCANNA
FEPLIBS=	-lcanna -L${LOCALBASE}/lib
FEPOBJS=	fepcanna.o
JVIM3RC=	"set fepctrl"
.endif

post-build:
	${INSTALL_DATA} ${WRKSRC}/doc.j/tutor/tutor.j ${WRKSRC}/doc.j
	${ECHO_CMD} "${JVIM3RC}" > ${WRKSRC}/jvim3rc.dist

post-install:
	${LN} -sf jvim3 ${STAGEDIR}${PREFIX}/bin/jvim
	${INSTALL_PROGRAM} ${WRKSRC}/src/grep.bin ${STAGEDIR}${PREFIX}/bin/jgrep
	${INSTALL_DATA} ${WRKSRC}/jvim3rc.dist ${STAGEDIR}${PREFIX}/etc/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc.j && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
