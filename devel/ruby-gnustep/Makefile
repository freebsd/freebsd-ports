# New ports collection makefile for:	Ruby/GNUstep
# Date created:		14 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/libs/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby interface to the GNUstep development environment

BUILD_DEPENDS=	${GNUSTEP_PREFIX}/System/Makefiles/GNUstep.sh:${PORTSDIR}/${GNUSTEP_MAKE_PORT} \
		${LOCALBASE}/lib/libcallback.a:${PORTSDIR}/devel/ffcall \
		${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/${GNUSTEP_BASE_PORT} \
		${COMBOLIBDIR}/libgnustep-gui.so:${PORTSDIR}/${GNUSTEP_GUI_PORT} \
		${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/${GNUSTEP_BACK_PORT}
LIB_DEPENDS+=	objc:${PORTSDIR}/${GNUSTEP_OBJC_PORT}
RUN_DEPENDS=	${GNUSTEP_PREFIX}/System/Makefiles/GNUstep.sh:${PORTSDIR}/${GNUSTEP_MAKE_PORT} \
		${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/${GNUSTEP_BASE_PORT} \
		${COMBOLIBDIR}/libgnustep-gui.so:${PORTSDIR}/${GNUSTEP_GUI_PORT} \
		${BACKBUNDLEDIR}/libgnustep-back:${PORTSDIR}/${GNUSTEP_BACK_PORT}

USE_RUBY=	yes
RUBY_WITH_PTHREAD=	yes
USE_GMAKE=	yes
CC=		gcc32
CXX=		g++32

GNUSTEP_OBJC_PORT?=	lang/gnustep-objc
GNUSTEP_MAKE_PORT?=	devel/gnustep-make
GNUSTEP_BASE_PORT?=	lang/gnustep-base
GNUSTEP_GUI_PORT?=	x11-toolkits/gnustep-gui
GNUSTEP_BACK_PORT?=	x11-toolkits/gnustep-back
GNUSTEP_PREFIX=		${LOCALBASE}/GNUstep
GNUSTEP_LOCAL_ROOT=	${GNUSTEP_PREFIX}/Local
GNUSTEP_SYSTEM_ROOT=	${GNUSTEP_PREFIX}/System
GNUSTEP_NETWORK_ROOT=	${GNUSTEP_PREFIX}/Network
GNUSTEP_USER_ROOT=	${GNUSTEP_PREFIX}/Local/Users
GNUSTEP_MAKEFILES=	${GNUSTEP_SYSTEM_ROOT}/Makefiles

BACKBUNDLEDIR=	${GNUSTEP_PREFIX}/System/Library/Bundles/libgnustep-back.bundle
SYSLIBDIR=	${GNUSTEP_PREFIX}/System/Library/Libraries
COMBOLIBDIR=	${SYSLIBDIR}
MAKE_ENV+=	GNUSTEP_FLATTENED=yes

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

MAKEFILE=	GNUmakefile
MAKE_ENV+=	GNUSTEP_LOCAL_ROOT=${GNUSTEP_LOCAL_ROOT} \
		GNUSTEP_SYSTEM_ROOT=${GNUSTEP_SYSTEM_ROOT} \
		GNUSTEP_NETWORK_ROOT=${GNUSTEP_NETWORK_ROOT} \
		GNUSTEP_USER_ROOT=${GNUSTEP_USER_ROOT} \
		GNUSTEP_MAKEFILES=${GNUSTEP_MAKEFILES} \
		PATH=${PATH}:${GNUSTEP_SYSTEM_ROOT}/Tools
PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} OPSYS=${OPSYS:L}
NO_FILTER_SHLIBS=	yes

post-extract:
	${FIND} ${WRKSRC}/ -type f -name '.cvsignore' -delete

post-patch:
	${RUBY} -i~ -p \
		-e 'gsub(/-lpthread/, "-pthread");' \
		-e 'gsub(/-lgmodel/, "");' \
		${WRKSRC}/Source/${MAKEFILE}
	${FIND} ${WRKSRC}/ -type f | \
		${XARGS} ${RUBY} -i -pe 'gsub(/ ruby -/, " ${RUBY} -")'

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/Examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
