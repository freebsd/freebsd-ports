PORTNAME=	jvim
PORTVERSION=	3.0.j2.1b
PORTREVISION=	4
CATEGORIES=	japanese editors
MASTER_SITES=	https://ftp.st.ryukoku.ac.jp/pub/editor/vim/unix/:vim \
		https://ftp.st.ryukoku.ac.jp/pub/editor/jvim/jvim3/2.1b/:jvim \
		http://ftp.fwnet.jp/:vim http://ftp.fwnet.jp/:jvim
DISTFILES=	vim-3.0.tar.gz:vim jvim.2.1b.tar.gz:jvim

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Japanized Vim-3.0
WWW=		https://ftp.st.ryukoku.ac.jp/pub/editor/jvim/jvim3/vim.html

USES=		localbase

MAKEFILE=	makjunix.mak

CPPFLAGS+=	-DBSD_UNIX -DUSE_LOCALE
LIBS+=		-ltermlib

EXTRA_PATCHES=	${WRKDIR}/${PORTNAME}.diff

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src
WRKSRC=		${WRKDIR}/vim

PORTDOCS=	differen.doc fepctrl.doc readme.doc termcap.dos tutor.j \
		uganda.jp

OPTIONS_DEFINE=		CANNA DOCS X11
OPTIONS_DEFAULT=	X11

CANNA_DESC=		Canna support
CANNA_LIB_DEPENDS=	libcanna.so:japanese/canna-lib
CANNA_MAKE_ARGS=	FEPLIBS=-lcanna \
			FEPOBJS=fepcanna.o \
			FEPOPT='-DJP_DEF=\"EEE\" -DFEPCTRL -DCANNA'
CANNA_VARS=		JVIM3RC="set fepctrl"

X11_USES=	xorg
X11_USE=	XORG=x11,xorgproto
X11_CPPFLAGS=	-DUSE_X11
X11_LIBS=	-lX11

post-build:
	${ECHO_CMD} "${JVIM3RC}" > ${WRKSRC}/jvim3rc.dist

post-install:
	${RLN} jvim3 ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/src/grep.bin ${STAGEDIR}${PREFIX}/bin/jgrep
	${INSTALL_DATA} ${WRKSRC}/jvim3rc.dist ${STAGEDIR}${PREFIX}/etc/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc.j && ${INSTALL_DATA} \
		${PORTDOCS:S,tutor.j,tutor/tutor.j,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
