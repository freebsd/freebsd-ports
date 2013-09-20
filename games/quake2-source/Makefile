# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	source
PORTVERSION=	3.21
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://offload1.icculus.org/quake2/files/:icc \
		${MASTER_SITE_IDSOFTWARE:S|$|quake2/source/:id|}
PKGNAMEPREFIX=	quake2-
DISTNAME=	quake2-r0.16.2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:icc
DIST_SUBDIR=	quake2lnx
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake II game source

NO_BUILD=	yes

OPTIONS_DEFINE=	CTF ROGUE XATRIX
CTF_DESC=	Capture The Flag mod source
ROGUE_DESC=	Ground Zero (Rogue) mission pack source
XATRIX_DESC=	Reckoning (Xatrix) mission pack source

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCTF}
PLIST_SUB+=	CTF=""
.else
PLIST_SUB+=	CTF="@comment "
.endif

.if ${PORT_OPTIONS:MROGUE}
DISTFILES+=	roguesrc320.shar.Z:id
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_rogue_g__local.h \
		${FILESDIR}/extra-patch-src_rogue_q__shared.c
ROGUE_OFF=	454
PLIST_SUB+=	ROGUE=""
.else
PLIST_SUB+=	ROGUE="@comment "
.endif

.if ${PORT_OPTIONS:MXATRIX}
DISTFILES+=	xatrixsrc320.shar.Z:id
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_xatrix_q__shared.c
XATRIX_OFF=	441
PLIST_SUB+=	XATRIX=""
.else
PLIST_SUB+=	XATRIX="@comment "
.endif

post-extract:
.for f in rogue xatrix
.   if ${PORT_OPTIONS:M${f:U}}
	@${MKDIR} ${WRKSRC}/src/${f}
	@(cd ${WRKSRC}/src/${f} && ${GUNZIP_CMD} -c \
		${DISTDIR}/${DIST_SUBDIR}/${f}src320.shar.Z > \
		${f}src320.shar && \
		${TAIL} +${${f:U}_OFF} ${f}src320.shar | ${SH})
.   endif
.endfor

pre-install:
	@${FIND} -E ${WRKSRC} -type f \
		-iregex "(Makefile|.*\.(def|dsp|orig|shar))" -print0 | \
		${XARGS} -0 ${RM}

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/src/game ${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/Makefile.game ${DATADIR}/game/Makefile
.for f in ctf rogue xatrix
.   if ${PORT_OPTIONS:M${f:U}}
	${CP} -R ${WRKSRC}/src/${f} ${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/Makefile.${f} ${DATADIR}/${f}/Makefile
.   endif
.endfor

.include <bsd.port.mk>
