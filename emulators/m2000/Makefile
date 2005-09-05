#
# New ports collection makefile for:	m2000
# Date created:				2005-08-23
# Whom:					Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	m2000
PORTVERSION=	0.6
CATEGORIES=	emulators
MASTER_SITES=	\
		http://www.komkon.org/~dekogel/files/p2000/:code \
		http://www.mavetju.org/download/adopted/:tapes \
		ftp://ftp.komkon.org/pub/EMUL8/P2000/Tapes/:tapes \
		http://www.mavetju.org/download/adopted/:code
DISTFILES=	${PORTNAME:U}${EXTRACT_SUFX}:code \
		tapeconv.zip:code \
		${M2000TAPES:S/$/.gz:tapes/}
DIST_SUBDIR=	m2000
EXTRACT_ONLY=	${PORTNAME:U}${EXTRACT_SUFX}

MAINTAINER=	edwin@mavetju.org
COMMENT=	M2000 is a portable emulator for the P2000 home computer

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

M2000TAPES=	3DDoolhof2.cas		\
		BrickWall.cas		\
		Componist.cas		\
		ElevatorHumpie.cas	\
		ErrorSoft1.cas		\
		Fraxxon.cas		\
		KleurenDemo.cas		\
		LazyBug.cas		\
		MachoMan.cas		\
		MonkeyKong.cas		\
		Snakey.cas		\
		SpaceAttack.cas		\
		SpaceFight.cas		\
		SpaceMission.cas	\
		SpeelPalijs.cas		\
		StarTrek.cas		\
		VluchtSimulator.cas

WRKSRC=		${WRKDIR}/P2000
ALL_TARGET=	x

SUB_FILES=	m2000.sh
USE_UNZIP=	yes

post-extract:
	${MKDIR} ${WRKDIR}/tapeconv
	${UNZIP_CMD} ${DISTDIR}/${DIST_SUBDIR}/tapeconv.zip -d ${WRKDIR}/tapeconv
	${MV} ${WRKDIR}/tapeconv/PCM2CAS.C ${WRKDIR}/tapeconv/PCM2CAS.c

post-build:
	${CC} -o ${WRKDIR}/tapeconv/PCM2CAS ${WRKDIR}/tapeconv/PCM2CAS.c

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/m2000.sh ${PREFIX}/bin/m2000
	@${INSTALL_PROGRAM} ${WRKDIR}/tapeconv/PCM2CAS ${PREFIX}/bin/tapeconv
	@${MKDIR} ${PREFIX}/share/m2000/
	@${INSTALL_PROGRAM} ${WRKSRC}/m2000 ${PREFIX}/share/m2000
	@${INSTALL_DATA} ${WRKSRC}/P2000ROM.bin ${PREFIX}/share/m2000
	@${INSTALL_DATA} ${WRKSRC}/Default.fnt ${PREFIX}/share/m2000
	@${INSTALL_DATA} ${WRKSRC}/BASIC.bin ${PREFIX}/share/m2000
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/M2000.txt ${DOCSDIR}
.for f in ${M2000TAPES}
	@${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${f}.gz > ${WRKDIR}/${f}
	@${INSTALL_DATA} ${WRKDIR}/${f} ${PREFIX}/share/m2000
.endfor

post-install:
	@${ECHO_CMD} "Run 'make install-user' to install the tapes in your own directory"

install-user:
	@${ECHO_CMD} "Copying tapes to ${HOME}/.m2000..."
	@${MKDIR} ${HOME}/.m2000
.for f in ${M2000TAPES}
	@${INSTALL_DATA} ${WRKDIR}/${f} ${HOME}/.m2000
	@${CHMOD} u+w ${HOME}/.m2000/${f}
.endfor
	@${ECHO_CMD} "Done. Now start it with 'm2000 [tapename]' and execute the commands 'cload' and 'run'"

.include <bsd.port.mk>
