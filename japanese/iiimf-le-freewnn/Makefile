# New ports collection makefile for:	iiimf-le-freewnn
# Date created:		18 Feb 2005
# Whom:			Masanori OZAWA <ozawa@ongs.co.jp>
#
# $FreeBSD$
#

PORTNAME=	le-freewnn
PORTVERSION=	12.2
PORTREVISION=	4
CATEGORIES=	japanese textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FreeWnn language engine for IIIMF

LIB_DEPENDS=	wnn.0:${PORTSDIR}/japanese/FreeWnn-lib
RUN_DEPENDS=	iiimd:${PORTSDIR}/textproc/iiimf-server \
		${LOCALBASE}/lib/iiim/csconv/csconv.so:${PORTSDIR}/textproc/iiimf-csconv \
		${LOCALBASE}/bin/Wnn4/jserver:${PORTSDIR}/japanese/FreeWnn-server

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:262:env libtool:22:env

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/leif

CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/wnn \
		${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -liconv ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am \
		${BUILDDIR}/freewnn/freewnn.c
	${REINPLACE_CMD} -e "s,/usr/lib/iiim,${LOCALBASE}/lib/iiim,g" \
		${WRKSRC}/lib/CSConv/csconv.h

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} reconfig
	@${REINPLACE_CMD} -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
			  -e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
		${BUILDDIR}/configure
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

.include <bsd.port.mk>
