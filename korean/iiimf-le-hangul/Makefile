# New ports collection makefile for:	iiimf-le-hangul
# Date created:		1 Mar 2005
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	le-hangul
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
CATEGORIES=	korean textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk-src-${IIIMF_VER}

MAINTAINER=	daichi@FreeBSD.org
COMMENT=	IIIMF Hangul input method engine

RUN_DEPENDS=	${LOCALBASE}/lib/im/htt:${PORTSDIR}/textproc/iiimf-server

IIIMF_VER=	r12_1-svn2002
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool
USE_XLIB=	yes
WANT_AUTOCONF_VER=253
WANT_AUTOHEADER_VER=253
WANT_AUTOMAKE_VER=15
WANT_LIBTOOL_VER=15

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}/leif
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME:S/src-//}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=		"It is supported on FreeBSD 5.3 and later"
.endif

.if ${ARCH} != "i386"
IGNORE=	"${ARCH} is not support."
.endif

MAKE_ARGS+=	LIBTOOL="${LIBTOOL} --tag=CXX"
UPDATE_ARGS+=	ACLOCAL=${ACLOCAL} AUTOMAKE=${AUTOMAKE} \
		AUTOHEADER=${AUTOHEADER} AUTOCONF=${AUTOCONF} \
		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE}

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../acfiles/im_common.m4 \
		${WRKSRC}/../lib/CSConv/csconv.h

pre-configure:
	(cd ${WRKSRC}/.. && ${GMAKE} ${UPDATE_ARGS} update-acfiles)
	(cd ${WRKSRC}/../acfiles/ && ${TOUCH} ltconfig)
	(cd ${WRKSRC} && ${TOUCH} ltconfig)

do-configure:
	(cd ${WRKSRC} && ./autogen.sh --prefix=${PREFIX})

.include <bsd.port.post.mk>
