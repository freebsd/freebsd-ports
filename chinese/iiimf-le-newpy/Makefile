# New ports collection makefile for:	iiimf-le-newpy
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	le-newpy
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	chinese textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk
DISTFILES=	${DISTNAME}-src-${IIIMF_VER}.tgz

MAINTAINER=	kcwu@csie.org
COMMENT=	IIIMF New PinYin input method engine

RUN_DEPENDS=	${LOCALBASE}/lib/im/htt:${PORTSDIR}/textproc/iiimf-server

IIIMF_VER=	r12_0_1-svn1891
WRKSRC=		${WRKDIR}/${DISTNAME}-${IIIMF_VER}/leif
BUILD_WRKSRC=	${WRKSRC}/newpy
INSTALL_WRKSRC=	${WRKSRC}/newpy
USE_REINPLACE=	yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
USE_LIBTOOL_VER=	15
AUTOMAKE_ARGS+=	--add-missing --copy --gnu
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.if !defined(WITHOUT_XAUX)
USE_MOTIF=	yes
PLIST_SUB+=	WANT_XAUX=""
RUN_DEPENDS+=	${LOCALBASE}/csconv/csconv.so:${PORTSDIR}/textproc/iiimf-csconv
.else
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	WANT_XAUX="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../acfiles/im_common.m4 \
		${WRKSRC}/configure.ac \
		${WRKSRC}/newpy/NewPY.c \
		${WRKSRC}/newpy/xaux/aux_so.c \
		${WRKSRC}/newpy/xaux/aux_win.c

pre-configure:
	cd ${WRKSRC} && ${ACLOCAL} -I ${LOCALBASE}/share/aclocal -I ../acfiles
	${TOUCH} ${WRKSRC}/config.h.in
	cd ${WRKSRC} && ${LIBTOOLIZE} --copy --force --automake

.if !defined(WITHOUT_XAUX)
post-build:
	cd ${BUILD_WRKSRC}/xaux && ${MAKE} all

post-install:
	cd ${INSTALL_WRKSRC}/xaux && ${MAKE} install
.endif

.include <bsd.port.mk>
