# New ports collection makefile for:	iiimf-le-newpy
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	le-newpy
PORTVERSION=	${IIIMF_VER:S/_/./g:C/-.*//}
PORTREVISION=	2
CATEGORIES=	chinese textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	im-sdk-src-${IIIMF_VER}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kcwu@csie.org
COMMENT=	IIIMF New PinYin input method engine

RUN_DEPENDS=	${LOCALBASE}/lib/im/htt:${PORTSDIR}/textproc/iiimf-server

IIIMF_VER=	r12_1-svn2002
USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	259
USE_AUTOHEADER_VER=	259
USE_AUTOMAKE_VER=	19
WANT_LIBTOOL_VER=	15

AUTOMAKE_ARGS+=		--add-missing
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}/leif
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME:S/src-//}

.if !defined(WITHOUT_XAUX)
USE_MOTIF=	yes
CFLAGS+=	-I${X11BASE}/include
LDFLAGS+=	-L${X11BASE}/lib
PLIST_SUB+=	WANT_XAUX=""
RUN_DEPENDS+=	${LOCALBASE}/lib/im/csconv/csconv.so:${PORTSDIR}/textproc/iiimf-csconv
.else
CONFIGURE_ARGS+=--without-x
PLIST_SUB+=	WANT_XAUX="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=		"It is supported on FreeBSD 5.3 and later"
.endif

.if ${ARCH} != "i386"
IGNORE=	"${ARCH} is not support."
.endif

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+= LDFLAGS="${LDFLAGS}"
UPDATE_ARGS+=	ACLOCAL=${ACLOCAL} AUTOMAKE=${AUTOMAKE} \
		AUTOHEADER=${AUTOHEADER} AUTOCONF=${AUTOCONF} \
		LIBTOOL=${LIBTOOL} LIBTOOLIZE=${LIBTOOLIZE} \
		ACLOCAL_DIR="-I ${LOCALBASE}/share/aclocal -I ${ACLOCAL_DIR}"

post-patch:
	${REINPLACE_CMD} -e "s,/usr/lib/im,${PREFIX}/lib/im,g" \
		${WRKSRC}/../acfiles/im_common.m4 \
		${WRKSRC}/../lib/CSConv/csconv.h

pre-configure:
	@cd ${WRKSRC}/../ && ${GMAKE} ${UPDATE_ARGS} update-acfiles
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} --force --copy
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${ACLOCAL} \
	 -I ../acfiles -I ${LOCALBASE}/share/aclocal -I ${ACLOCAL_DIR}
	@cd ${WRKSRC} && ${REINPLACE_CMD} \
	 -e "s^\$$ac_aux_dir/ltconfig^${LTCONFIG}^g" \
	 -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
	 -e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
	 ${LIBTOOLFILES}
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOHEADER}

.include <bsd.port.post.mk>
