# Created by: Satoshi TAOKA <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jvim
PORTVERSION=	3.0.j2.1b
PORTREVISION=	1
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://ftp.vim.org/pub/vim/unix/ \
		http://hp.vector.co.jp/authors/VA003457/vim/vim3/2.1b/
DISTFILES=	vim-3.0.tar.gz jvim.2.1b.tar.gz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanized Vim-3.0

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

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11 FREEWNN_CANNA
OPTIONS_RADIO=	FEP
OPTIONS_RADIO_FEP=	FREEWNN_CANNA DIRECT_CANNA WNN6 WNN7
FEP_DESC=	Japanese FrontEnd Processor
DIRECT_CANNA_DESC=	Canna support (direct)
FREEWNN_CANNA_DESC=	Canna and FreeWnn support (via ONEW library)
WNN6_DESC=	Wnn6 support
WNN7_DESC=	Wnn7 support

PORTDOCS=	cygwin.txt differen.doc fepctrl.doc readme.doc \
		termcap.dos uganda.jp vim-jp.htm vim32.ini tutor.j

CPPFLAGS+=	-DBSD_UNIX -DUSE_LOCALE
LIBS=		-ltermlib -L${PREFIX}/lib

X11_USE=	XORG=x11
X11_CPPFLAGS+=	-DUSE_X11 -I${LOCALBASE}/include

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
LIBS+=	-lX11 -L${LOCALBASE}/lib
.endif

.if ${PORT_OPTIONS:MDIRECT_CANNA} || \
    ${PORT_OPTIONS:MFREEWNN_CANNA} || \
    ${PORT_OPTIONS:MWNN6} || \
    ${PORT_OPTIONS:MWNN7}
FEPOPT+=	-DJP_DEF=\"EEE\" -DFEPCTRL
.endif

#  Direct connection to Canna
DIRECT_CANNA_LIB_DEPENDS+=	libcanna.so:${PORTSDIR}/japanese/canna-lib
.if ${PORT_OPTIONS:MDIRECT_CANNA}
FEPOPT+=	-DCANNA
FEPLIBS=	-lcanna -L${LOCALBASE}/lib
FEPOBJS=	fepcanna.o
JVIM3RC=	"set fepctrl"
.endif

.if ${PORT_OPTIONS:MFREEWNN_CANNA} || \
    ${PORT_OPTIONS:MWNN6} || \
    ${PORT_OPTIONS:MWNN7} || \
    ${PORT_OPTIONS:MCANNA}
FEPOPT+=	-DONEW
FEPOBJS=	feponew.o
JVIM3RC=	"set fepctrl onewredraw"
.endif

# Connection by using ONEW library
FREEWNN_CANNA_LIB_DEPENDS=	libjd.so:${PORTSDIR}/japanese/FreeWnn-lib \
				libcanna.so:${PORTSDIR}/japanese/canna-lib
FREEWNN_CANNA_BUILD_DEPENDS=	${LOCALBASE}/lib/libonew-canna+freewnn.a:${PORTSDIR}/japanese/onew
.if ${PORT_OPTIONS:MFREEWNN_CANNA}
FEPLIBS+=	-lonew-canna+freewnn -lcanna -ljd -lcrypt
.endif

WNN6_LIB_DEPENDS=	libjd.so:${PORTSDIR}/japanese/FreeWnn-lib
WNN6_BUILD_DEPENDS=	${LOCALBASE}/lib/libonew-wnn6.a:${PORTSDIR}/japanese/onew
.if ${PORT_OPTIONS:MWNN6}
FEPLIBS+=	-lonew-wnn6 -ljd -lcrypt
.endif

WNN7_LIB_DEPENDS=	libjd.so:${PORTSDIR}/japanese/FreeWnn-lib
WNN7_BUILD_DEPENDS=	${LOCALBASE}/lib/libonew-wnn7.a:${PORTSDIR}/japanese/onew
.if ${PORT_OPTIONS:MWNN7}
FEPLIBS+=	-lonew-wnn7 -ljd -lcrypt
.endif

post-build:
	${CP} ${WRKSRC}/doc.j/tutor/tutor.j ${WRKSRC}/doc.j

post-install:
	${LN} -sf jvim3 ${STAGEDIR}${PREFIX}/bin/jvim
	${INSTALL_PROGRAM} ${WRKSRC}/src/grep/grep \
	    ${STAGEDIR}${PREFIX}/bin/jgrep
	${ECHO_CMD} "${JVIM3RC}" > ${WRKSRC}/jvim3rc.dist
	${INSTALL_DATA} ${WRKSRC}/jvim3rc.dist ${STAGEDIR}${PREFIX}/etc/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc.j && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
