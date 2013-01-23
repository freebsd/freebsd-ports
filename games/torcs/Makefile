# Created by:	thierry@pompo.net
# $FreeBSD$

PORTNAME=	torcs
DISTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/all-in-one/${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	The Open Racing Car Simulator

LICENSE=	GPLv2

MAKE_JOBS_UNSAFE=	yes

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		vorbis:${PORTSDIR}/audio/libvorbis
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_XORG=	xrender xmu ice xext x11 xxf86vm xrandr
USE_GL=		glut
USE_OPENAL=	al alut
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
REINPLACE_ARGS=	-i ""
CONFIGURE_ARGS=	--x-includes=${LOCALBASE}/include --x-libraries=${LOCALBASE}/lib
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include -DHAVE_DECL_GETOPT

ALL_TARGET=	default
INSTALL_TARGET=	install datainstall

LDFLAGS+=	-L${LOCALBASE}/lib

INSTDIR=	${PREFIX}/share/games/${PORTNAME}

PORTDOCS=	faq.html

BASH2FIX=	src/linux/torcs.in src/tools/accc/accc.in \
		src/tools/nfsperf/nfsperf.in \
		src/tools/texmapper/texmapper.in src/tools/nfs2ac/nfs2ac.in \
		src/tools/trackgen/trackgen.in \
		src/modules/telemetry/telemetry.sh robotgen Make-default.mk

DESKTOP_ENTRIES=	"TORCS" \
			"The Open Racing Car Simulator" \
			"${INSTDIR}/Ticon.png" \
			"torcs" \
			"Game;Simulation;" \
			false

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

EMPTYDIR=	champ dtmrace endrace ncrace practice quickrace

post-patch:
.for FILE in ${BASH2FIX}
	@${REINPLACE_CMD} -E -e "s|/bin/bash|${LOCALBASE}/bin/bash|"	\
		${WRKSRC}/${FILE}
.endfor

pre-install:
	@${MKDIR} ${PREFIX}/share/games

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/faq/|} ${DOCSDIR}
.endif
.for ed in ${EMPTYDIR}
	${TOUCH} ${INSTDIR}/results/${ed}/.keep_me
.endfor

.include <bsd.port.mk>
