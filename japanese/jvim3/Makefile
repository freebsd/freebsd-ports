# Created by: Satoshi TAOKA <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jvim
PORTVERSION=	3.0.j2.1b
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

MAN1=		jvim3.1

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11 FREEWNN
OPTIONS_RADIO=	FEP
OPTIONS_RADIO_FEP=	CANNA DIRECT_CANNA WNN6 WNN7 FREEWNN
FEP_DESC=	Japanese FrontEnd Processor
CANNA_DESC=	Canna support (via ONEW library)
DIRECT_CANNA_DESC=	Canna support (direct)
FREEWNN_DESC=	FreeWnn support (via ONEW library)
WNN6_DESC=	Wnn6 support
WNN7_DESC=	Wnn7 support

PORTDOCS=	cygwin.txt differen.doc fepctrl.doc readme.doc \
		termcap.dos uganda.jp vim-jp.htm vim32.ini tutor.j

# -DUSE_X11 is the cause of a problem treating Japanese
CPPFLAGS+=	-DBSD_UNIX -DUSE_LOCALE
LIBS=		-ltermlib -L${PREFIX}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11
CPPFLAGS+=	-DUSE_X11 -I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11
.endif

.if ${PORT_OPTIONS:MDIRECT_CANNA} || \
    ${PORT_OPTIONS:MCANNA} || \
    ${PORT_OPTIONS:MFREEWNN} || \
    ${PORT_OPTIONS:MWNN6} || \
    ${PORT_OPTIONS:MWNN7}
FEPOPT+=	-DJP_DEF=\"EEE\" -DFEPCTRL
.endif

#  Direct connection to Canna
.if ${PORT_OPTIONS:MDIRECT_CANNA}
LIB_DEPENDS+=	canna.1:${PORTSDIR}/japanese/canna-lib
FEPOPT+=	-DCANNA
FEPLIBS=	-lcanna -L${LOCALBASE}/lib
FEPOBJS=	fepcanna.o
JVIM3RC=	"set fepctrl"
.endif

.if ${PORT_OPTIONS:MFREEWNN} || \
    ${PORT_OPTIONS:MWNN6} || \
    ${PORT_OPTIONS:MWNN7} || \
    ${PORT_OPTIONS:MCANNA}
FEPOPT+=	-DONEW
FEPOBJS=	feponew.o
JVIM3RC=	"set fepctrl onewredraw"
.endif

# Connection by using ONEW library
.if ${PORT_OPTIONS:MCANNA}
LIB_DEPENDS+=	canna.1:${PORTSDIR}/japanese/canna-lib
BUILD_DEPENDS+=	${LOCALBASE}/lib/libonew-canna.a:${PORTSDIR}/japanese/onew
FEPLIBS+=	-lonew-canna -lcanna
.endif

.if ${PORT_OPTIONS:MFREEWNN}
LIB_DEPENDS+=	jd.0:${PORTSDIR}/japanese/FreeWnn-lib
BUILD_DEPENDS+=	${LOCALBASE}/lib/libonew-freewnn.a:${PORTSDIR}/japanese/onew
FEPLIBS+=	-lonew-freewnn -ljd -lcrypt
.endif

.if ${PORT_OPTIONS:MWNN6}
LIB_DEPENDS+=	jd.0:${PORTSDIR}/japanese/FreeWnn-lib
BUILD_DEPENDS+=	${LOCALBASE}/lib/libonew-wnn6.a:${PORTSDIR}/japanese/onew
FEPLIBS+=	-lonew-wnn6 -ljd -lcrypt
.endif

.if ${PORT_OPTIONS:MWNN7}
LIB_DEPENDS+=	jd.0:${PORTSDIR}/japanese/FreeWnn-lib
BUILD_DEPENDS+=	${LOCALBASE}/lib/libonew-wnn7.a:${PORTSDIR}/japanese/onew
FEPLIBS+=	-lonew-wnn7 -ljd -lcrypt
.endif

post-build:
	${CP} ${WRKSRC}/doc.j/tutor/tutor.j ${WRKSRC}/doc.j

post-install:
	${LN} -sf ${PREFIX}/bin/jvim3 ${PREFIX}/bin/jvim
	${INSTALL_PROGRAM} ${WRKSRC}/src/grep/grep ${PREFIX}/bin/jgrep
	${ECHO_CMD} "${JVIM3RC}" > ${WRKSRC}/jvim3rc.dist
	${INSTALL_DATA} ${WRKSRC}/jvim3rc.dist ${PREFIX}/etc/
.if !exists(${PREFIX}/etc/jvim3rc)
	${INSTALL_DATA} ${PREFIX}/etc/jvim3rc.dist ${PREFIX}/etc/jvim3rc
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc.j && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
