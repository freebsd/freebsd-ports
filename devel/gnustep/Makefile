# New ports collection makefile for:    gnustep
# Date created:         03 October 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep
PORTVERSION=	1.1.0
CATEGORIES=	devel lang
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/System/Makefiles/GNUstep.sh:${PORTSDIR}/devel/gnustep-make \
		${SYSLIBDIR}/libobjc.so:${PORTSDIR}/lang/gnustep-objc \
		${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/lang/gnustep-base \
		${COMBOLIBDIR}/libgnustep-gui.so:${PORTSDIR}/x11-toolkits/gnustep-gui \
		${XGPSBUNDLEDIR}/libgnustep-xgps:${PORTSDIR}/x11-toolkits/gnustep-xgps

PREFIX=		${LOCALBASE}/GNUstep
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
BROKEN=		"Sorry, this port does not work on FreeBSD-2.2.x"
.endif

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

SYSLIBDIR=	${PREFIX}/System/Libraries/${GNU_ARCH}/${OPSYS:L}
COMBOLIBDIR=	${SYSLIBDIR}/gnu-gnu-gnu
XGPSBUNDLEDIR=	${PREFIX}/System/Library/Bundles/libgnustep-xgps.bundle/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu/

do-install:	# empty

.include <bsd.port.post.mk>
