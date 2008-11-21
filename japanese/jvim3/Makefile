# New ports collection makefile for:    jvim3
# Date created:         98/11/17
# Whom:                 Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jvim
PORTVERSION=	3.0.j2.1a
PORTREVISION=	4
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://ftp.vim.org/pub/vim/unix/ \
		http://hp.vector.co.jp/authors/VA003457/vim/vim3/2.1a/
DISTFILES=	vim-3.0.tar.gz jvim.2.1a.tar.gz

MAINTAINER=	ports@FreeBSD.org
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
		MACHINE="${MACHINE}" \
		CC="${CC}" \
		LIBS="${LIBS}"

MAN1=		jvim3.1

OPTIONS=	X11	"X11 support"				on \
		CANNA	"Canna support (via ONEW library)"	on \
		DIRECT_CANNA	"Canna support (direct)"	off \
		FREEWNN	"FreeWnn support (via ONEW library)"	on \
		WNN6	"Wnn6 support"				off \
		WNN7	"Wnn7 support"				off

PORTDOCS=	cygwin.txt differen.doc fepctrl.doc readme.doc \
		termcap.dos uganda.jp vim-jp.htm vim32.ini tutor.j

# -DUSE_X11 is the cause of a problem treating Japanese
MACHINE=	-DBSD_UNIX -DUSE_LOCALE
LIBS=		-ltermlib -L${PREFIX}/lib

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_X11)
USE_XORG=	x11
MACHINE+=	-DUSE_X11
CC+=		-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11
.endif

#  Direct connection to Canna
.if !defined(WITHOUT_DIRECT_CANNA)
INPUT_METHOD+=	direct_canna
LIB_DEPENDS+=	canna.1:${PORTSDIR}/japanese/canna-lib
FEPOPT+=	-DJP_DEF=\"EEE\" -DCANNA -DFEPCTRL
FEPLIBS=	-lcanna
FEPOBJS=	fepcanna.o
JVIM3RC=	"set fepctrl"
.else # !WITHOUT_DIRECT_CANNA

# Connection by using ONEW library
.if !defined(WITHOUT_CANNA)
INPUT_METHOD+=	canna
LIB_DEPENDS+=	canna.1:${PORTSDIR}/japanese/canna-lib
FEPLIBS+=	-L${LOCALBASE}/lib -lonew-canna -lcanna
FEPOPT+=	-DJP_DEF=\"EEE\" -DONEW -DFEPCTRL
FEPOBJS=	feponew.o
JVIM3RC=	"set fepctrl onewredraw"
.endif

.if !defined(WITHOUT_FREEWNN)
LIB_DEPENDS+=	jd.0:${PORTSDIR}/japanese/FreeWnn-lib
BUILD_DEPENDS+=	${LOCALBASE}/lib/libonew-freewnn.a:${PORTSDIR}/japanese/onew
FEPLIBS+=	-L${LOCALBASE}/lib -lonew-freewnn -ljd -lcrypt
FEPOPT+=	-DJP_DEF=\"EEE\" -DONEW -DFEPCTRL
FEPOBJS=	feponew.o
JVIM3RC=	"set fepctrl onewredraw"
.endif

.if !defined(WITHOUT_WNN6)
LIB_DEPENDS+=	jd.0:${PORTSDIR}/japanese/FreeWnn-lib
BUILD_DEPENDS+=	${LOCALBASE}/lib/libonew-wnn6.a:${PORTSDIR}/japanese/onew
FEPLIBS+=	-L${LOCALBASE}/lib -lonew-wnn6 -ljd -lcrypt
FEPOPT+=	-DJP_DEF=\"EEE\" -DONEW -DFEPCTRL
FEPOBJS=	feponew.o
JVIM3RC=	"set fepctrl onewredraw"
.endif

.if !defined(WITHOUT_WNN7)
LIB_DEPENDS+=	jd.0:${PORTSDIR}/japanese/FreeWnn-lib
BUILD_DEPENDS+=	${LOCALBASE}/lib/libonew-wnn7.a:${PORTSDIR}/japanese/onew
FEPLIBS+=	-L${LOCALBASE}/lib -lonew-wnn7 -ljd -lcrypt
FEPOPT+=	-DJP_DEF=\"EEE\" -DONEW -DFEPCTRL
FEPOBJS=	feponew.o
JVIM3RC=	"set fepctrl onewredraw"
.endif
.endif # !WITHOUT_DIRECT_CANNA

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
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc.j && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
