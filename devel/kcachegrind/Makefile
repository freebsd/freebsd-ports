# New ports collection makefile for:	KCachegrind
# Date created:				Jun 3 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kcachegrind
PORTVERSION=	0.4.6
PORTREVISION=	4
CATEGORIES=	devel kde
MASTER_SITES=	SF/${PORTNAME}/KCachegrind/KCachegrind%20${PORTVERSION}

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Profiling Visualization Tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	i386 amd64
CONFLICTS=	kdesdk3-[0-9]*

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_KDELIBS_VER=3
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes

OPTIONS=	DOT "Use GraphViz/dot to render call graphs" on \
		VALGRIND "Install devel/valgrind" off

.include <bsd.port.pre.mk>

.if defined (WITH_DOT)
RUN_DEPENDS+=	dot:${PORTSDIR}/graphics/graphviz
.endif

.if defined (WITH_VALGRIND)
RUN_DEPENDS+=	valgrind:${PORTSDIR}/devel/valgrind
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g' -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
