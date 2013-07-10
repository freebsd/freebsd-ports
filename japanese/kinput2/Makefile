# Created by: Satoshi TAOKA <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kinput2
PORTVERSION=	3.1
PORTREVISION=	13
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/x11/kinput2/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese text input server for X11 applications

MAKE_JOBS_UNSAFE=	yes

USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
SUB_FILES=	Kinput2.conf
PLIST_FILES=	${PLIST_ALL}

MAN1=		kinput2.1

OPTIONS_DEFINE=	CANNA FREEWNN WNN6 WNN7 SJ3 TCP
OPTIONS_DEFAULT=CANNA FREEWNN           SJ3
CANNA_DESC=	Canna support
FREEWNN_DESC=	FreeWnn support
WNN6_DESC=	Wnn6 support
WNN7_DESC=	Wnn7 support
SJ3_DESC=	SJ3 support
TCP_DESC=	TCP transport support (not needed for most cases)

LIB_DEPENDS.CANNA=	canna16.1:${PORTSDIR}/japanese/canna-lib
CONF.CANNA=		'\#define UseCanna' \
			CANNASRC=${LOCALBASE}/include \
			CANNALIB="-L${LOCALBASE}/lib -lcanna16"

LIB_DEPENDS.WNN6=	wnn6.2:${PORTSDIR}/japanese/Wnn6-lib
CONF.WNN6=		'\#define UseWnn' \
			'\#define UseWnn6' \
			WNNINCDIR=$(LOCALBASE)/include/wnn6/wnn \
			WNNLIB="-L$(LOCALBASE)/lib -lwnn6 -lcrypt"

LIB_DEPENDS.WNN7=	wnn7.1:${PORTSDIR}/japanese/Wnn7-lib
CONF.WNN7=		'\#define UseWnn' \
			'\#define UseWnn6' \
			WNNINCDIR=$(LOCALBASE)/include/wnn7/wnn \
			WNNLIB="-L$(LOCALBASE)/lib -lwnn7 -lcrypt"

LIB_DEPENDS.FREEWNN=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
CONF.FREEWNN+=		'\#define UseWnn' \
			WNNINCDIR=$(LOCALBASE)/include/wnn \
			WNNLIB="-L$(LOCALBASE)/lib -lwnn -lcrypt"

LIB_DEPENDS.SJ3=	sj3lib.1:${PORTSDIR}/japanese/sj3-lib
CONF.SJ3+=		'\#define UseSj3' \
			SJ3SRC=${LOCALBASE}/include \
			SJ3LIB="-L${LOCALBASE}/lib -lsj3lib" \
			SJ3DEF_DIR=\$${LIBDIR}/ccdef
PLIST.SJ3=		lib/X11/ccdef/sjhk \
			lib/X11/ccdef/sjrc \
			lib/X11/ccdef/sjrk \
			lib/X11/ccdef/sjsb \
			lib/X11/ccdef/sjzh

PLIST.WNN=		lib/X11/ccdef/ccdef.kinput2 \
			lib/X11/ccdef/rule.eggfunc \
			lib/X11/ccdef/rule.func \
			lib/X11/ccdef/rule.greek \
			lib/X11/ccdef/rule.kana \
			lib/X11/ccdef/rule.kana2 \
			lib/X11/ccdef/rule.roma \
			lib/X11/ccdef/rule.wnnroma \
			lib/X11/ccdef/rule.zascii \
			lib/X11/ccdef/ccdef.kinput2.egg \
			lib/X11/ccdef/rule.hiragana.egg \
			lib/X11/ccdef/rule.katakana.egg \
			lib/X11/ccdef/rule.kigou.egg

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFREEWNN} || \
    ${PORT_OPTIONS:MWNN6} || \
    ${PORT_OPTIONS:MWNN7}
PLIST_ALL+=	${PLIST.WNN}
.endif

.for I in ${OPTIONS_DEFINE:NTCP}
.if ${PORT_OPTIONS:M${I}}
LIB_DEPENDS+=	${LIB_DEPENDS.${I}}
BUILD_DEPENDS+=	${BUILD_DEPENDS.${I}}
CONF+=		${CONF.${I}}
PLIST_ALL+=	${PLIST.${I}}
.endif
.endfor

.if !${PORT_OPTIONS:MTCP}
CONF+=		TRANSPORTDEFS="-DNO_TCP_TRANSPORT"
.endif

pre-configure: apply-slist
	${INSTALL_DATA} ${WRKDIR}/Kinput2.conf ${WRKSRC}/Kinput2.conf
	${PRINTF} "%s\n" ${CONF} > ${WRKSRC}/Kinput2_im.conf

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
