# New ports collection makefile for:   killustrator
# Version required:    0.7.1
# Date created:        07 May 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	killustrator-0.7.1
CATEGORIES=	graphics kde
MASTER_SITES=	http://wwwiti.cs.uni-magdeburg.de/~sattler/pub/killustrator/

MAINTAINER=	jedgar@FreeBSD.org

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		intl.1:${PORTSDIR}/devel/gettext \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
RUN_DEPENDS=	${LOCALBASE}/bin/kdehelp:${PORTSDIR}/x11/kdebase11

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include -L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400004
BROKEN=		"Requires NEWGCC-compiled KDE libs"
.endif

.include <bsd.port.post.mk>
