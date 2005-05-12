# New ports collection makefile for:	L-Breeder
# Date created:				30 May 2002
# Whom:					David Yeske <dyeske@yahoo.com> et al
#
# $FreeBSD$
#

PORTNAME=	L-Breeder
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	biology
MASTER_SITES=	http://pixie.oum.ox.ac.uk/L-Breeder/
DISTNAME=	LBreeder
EXTRACT_SUFX=	.tgz

MAINTAINER=	dyeske@yahoo.com
COMMENT=	Allows you to display and breed L-system forms

LIB_DEPENDS=	wx_gtk2_gl-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24

WRKSRC=		${WRKDIR}/LBreeder/LBreeder
PATCH_WRKSRC=	${WRKDIR}/LBreeder
PLIST_FILES=	bin/L-Breeder

USE_X_PREFIX=	yes
USE_GL=		yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

WX_CONFIG=	${X11BASE}/bin/wxgtk2-2.4-config

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

post-patch:
	@${FIND} ${WRKDIR} -type f -name Makefile | \
		${XARGS} -n 10 ${REINPLACE_CMD} -E -e \
		's|/usr/lib/libm.a||; \
		s|-ldl||; \
		s|-lgtk||; \
		s|-lgmodule||; \
		s|-lpthread||; \
		s|-lgthread||; \
		s|/usr/lib/libGL.a|-lGL|; \
		s|/usr/lib/libGLU.so|-lGLU|; \
		s|-O2|"${CFLAGS} ${PTHREAD_CFLAGS}"|; \
		s|-lglib||; \
		s|g\+\+|${CXX} -I${X11BASE}/include|; \
		s|-lgdk||; \
		s|wx-config|${WX_CONFIG}|; \
		s|-lwx_gtk[[:space:]]|`${WX_CONFIG} --libs`|; \
		s|-lwx_gtk_gl|-lwx_gtk2_gl-2.4|'

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/L-Breeder ${PREFIX}/bin

.include <bsd.port.mk>
