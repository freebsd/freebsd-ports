# Created by: Satoshi TAOKA <taoka@FreeBSD.org>

PORTNAME=	kinput2
PORTVERSION=	3.1
PORTREVISION=	13
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/x11/kinput2/
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Japanese text input server for X11 applications

MAKE_JOBS_UNSAFE=	yes

USES=		imake xorg
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
SUB_FILES=	Kinput2.conf
PLIST_FILES=	bin/kinput2 lib/X11/app-defaults/Kinput2 man/man1/kinput2.1.gz

OPTIONS_DEFINE=	CANNA FREEWNN WNN6 WNN7 SJ3 TCP
OPTIONS_DEFAULT=CANNA FREEWNN           SJ3
TCP_DESC=		TCP transport support (not needed for most cases)

CANNA_DESC=		Canna support
CANNA_LIB_DEPENDS=	libcanna16.so:japanese/canna-lib
CANNA_CONF=		'\#define UseCanna' \
			CANNASRC=${LOCALBASE}/include \
			CANNALIB="-L${LOCALBASE}/lib -lcanna16"

WNN6_DESC=		Wnn6 support
WNN6_LIB_DEPENDS=	libwnn6.so:japanese/Wnn6-lib
WNN6_CONF=		'\#define UseWnn' \
			'\#define UseWnn6' \
			WNNINCDIR=${LOCALBASE}/include/wnn6/wnn \
			WNNLIB="-L${LOCALBASE}/lib -lwnn6 -lcrypt"
WNN6_PLIST_FILES=	${WNN_PLIST_FILES}

WNN7_DESC=		Wnn7 support
WNN7_LIB_DEPENDS=	libwnn7.so:japanese/Wnn7-lib
WNN7_CONF=		'\#define UseWnn' \
			'\#define UseWnn6' \
			WNNINCDIR=${LOCALBASE}/include/wnn7/wnn \
			WNNLIB="-L${LOCALBASE}/lib -lwnn7 -lcrypt"
WNN7_PLIST_FILES=	${WNN_PLIST_FILES}

FREEWNN_DESC=		FreeWnn support
FREEWNN_LIB_DEPENDS=	libwnn.so:japanese/FreeWnn-lib
FREEWNN_CONF=		'\#define UseWnn' \
			WNNINCDIR=${LOCALBASE}/include/wnn \
			WNNLIB="-L${LOCALBASE}/lib -lwnn -lcrypt"
FREEWNN_PLIST_FILES=	${WNN_PLIST_FILES}

SJ3_DESC=		SJ3 support
SJ3_LIB_DEPENDS=	libsj3lib.so:japanese/sj3-lib
SJ3_CONF=		'\#define UseSj3' \
			SJ3SRC=${LOCALBASE}/include \
			SJ3LIB="-L${LOCALBASE}/lib -lsj3lib" \
			SJ3DEF_DIR=\$${LIBDIR}/ccdef
SJ3_PLIST_FILES=	lib/X11/ccdef/sjhk \
			lib/X11/ccdef/sjrc \
			lib/X11/ccdef/sjrk \
			lib/X11/ccdef/sjsb \
			lib/X11/ccdef/sjzh

WNN_PLIST_FILES=	lib/X11/ccdef/ccdef.kinput2 \
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

.for I in ${OPTIONS_DEFINE:NTCP}
.if ${PORT_OPTIONS:M${I}}
CONF+=		${${I}_CONF}
.endif
.endfor
.if !${PORT_OPTIONS:MTCP}
CONF+=	TRANSPORTDEFS="-DNO_TCP_TRANSPORT"
.endif

pre-configure:
	${INSTALL_DATA} ${WRKDIR}/Kinput2.conf ${WRKSRC}/Kinput2.conf
	${PRINTF} "%s\n" ${CONF} > ${WRKSRC}/Kinput2_im.conf

.include <bsd.port.mk>
