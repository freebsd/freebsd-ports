# New ports collection makefile for:	torcs
# Date created:		Fri 25 avr 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	torcs
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${TARBALL}-src
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}			\
		${EXTRADIST}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}			\
		${DISTNAME}-robots-base${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Open Racing Car Simulator

BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
# doxygen would be required to build the doc (TODO?)
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png
USE_MESA=	yes
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include ${CFLAGSD}" \
		LDFLAGS="-L${LOCALBASE}/lib"
ALL_TARGET=	default

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
TARBALL=	${PORTNAME:U}-${PORTVERSION}
DATANAME=	${TARBALL}-data
EXTRADIST=	${DATANAME}${EXTRACT_SUFX}			\
		${DISTNAME}-robots-base${EXTRACT_SUFX}		\
		${DATANAME}-tracks-base${EXTRACT_SUFX}		\
		${DATANAME}-cars-extra${EXTRACT_SUFX}		\
		${DATANAME}-cars-Patwo-Design${EXTRACT_SUFX}
INSTDIR=	${PREFIX}/share/games/${PORTNAME}

.include <bsd.port.pre.mk>

.if (${ARCH} == "amd64") || (${ARCH} == "ia64")
BROKEN=		"does not build on ${ARCH}"
.endif

.if !defined(WITHOUT_BERNIW)
DISTFILES+=	${DISTNAME}-robots-berniw${EXTRACT_SUFX}
EXTRACT_ONLY+=	${DISTNAME}-robots-berniw${EXTRACT_SUFX}
PLIST_SUB=	BERNIW=""
.else
PLIST_SUB=	BERNIW="@comment "
.endif

.if !defined(WITHOUT_K1999)
DISTFILES+=	${DISTNAME}-robots-K1999${EXTRACT_SUFX}
EXTRACT_ONLY+=	${DISTNAME}-robots-K1999${EXTRACT_SUFX}
PLIST_SUB+=	K1999=""
.else
PLIST_SUB+=	K1999="@comment "
.endif

2BCLEANED=	Make-config src/libs/txml/gennmtab/gennmtab.o
BASH2FIX=	src/modules/telemetry/telemetry.sh src/tools/launcher/torcs.in	\
		Make-default.mk robotgen		\

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	You might define these options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	- WITHOUT_BERNIW and WITHOUT_K1999: do not install optional"
	@${ECHO_MSG} "	  robots."
	@${ECHO_MSG} ""

post-extract:
.for SLAG in ${2BCLEANED}
	@${RM} ${WRKSRC}/${SLAG}
.endfor

post-patch:
.for file in ${BASH2FIX}
	@${REINPLACE_CMD} -e "s|/bin/bash|${LOCALBASE}/bin/bash|g"	\
		${WRKSRC}/${file}
.endfor

pre-install:
	@${MKDIR} ${PREFIX}/share/games

post-install:
.for file in ${EXTRADIST}
	@ cd ${INSTDIR} &&	\
		${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${file} \
			${EXTRACT_AFTER_ARGS}
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${INSTDIR}
	@${CHMOD} -R go-w ${INSTDIR}
	@${CHMOD} +x ${INSTDIR}/setup_linux.sh
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*****************************************************************************"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	TORCS has been installed as ${PREFIX}/bin/torcs."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "*****************************************************************************"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
