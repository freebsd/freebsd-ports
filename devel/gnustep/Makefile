# New ports collection makefile for:    gnustep
# Date created:         03 October 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep
PORTVERSION=	1.10.2
CATEGORIES=	devel lang
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Objective-C libraries based on the OpenStep standard

RUN_DEPENDS+=	${SYSMAKEDIR}/GNUstep.sh:${PORTSDIR}/${GNUSTEP_MAKE_PORT}
RUN_DEPENDS+=	${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/${GNUSTEP_BASE_PORT}
RUN_DEPENDS+=	${COMBOLIBDIR}/libgnustep-gui.so:${PORTSDIR}/${GNUSTEP_GUI_PORT}
RUN_DEPENDS+=	${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/${GNUSTEP_BACK_PORT}

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
NO_BUILD=	yes
SYSTEMDIR=	${PREFIX}/System
SYSMAKEDIR=	${SYSTEMDIR}/Makefiles
BUNDLEDIR=	${SYSTEMDIR}/Library/Bundles
GNUSTEP_MAKE_PORT?=	devel/gnustep-make
GNUSTEP_BASE_PORT?=	lang/gnustep-base
GNUSTEP_GUI_PORT?=	x11-toolkits/gnustep-gui
GNUSTEP_BACK_PORT?=	x11-toolkits/gnustep-back

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

SYSLIBDIR=	${SYSTEMDIR}/Library/Libraries
COMBOLIBDIR=	${SYSLIBDIR}
BACKBUNDLEDIR=	${BUNDLEDIR}/libgnustep-back.bundle

do-install:	# empty

.include <bsd.port.post.mk>
