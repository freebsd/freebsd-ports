PORTNAME=	ctf
PORTVERSION=	1.52
CATEGORIES=	games
MASTER_SITES=	IDSOFTWARE/quake2/ctf/:data \
		http://offload1.icculus.org/quake2/files/:src
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTFILES=	${CTF_DATA}:data ${CTF_SRC}:src
DIST_SUBDIR=	quake2lnx

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake II CTF (Capture The Flag) mod

USES=		dos2unix zip:infozip
DOS2UNIX_FILES=	../../../ctf/readme.txt ../../../ctf/server.cfg
WRKSRC=		${WRKDIR}/${CTF_SRC:S/.tar.gz//}/src/ctf

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

CTF_DATA=	q2ctf150.zip
CTF_SRC=	quake2-r0.16.2.tar.gz

OPTIONS_DEFINE=	DOCS

.include "${.CURDIR}/../quake2-data/Makefile.include"
.include <bsd.port.options.mk>

do-extract:
	@${MKDIR} ${WRKDIR}
	@${TAR} zxf ${DISTDIR}/${DIST_SUBDIR}/${CTF_SRC} -C ${WRKDIR} \
		--include "${CTF_SRC:S/.tar.gz//}/src/ctf/*"
	@${UNZIP_CMD} ${EXTRACT_BEFORE_ARGS} -d ${WRKDIR}/ctf \
		${DISTDIR}/${DIST_SUBDIR}/${CTF_DATA} -x *.dll *.ico

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${Q2DIR}/ctf
	${INSTALL_PROGRAM} ${WRKSRC}/game.so ${STAGEDIR}${Q2DIR}/ctf
.for f in *.cfg *.pak
	${INSTALL_DATA} ${WRKDIR}/ctf/${f} ${STAGEDIR}${Q2DIR}/ctf
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/ctf/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
