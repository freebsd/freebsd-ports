# New ports collection makefile for:	Ruby/GNUstep
# Date created:		14 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep
PORTVERSION=	0.2.1
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/libs/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${GNUSTEP_PREFIX}/System/Makefiles/GNUstep.sh:${PORTSDIR}/devel/gnustep-make \
		${SYSLIBDIR}/libobjc.so:${PORTSDIR}/lang/gnustep-objc \
		${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/lang/gnustep-base \
		${COMBOLIBDIR}/libgnustep-gui.so:${PORTSDIR}/x11-toolkits/gnustep-gui \
		${XGPSBUNDLEDIR}/libgnustep-xgps:${PORTSDIR}/x11-toolkits/gnustep-xgps
RUN_DEPENDS=	${GNUSTEP_PREFIX}/System/Makefiles/GNUstep.sh:${PORTSDIR}/devel/gnustep-make \
		${SYSLIBDIR}/libobjc.so:${PORTSDIR}/lang/gnustep-objc \
		${COMBOLIBDIR}/libgnustep-base.so:${PORTSDIR}/lang/gnustep-base \
		${COMBOLIBDIR}/libgnustep-gui.so:${PORTSDIR}/x11-toolkits/gnustep-gui \
		${XGPSBUNDLEDIR}/libgnustep-xgps:${PORTSDIR}/x11-toolkits/gnustep-xgps

USE_RUBY=	yes
RUBY_WITH_PTHREAD=	yes
USE_GMAKE=	yes

GNUSTEP_PREFIX=		${LOCALBASE}/GNUstep
GNUSTEP_LOCAL_ROOT=	${GNUSTEP_PREFIX}/Local
GNUSTEP_SYSTEM_ROOT=	${GNUSTEP_PREFIX}/System
GNUSTEP_NETWORK_ROOT=	${GNUSTEP_PREFIX}/Network
GNUSTEP_USER_ROOT=	${GNUSTEP_PREFIX}/Local/Users
GNUSTEP_MAKEFILES=	${GNUSTEP_SYSTEM_ROOT}/Makefiles

SYSLIBDIR=	${GNUSTEP_PREFIX}/System/Libraries/${GNU_ARCH}/${OPSYS:L}
COMBOLIBDIR=	${SYSLIBDIR}/gnu-gnu-gnu
XGPSBUNDLEDIR=	${GNUSTEP_PREFIX}/System/Library/Bundles/libgnustep-xgps.bundle/${GNU_ARCH}/${OPSYS:L}/gnu-gnu-gnu/

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif

MAKEFILE=	GNUmakefile
MAKE_ENV=	GNUSTEP_LOCAL_ROOT=${GNUSTEP_LOCAL_ROOT} \
		GNUSTEP_SYSTEM_ROOT=${GNUSTEP_SYSTEM_ROOT} \
		GNUSTEP_NETWORK_ROOT=${GNUSTEP_NETWORK_ROOT} \
		GNUSTEP_USER_ROOT=${GNUSTEP_USER_ROOT} \
		GNUSTEP_MAKEFILES=${GNUSTEP_MAKEFILES} \
		PATH=${PATH}:${GNUSTEP_SYSTEM_ROOT}/Tools
PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} OPSYS=${OPSYS:L}
NO_FILTER_SHLIBS=	yes

post-extract:
	find ${WRKSRC}/ -type f -name '.cvsignore' -delete

post-patch:
	${RUBY} -i~ -p \
		-e 'gsub(/-lpthread/, "-pthread");' \
		-e 'gsub(/-lgmodel/, "");' \
		${WRKSRC}/Source/${MAKEFILE}
	find ${WRKSRC}/ -type f | xargs ${RUBY} -i -pe 'gsub(/ ruby -/, " ${RUBY} -")'

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
