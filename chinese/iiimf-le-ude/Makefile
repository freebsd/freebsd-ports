# New ports collection makefile for:	iiimf-le-ude
# Date created:		11 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	le-ude
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	chinese textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk-src-${IIIMF_VER}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kcwu@csie.org
COMMENT=	IIIMF User Defined language Engine for Simplified Chinese conversion

RUN_DEPENDS=	${LOCALBASE}/lib/im/htt:${PORTSDIR}/textproc/iiimf-server

IIIMF_VER=	r12_1-svn2002
USE_REINPLACE=	yes
USE_GMAKE=      yes
USE_GNOME=      intltool
WANT_AUTOCONF_VER=253
WANT_AUTOHEADER_VER=253
WANT_AUTOMAKE_VER=15
WANT_LIBTOOL_VER=15

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}/leif
BUILD_WRKSRC=	${WRKSRC}/ude
INSTALL_WRKSRC=	${WRKSRC}/ude
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME:S/src-//}

MAKE_ARGS+=	LIBTOOL="${LIBTOOL} --tag=CXX"
UPDATE_ARGS+=	ACLOCAL=${ACLOCAL} AUTOMAKE=${AUTOMAKE} \
		AUTOHEADER=${AUTOHEADER} AUTOCONF=${AUTOCONF} \
		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE}
AUTOGEN_ARGS+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib" \
		--prefix=${PREFIX}

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../acfiles/im_common.m4

pre-configure:
	(cd ${WRKSRC}/../ && ${GMAKE} ${UPDATE_ARGS} update-acfiles)
	(cd ${WRKSRC}/../acfiles/ && ${TOUCH} ltconfig)
	(cd ${WRKSRC}/ && ${TOUCH} ltconfig)

do-configure:
	(cd ${WRKSRC}/ && ./autogen.sh ${AUTOGEN_ARGS})

.include <bsd.port.mk>
