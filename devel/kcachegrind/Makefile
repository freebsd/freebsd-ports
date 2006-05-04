# New ports collection makefile for:	KCachegrind
# Date created:				Jun 3 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kcachegrind
PORTVERSION=	0.4.5
PORTREVISION=	2
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kcachegrind

MAINTAINER=	barner@FreeBSD.org
COMMENT=	Profiling Visualization Tool

RUN_DEPENDS=	callgrind:${PORTSDIR}/devel/callgrind

ONLY_FOR_ARCHS=	i386
CONFLICTS=	kdesdk3-[0-9]*

USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
USE_KDELIBS_VER=3

OPTIONS=	DOT "Use GraphViz/dot to render call graphs" on

.include <bsd.port.pre.mk>

.if defined (WITH_DOT)
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
