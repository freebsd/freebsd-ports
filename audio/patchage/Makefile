# New ports collection makefile for:	patchage
# Date created:		2008-07-22
# Whom:			Edward Tomasz Napierala <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	patchage
PORTVERSION=	0.4.2
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modular patch bay for Jack

LIB_DEPENDS=	boost_date_time.4:${PORTSDIR}/devel/boost-libs \
		glibmm-2.4.1:${PORTSDIR}/devel/glibmm \
		glademm-2.4:${PORTSDIR}/devel/libglademm24 \
		raul.2:${PORTSDIR}/audio/raul \
		flowcanvas.2:${PORTSDIR}/x11-toolkits/flowcanvas

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	"CXXFLAGS=${CFLAGS} -I${LOCALBASE}/include"
INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900027
BROKEN=		does not build on 9.X after log2 addition
.endif

.include <bsd.port.post.mk>
