# New ports collection makefile for:    gnustep
# Date created:         03 October 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep
PORTVERSION=	1.5.1
CATEGORIES=	devel lang
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	dinoex@FreeBSD.org

RUN_DEPENDS=	${SYSTEMDIR}/Makefiles/GNUstep.sh:${PORTSDIR}/devel/gnustep-make
RUN_DEPENDS+=	${SYSLIBDIR}/libobjc.so:${PORTSDIR}/lang/gnustep-objc
RUN_DEPENDS+=	${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/lang/gnustep-base
RUN_DEPENDS+=	${COMBOLIBDIR}/libgnustep-gui.so:${PORTSDIR}/x11-toolkits/gnustep-gui-devel
RUN_DEPENDS+=	${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/x11-toolkits/gnustep-back

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

SYSTEMDIR=	${LOCALBASE}/GNUstep/System
SYSLIBDIR=	${SYSTEMDIR}/Libraries/${GNU_ARCH}/${OPSYS:L}
COMBOLIBDIR=	${SYSLIBDIR}/gnu-gnu-gnu
BACKBUNDLEDIR=	${SYSTEMDIR}/Library/Bundles/libgnustep-back.bundle/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu/

do-install:	# empty

.include <bsd.port.post.mk>
