# New ports collection makefile for:	torcs
# Date created:		Fri 25 avr 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		torcs
PORTVERSION=		1.2.3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${TARBALL}-src
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}			\
			${EXTRADIST}
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}			\
			${DISTNAME}-robots-base${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Open Racing Car Simulator

BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GETOPT_LONG=yes
REINPLACE_ARGS=	-i ""
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
ALL_TARGET=	default

LDFLAGS+=	-L${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
TARBALL=	${PORTNAME:U}-${PORTVERSION}
DATANAME=	${TARBALL}-data
EXTRADIST=	${DATANAME}${EXTRACT_SUFX}				\
		${DISTNAME}-robots-base${EXTRACT_SUFX}			\
		${DATANAME}-tracks-dirt${EXTRACT_SUFX}			\
		${DATANAME}-tracks-oval${EXTRACT_SUFX}			\
		${DATANAME}-tracks-road${EXTRACT_SUFX}			\
		${DATANAME}-cars-extra${EXTRACT_SUFX}			\
		${DATANAME}-cars-kcendra-gt${EXTRACT_SUFX}		\
		${DATANAME}-cars-kcendra-roadsters${EXTRACT_SUFX}	\
		${DATANAME}-cars-kcendra-sport${EXTRACT_SUFX}		\
		${DATANAME}-cars-nascar${EXTRACT_SUFX}			\
		${DATANAME}-cars-Patwo-Design${EXTRACT_SUFX}		\
		${DATANAME}-cars-VM${EXTRACT_SUFX}
LINSTDIR=	share/games/${PORTNAME}
INSTDIR=	${PREFIX}/${LINSTDIR}

PLIST_SUB=	TORCSDIR=${LINSTDIR} TORCSVER=${PORTVERSION}

.if !defined(WITHOUT_BERNIW)
DISTFILES+=	${DISTNAME}-robots-berniw${EXTRACT_SUFX}
EXTRACT_ONLY+=	${DISTNAME}-robots-berniw${EXTRACT_SUFX}
PLIST_SUB+=	BERNIW=""
.else
PLIST_SUB+=	BERNIW="@comment "
.endif

.if !defined(WITHOUT_BT)
DISTFILES+=	${DISTNAME}-robots-bt${EXTRACT_SUFX}
EXTRACT_ONLY+=	${DISTNAME}-robots-bt${EXTRACT_SUFX}
PLIST_SUB+=	BT=""
.else
PLIST_SUB+=	BT="@comment "
.endif

.if !defined(WITHOUT_OLETHROS)
DISTFILES+=	${DISTNAME}-robots-olethros${EXTRACT_SUFX}
EXTRACT_ONLY+=	${DISTNAME}-robots-olethros${EXTRACT_SUFX}
PLIST_SUB+=	OLETHROS=""
.else
PLIST_SUB+=	OLETHROS="@comment "
.endif

BASH2FIX=	src/linux/torcs.in src/tools/accc/accc.in src/tools/nfsperf/nfsperf.in	\
		src/tools/texmapper/texmapper.in src/tools/nfs2ac/nfs2ac.in		\
		src/tools/trackgen/trackgen.in src/modules/telemetry/telemetry.sh	\
		robotgen Make-default.mk setup_linux.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Does not compile on FreeBSD-4."
.endif

.if ${OSVERSION} < 500041
CPPFLAGS+=	-I${X11BASE}/include
.else
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include -DHAVE_DECL_GETOPT" \
		LDFLAGS="${LDFLAGS}"
.endif

.if !defined(WITHOUT_FREEGLUT)
LIB_DEPENDS+=	glut.11:${PORTSDIR}/x11-toolkits/freeglut
.else
USE_GL=		yes
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	You might define these options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	- WITHOUT_BERNIW, WITHOUT_BT and WITHOUT_OLETHROS:"
	@${ECHO_MSG} "	  do not install optional robots."
	@${ECHO_MSG} ""

post-patch:
.for FILE in ${BASH2FIX}
	@${REINPLACE_CMD} -E -e "s|/bin/bash|${LOCALBASE}/bin/bash|"	\
		${WRKSRC}/${FILE}
.endfor

pre-install:
	@${MKDIR} ${PREFIX}/share/games

post-install:
.for extra in ${EXTRADIST}
	@ cd ${INSTDIR} &&	\
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${extra} \
			${EXTRACT_AFTER_ARGS}
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}
	@${CHMOD} -R go-w ${INSTDIR}
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*****************************************************************************"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	TORCS has been installed as ${PREFIX}/bin/torcs."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*****************************************************************************"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
