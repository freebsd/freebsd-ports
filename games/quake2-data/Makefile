PORTNAME=	data
PORTVERSION=	3.20
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	IDSOFTWARE/quake2/:data IDSOFTWARE/quake2/source/:src
PKGNAMEPREFIX=	${Q2PKGNAMEPREFIX}
DISTFILES=	${Q2_UPDATE}:data ${Q2_SRC}:src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake II data files

# XXX we need info-unzip for q2-314-demo-x86.exe
USES=		zip:infozip
NO_WRKSUBDIR=	yes

DATADIR=	${Q2DIR}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

Q2_DEMO=	q2-314-demo-x86.exe
Q2_SRC=		q2src${PORTVERSION:S|.||}.shar.Z
Q2_UPDATE=	q2-${PORTVERSION}-x86-full.exe

OPTIONS_DEFINE=	MANUAL OPTIMIZED_CFLAGS SHAREWARE
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

MANUAL_DESC=	Install the game HTML manual
SHAREWARE_DESC=	Install demo version of the game data

.include "Makefile.include"	# must be included before bsd.port.options.mk
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMANUAL} || ${PORT_OPTIONS:MSHAREWARE}
DISTFILES+=	${Q2_DEMO}:data
.endif

.if ${PORT_OPTIONS:MMANUAL}
PLIST_SUB+=	MANUAL=""
.else
PLIST_SUB+=	MANUAL="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-ffast-math -funroll-loops -fomit-frame-pointer \
		-fexpensive-optimizations
.endif

.if ${PORT_OPTIONS:MSHAREWARE}
PLIST_SUB+=	FULL="@comment " SHAREWARE=""
.else
PLIST_SUB+=	FULL="" SHAREWARE="@comment "
SUB_FILES=	pkg-message
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && uncompress -c ${DISTDIR}/${Q2_SRC} | \
		${TAIL} +434 | ${SH}
	@${UNZIP_CMD} -q -d ${WRKSRC} \
		${DISTDIR}/${Q2_UPDATE} baseq2/* -x *.dll
.if ${PORT_OPTIONS:MMANUAL}
	@${UNZIP_CMD} -ajq -d ${WRKSRC}/DOCS \
		${DISTDIR}/${Q2_DEMO} Install/Data/DOCS/*
.endif
.if ${PORT_OPTIONS:MSHAREWARE}
	@${RM} ${WRKSRC}/baseq2/pak[^0].pak
	@${UNZIP_CMD} -jq -d ${WRKSRC}/baseq2 \
		${DISTDIR}/${Q2_DEMO} Install/Data/baseq2/pak0.pak
.endif

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's/__linux__/__unix__/' ${WRKSRC}/q_shared.[ch]

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/baseq2
	${INSTALL_PROGRAM} ${WRKSRC}/game.so ${STAGEDIR}${DATADIR}/baseq2
	${CP} -a ${WRKSRC}/baseq2/* ${STAGEDIR}${DATADIR}/baseq2
.if ${PORT_OPTIONS:MMANUAL}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -a ${WRKSRC}/DOCS ${STAGEDIR}${DOCSDIR}/manual
.endif

.include <bsd.port.mk>
