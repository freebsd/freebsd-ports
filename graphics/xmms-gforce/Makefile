# New ports collection makefile for:	xmms-gforce
# Date created:        			22 December 2000
# Whom:					alex
#
# $FreeBSD$
#

PORTNAME=	xmms-gforce
PORTVERSION=	1.1.6.x.p.3
CATEGORIES=	graphics
MASTER_SITES=	http://dl.droso.net/ports/
DISTNAME=	gforce-1.1.6xp3

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

RESTRICTED=	"Non-commercial use only"

.if defined(WANT_DGA)
PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	gforce-1.1.6xp3.dga.patch.gz
PATCH_WRKSRC=	${WRKDIR}
.else
pre-fetch:
	@${ECHO_MSG} "*******************************************************"
	@${ECHO_MSG} "* To compile this port with DGA support (faster),     *"
	@${ECHO_MSG} "* use the WANT_DGA switch.  Be aware that if XMMS or  *"
	@${ECHO_MSG} "* the plugin crashes, your whole X-session will be    *"
	@${ECHO_MSG} "* affected.  You have to run XMMS as root to use DGA. *"
	@${ECHO_MSG} "*******************************************************"
.endif

.include <bsd.port.mk>
