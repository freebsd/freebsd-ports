# New ports collection makefile for:	kinput2-wnn4
# Date created:		19 Dec 1997
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kinput2
PORTVERSION=	3.0
PKGNAMESUFFIX=	${INPUT_METHOD}
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.sra.co.jp/pub/x11/kinput2/ 
DISTNAME=	kinput2-v3

MAINTAINER=	taoka@FreeBSD.org

LIB_DEPENDS=	${LIB_INPUT_METHOD}
BUILD_DEPENDS=	${BUILD_INPUT_METHOD}

PATCHDIR=	${.CURDIR}/../kinput2-wnn4/patches
FILESDIR=	${.CURDIR}/../kinput2-wnn4/files
USE_IMAKE=	yes

.if !defined(CANNA) && !defined(SJ3) && !defined(WNN4) && !defined(WNN6)
# For this port
WNN4=			yes
.endif
#
# Specifying a velue INPUT_METHOD, and seting values BUILD_DEPENDS,
# LIB_DEPENDS, etc.
.if defined(CANNA)
INPUT_METHOD+=		canna
LIB_INPUT_METHOD+=	canna16.1:${PORTSDIR}/japanese/Canna
KINPUT2_DEF+=		-DUseCanna -Dport_CANNASRC=${LOCALBASE}/include \
			-Dport_CANNALIB="-L${LOCALBASE}/lib -lcanna16"
.endif
.if defined(SJ3)
INPUT_METHOD+=		sj3
BUILD_INPUT_METHOD+=	sj3serv:${PORTSDIR}/japanese/sj3
KINPUT2_DEF+=		-DUseSj3 -Dport_SJ3SRC=${LOCALBASE}/include \
			-Dport_SJ3LIB="-L${LOCALBASE}/lib -lsj3lib"
.endif
.if defined(WNN4)
INPUT_METHOD+=		wnn4
BUILD_INPUT_METHOD+=	${X11BASE}/lib/libwnn.a:${PORTSDIR}/japanese/Wnn
KINPUT2_DEF+=		-DUseWnn -Dport_WNNINCDIR=$(X11BASE)/include/wnn \
			-Dport_WNNLIB="-L$(X11BASE)/lib -lwnn -lcrypt"
.elif defined(WNN6)
INPUT_METHOD+=		wnn6
LIB_INPUT_METHOD+=	wnn6.1:${PORTSDIR}/japanese/Wnn6-lib
KINPUT2_DEF+=		-DUseWnn -DUseWnn6 -Dport_WNNINCDIR=$(LOCALBASE)/include/wnn \
			-Dport_WNNLIB="-L$(LOCALBASE)/lib -lwnn6 -lcrypt"
.endif
#
# Make a value of INPUT_METHOD
.if defined(INPUT_METHOD)
INPUT_METHOD!=	echo ${INPUT_METHOD} | sed -e 's/^/-/' -e 's/ /+/g'
.endif
#
# Redefine $(IMAKE_CMD) with $(PORT_IMAKE_DEFINES) in ${WRKSRC}/Kinput2.conf
MAKE_ENV+=	 PORT_IMAKE_DEFINES='${KINPUT2_DEF}'

pre-configure:
	if [ -f ${WRKSRC}/Kinput2.conf ]; then \
		${MV} -f ${WRKSRC}/Kinput2.conf ${WRKSRC}/Kinput2.conf.org; \
	fi
	${CP} ${FILESDIR}/Kinput2.conf ${WRKSRC}/Kinput2.conf

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${XMKMF}

post-install:
# For Wnn4 or Wnn6
	@if [ -e ${PKGDIR}/MESSAGE ]; then \
		${CAT} ${PKGDIR}/MESSAGE; \
	fi

.include <bsd.port.mk>
