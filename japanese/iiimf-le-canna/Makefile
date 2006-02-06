# New ports collection makefile for:	iiimf-le-canna
# Date created:		18 Feb 2005
# Whom:			Masanori OZAWA <ozawa@ongs.co.jp>
#
# $FreeBSD$
#

PORTNAME=	le-canna
PORTVERSION=	12.2
PORTREVISION=	1
CATEGORIES=	japanese textproc
MASTER_SITES=	http://www.openi18n.org/download/im-sdk/src/
PKGNAMEPREFIX=	iiimf-
DISTNAME=	iiimf-src-${PORTVERSION}

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	Canna language engine for IIIMF

LIB_DEPENDS=	canna16.1:${PORTSDIR}/japanese/Canna
RUN_DEPENDS=	iiimd:${PORTSDIR}/textproc/iiimf-server \
		${LOCALBASE}/lib/iiim/csconv/csconv.so:${PORTSDIR}/textproc/iiimf-csconv

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_XLIB=	yes
USE_AUTOTOOLS=	automake:19:env autoconf:259:env libtool:15:env
WANT_AUTOHEADER_VER=	259

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}
BUILDDIR=	${WRKSRC}/leif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=	is supported on FreeBSD 5.3 and later only
.endif

CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -L${X11BASE}/lib -liconv ${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-patch:
	${REINPLACE_CMD} \
		-e "s,%%LOCALBASE%%,${LOCALBASE},g" \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/Makefile ${BUILDDIR}/Makefile.am
	${REINPLACE_CMD} -e "s,/usr/lib/iiim,${LOCALBASE}/lib/iiim,g" \
		${WRKSRC}/lib/CSConv/csconv.h

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${GMAKE} reconfig
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} config

.include <bsd.port.post.mk>
