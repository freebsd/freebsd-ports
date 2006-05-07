# New ports collection makefile for:	torcs
# Date created:		Fri 25 avr 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=		torcs
DISTVERSION=		1.2.4
PORTREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Open Racing Car Simulator

BUILD_DEPENDS=	${X11BASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png	\
		openal.0:${PORTSDIR}/audio/openal \
		alut.0:${PORTSDIR}/audio/freealut
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
REINPLACE_ARGS=	-i ""
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include --x-libraries=${X11BASE}/lib
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
ALL_TARGET=	default
INSTALL_TARGET=	install datainstall

LDFLAGS+=	-L${LOCALBASE}/lib

LINSTDIR=	share/games/${PORTNAME}
INSTDIR=	${PREFIX}/${LINSTDIR}

PLIST_SUB=	TORCSDIR=${LINSTDIR}

PORTDOCS=	faq.html

BASH2FIX=	src/linux/torcs.in src/tools/accc/accc.in src/tools/nfsperf/nfsperf.in	\
		src/tools/texmapper/texmapper.in src/tools/nfs2ac/nfs2ac.in		\
		src/tools/trackgen/trackgen.in src/modules/telemetry/telemetry.sh	\
		robotgen Make-default.mk data/tracks/road/ole-road-1/generate.sh

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Does not compile on FreeBSD-4."
.endif

.if ${OSVERSION} < 500041
CPPFLAGS+=	-I${X11BASE}/include
.else
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include -DHAVE_DECL_GETOPT" \
		LIBS="${PTHREAD_LIBS}" LDFLAGS="${LDFLAGS}"
.endif

.if !defined(WITHOUT_FREEGLUT)
LIB_DEPENDS+=	glut.11:${PORTSDIR}/graphics/freeglut
.else
USE_GL=		yes
.endif

post-patch:
.for FILE in ${BASH2FIX}
	@${REINPLACE_CMD} -E -e "s|/bin/bash|${LOCALBASE}/bin/bash|"	\
		${WRKSRC}/${FILE}
.endfor

pre-install:
	@${MKDIR} ${PREFIX}/share/games

post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/faq/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
