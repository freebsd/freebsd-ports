# New ports collection makefile for:	iiimf-le-newpy
# Date created:		6 Dec 2003
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	le-newpy
PORTVERSION=	12.2
PORTREVISION=	4
CATEGORIES=	chinese textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IIIMF New PinYin input method engine

RUN_DEPENDS=	iiimd:${PORTSDIR}/textproc/iiimf-server

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:262:env libtool:22:env

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/leif

LE_TARGETS=	newpy

.if !defined(WITHOUT_XAUX)
LE_TARGETS+=	newpy/xaux
USE_MOTIF=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PLIST_SUB+=	WANT_XAUX=""
.else
PLIST_SUB+=	WANT_XAUX="@comment "
.endif

.include <bsd.port.pre.mk>

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

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
