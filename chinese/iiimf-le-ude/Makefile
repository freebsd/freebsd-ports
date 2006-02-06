# New ports collection makefile for:	iiimf-le-ude
# Date created:		11 Sep 2004
# Whom:			Kuang-che Wu <kcwu@csie.org>
#
# $FreeBSD$
#

PORTNAME=	le-ude
PORTVERSION=	12.2
PORTREVISION=	1
CATEGORIES=	chinese textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	IIIMF User Defined language Engine for Simplified Chinese conversion

RUN_DEPENDS=	iiimd:${PORTSDIR}/textproc/iiimf-server

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:259:env libtool:15:env
WANT_AUTOHEADER_VER=	259

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/leif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=	is supported on FreeBSD 5.3 and later only
.endif

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am \
		${BUILDDIR}/ude/UDEngine.c

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} reconfig
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

.include <bsd.port.post.mk>
