# New ports collection makefile for:	irit
# Date created:		6 August 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	irit
PORTVERSION=	9.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.technion.ac.il/~irit/
DISTNAME=	${PORTNAME}-sm

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	Solid modeling system

BUILD_DEPENDS=	${LOCALBASE}/lib/libpng.a:${PORTSDIR}/graphics/png \
		${LOCALBASE}/lib/libungif.a:${PORTSDIR}/graphics/libungif

USE_ZIP=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
.ifdef (WITH_MOTIF)
USE_MOTIF=	yes
USE_GL=		yes
.endif
INSTALLS_SHLIB=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile.unx
MAKE_ENV=	WRKSRC=${WRKSRC} \
		ECHO_CMD=${ECHO_CMD} \
		LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${WRKSRC}/lib
.ifdef (WITH_MOTIF)
MAKE_ENV+=	WITH_MOTIF_DEF=yes
.endif

IRIT_PROGS=	3ds2irit aisoshad dat2bin dat2irit dxf2irit igs2irit ihidden \
		illustrt irender irit irit2dxf irit2hgl irit2igs irit2iv \
		irit2nff irit2off irit2plg irit2pov irit2ps irit2ray irit2scn \
		irit2stl irit2wrl irit2xfg izebra lineshad obj2irit off2irit \
		poly3d-h skeletn1 stl2irit
IRIT_DRVS=	nuldrvs x11drvs
.ifdef (WITH_MOTIF)
IRIT_DRVS+=	xmtdrvs xogldrvs
.endif

.if !defined(WITH_MOTIF)
PLIST_SUB=	WITH_MOTIF="@comment "
.else
PLIST_SUB=	WITH_MOTIF=""
.endif

PKGMESSAGE=	${WRKDIR}/pkg-message

.ifndef (WITH_MOTIF)
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define WITH_MOTIF=yes to build X11/Motif and OpenGL display drivers"
	@${ECHO_CMD} ""
.endif

do-install:
.for i in ${IRIT_PROGS} ${IRIT_DRVS}
	${INSTALL_PROGRAM} ${WRKSRC}/bin/$i ${PREFIX}/bin
.endfor

	${INSTALL_PROGRAM} ${WRKSRC}/lib/libIrit*.so ${PREFIX}/lib/
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/${PORTNAME}

	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/*.cfg ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/iritfont.itd ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin/iritinit.irt ${DATADIR}

	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/data
	${INSTALL_DATA} ${WRKSRC}/data/* ${EXAMPLESDIR}/data
	@${MKDIR} ${EXAMPLESDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/scripts/* ${EXAMPLESDIR}/scripts

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/irit.doc ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/docs/prog_man.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/general.inf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/technion.inf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/update.new ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/coding.std ${DOCSDIR}
.endif

post-install:
	@(${SED} -e 's|%%DATADIR%%|${DATADIR}|' \
		<pkg-message >${PKGMESSAGE} && ${CAT} ${PKGMESSAGE})

.include <bsd.port.mk>
