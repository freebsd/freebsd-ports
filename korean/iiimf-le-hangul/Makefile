# New ports collection makefile for:	iiimf-le-hangul
# Date created:		1 Mar 2005
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	le-hangul
PORTVERSION=	12.2
PORTREVISION=	5
CATEGORIES=	korean textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IIIMF Hangul input method engine

RUN_DEPENDS=	iiimd:${PORTSDIR}/textproc/iiimf-server

ONLY_FOR_ARCHS=	i386

USE_XORG=	x11
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:262:env libtool:22:env

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/leif

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am

pre-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} reconfig
	@${REINPLACE_CMD} -e "/^ltmain=/!s^\$$ac_aux_dir/ltmain.sh^${LIBTOOLFLAGS} ${LTMAIN}^g" \
			  -e '/^LIBTOOL=/s^\$$(top_builddir)/libtool^${LIBTOOL}^g' \
		${BUILDDIR}/configure
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

.include <bsd.port.mk>
