# New ports collection makefile for:	KCachegrind
# Date created:				Jun 3 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kcachegrind
PORTVERSION=	0.4.5
CATEGORIES=	devel kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kcachegrind

MAINTAINER=	barner@gmx.de
COMMENT=	Profiling Visualization Tool

BUILD_DEPENDS=	mcopidl:${PORTSDIR}/audio/arts
RUN_DEPENDS=	calltree:${PORTSDIR}/devel/calltree

CONFLICTS=	kdesdk3-[0-9]*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_KDELIBS_VER=3
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
