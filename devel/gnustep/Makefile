# New ports collection makefile for:    gnustep
# Date created:         03 October 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep
.if defined(WITH_GNUSTEP_DEVEL)
PORTVERSION=	1.7.0
.else
PORTVERSION=	1.6.0
.endif
CATEGORIES=	devel lang
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Objective-C libraries based on the OpenStep standard

RUN_DEPENDS+=	${SYSMAKEDIR}/GNUstep.sh:${PORTSDIR}/devel/gnustep-make
RUN_DEPENDS+=	${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/lang/gnustep-base
RUN_DEPENDS+=	${COMBOLIBDIR}/libgnustep-gui.so:${PORTSDIR}/x11-toolkits/gnustep-gui
RUN_DEPENDS+=	${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/x11-toolkits/gnustep-back

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
NO_BUILD=	yes
SYSTEMDIR=	${PREFIX}/System
SYSMAKEDIR=	${SYSTEMDIR}/Makefiles
COMBOLIBDIR=	${SYSLIBDIR}/gnu-gnu-gnu
BUNDLEDIR=	${SYSTEMDIR}/Library/Bundles

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

.if defined(WITH_GNUSTEP_DEVEL)
SYSLIBDIR=	${SYSTEMDIR}/Library/Libraries/${GNU_ARCH}/${OPSYS:L}
.else
SYSLIBDIR=	${SYSTEMDIR}/Libraries/${GNU_ARCH}/${OPSYS:L}
.endif
COMBOPATH=	${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu
BACKBUNDLEDIR=	${BUNDLEDIR}/libgnustep-back.bundle/${COMBOPATH}

do-install:	# empty

.include <bsd.port.post.mk>
