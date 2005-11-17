# New ports collection makefile for:	quake3
# Date created:							23 August 2005
# Whom:									pypt
#
# $FreeBSD$
#

PORTNAME=	quake3
PORTVERSION=	1.32b
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/
EXTRACT_SUFX=	-source.zip
EXTRACT_ONLY=

MAINTAINER=	shirshegsm@gmail.com
COMMENT=	Quake III Arena -- first person shooter (native build)

EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS=		nasm:${PORTSDIR}/devel/nasm

USE_GMAKE=		yes
USE_PERL5_BUILD=	yes
USE_GL=			yes
USE_REINPLACE=		yes
CONFLICTS=		q3server-1.32*

# We need that -a flag
do-extract:
		${MKDIR} ${WRKDIR} && \
		cd ${WRKDIR} && \
		${UNZIP_CMD} -aqx ${DISTDIR}/${PORTNAME}-${PORTVERSION}-source.zip

post-patch:
		@${REINPLACE_CMD} -e 's|##PREFIX##|${PREFIX}|g' ${WRKSRC}/code/unix/unix_shared.c

pre-build:
		${MKDIR} ${WRKSRC}/lcc/build

do-build:
		cd ${WRKSRC}/code && \
		${PERL} unix/cons
		${MV} ${WRKSRC}/code/install/linuxq3ded ${WRKSRC}/code/install/q3ded
		${MV} ${WRKSRC}/code/install/linuxquake3 ${WRKSRC}/code/install/quake3

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/code/install/q3ded ${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/code/install/quake3 ${PREFIX}/bin
		${MKDIR} ${PREFIX}/lib/quake3/baseq3/vm
		${CP} ${WRKSRC}/code/install/baseq3/cgamei386.so ${PREFIX}/lib/quake3/baseq3
		${CP} ${WRKSRC}/code/install/baseq3/qagamei386.so ${PREFIX}/lib/quake3/baseq3
		${CP} ${WRKSRC}/code/install/baseq3/uii386.so ${PREFIX}/lib/quake3/baseq3
		${CP} ${WRKSRC}/code/install/baseq3/vm/cgame.qvm ${PREFIX}/lib/quake3/baseq3/vm
		${CP} ${WRKSRC}/code/install/baseq3/vm/qagame.qvm ${PREFIX}/lib/quake3/baseq3/vm
		${CP} ${WRKSRC}/code/install/baseq3/vm/ui.qvm ${PREFIX}/lib/quake3/baseq3/vm
		${MKDIR} ${PREFIX}/lib/quake3/missionpack/vm
		${CP} ${WRKSRC}/code/install/missionpack/cgamei386.so ${PREFIX}/lib/quake3/missionpack
		${CP} ${WRKSRC}/code/install/missionpack/qagamei386.so ${PREFIX}/lib/quake3/missionpack
		${CP} ${WRKSRC}/code/install/missionpack/uii386.so ${PREFIX}/lib/quake3/missionpack
		${CP} ${WRKSRC}/code/install/missionpack/vm/cgame.qvm ${PREFIX}/lib/quake3/missionpack/vm
		${CP} ${WRKSRC}/code/install/missionpack/vm/qagame.qvm ${PREFIX}/lib/quake3/missionpack/vm
		${CP} ${WRKSRC}/code/install/missionpack/vm/ui.qvm ${PREFIX}/lib/quake3/missionpack/vm

post-install:
		${CAT} pkg-message

.include <bsd.port.mk>
