# New ports collection makefile for:	calf
# Date created:		2009-08-26
# Whom:			 <trasz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	calf
PORTVERSION=	0.0.18.5
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Calf audio plugin pack

LIB_DEPENDS=	dssialsacompat.0:${PORTSDIR}/audio/libdssialsacompat \
		lo.7:${PORTSDIR}/audio/liblo \
		jack.0:${PORTSDIR}/audio/jack \
		lash.2:${PORTSDIR}/audio/lash
BUILD_DEPENDS=	${LOCALBASE}/include/dssi.h:${PORTSDIR}/audio/dssi \
		${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libglade2
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/dssi -L${LOCALBASE}/lib
MAN1=		calfjackhost.1
MAN7=		calf.7
INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		Does not compile
.endif

post-patch:
		@${FIND} ${BUILD_WRKSRC} -name '*.cpp' | ${XARGS} \
			${REINPLACE_CMD} -e "s|<malloc.h>|<stdlib.h>|g"

.include <bsd.port.post.mk>
