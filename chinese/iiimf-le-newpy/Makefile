# New ports collection makefile for:	iiimf-le-newpy
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	le-newpy
PORTVERSION=	12.2
PORTREVISION=	1
CATEGORIES=	chinese textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	IIIMF New PinYin input method engine

RUN_DEPENDS=	iiimd:${PORTSDIR}/textproc/iiimf-server

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
WANT_AUTOCONF_VER=	259
WANT_AUTOHEADER_VER=	259
WANT_AUTOMAKE_VER=	19
WANT_LIBTOOL_VER=	15

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/leif

LE_TARGETS=	newpy

.if !defined(WITHOUT_XAUX)
LE_TARGETS+=	newpy/xaux
USE_MOTIF=	yes
CFLAGS+=	-I${X11BASE}/include
LDFLAGS+=	-L${X11BASE}/lib
PLIST_SUB+=	WANT_XAUX=""
.else
PLIST_SUB+=	WANT_XAUX="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=		"It is supported on FreeBSD 5.3 and later"
.endif

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+= CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am \
		${BUILDDIR}/newpy/xaux/aux_win.c \
		${BUILDDIR}/newpy/xaux/aux_so.c

do-configure:
.if defined(WITHOUT_XAUX)
	@cd ${WRKSRC} && \
	 ${REINPLACE_CMD} -e '/^CONFIG_FLAGS =/s,$$, --without-x,' Makefile
.endif
	@cd ${BUILDDIR} && ${REINPLACE_CMD} \
	 -e "/LE_TARGETS=/s,%%LE_TARGETS%%,${LE_TARGETS}," configure.ac
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} reconfig
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

.include <bsd.port.post.mk>
