# New ports collection makefile for:	irit
# Date created:		6 August 2002
# Whom:			Igor Pokrovsky <tiamat@telegraph.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	irit
PORTVERSION=	9.5
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.technion.ac.il/~irit/
DISTNAME=	${PORTNAME}-sm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Solid modeling system

LIB_DEPENDS=	rle.1:${PORTSDIR}/graphics/urt
BUILD_DEPENDS=	${LOCALBASE}/lib/libpng.a:${PORTSDIR}/graphics/png \
		${LOCALBASE}/lib/libungif.a:${PORTSDIR}/graphics/libungif

BROKEN=		checksum mismatch

USE_ZIP=	yes
USE_GMAKE=	yes
.ifdef (WITH_MOTIF)
USE_MOTIF=	yes
USE_GL=		gl
.endif
USE_LDCONFIG=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile.gnux
MAKE_ARGS=	"CFG=Rel"
MAKE_ENV=	WRKSRC=${WRKSRC} \
		ECHO_CMD=${ECHO_CMD} \
		LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:${WRKSRC}/lib
NOT_FOR_ARCHS=	sparc64
.ifdef (WITH_MOTIF)
MAKE_ENV+=	WITH_MOTIF_DEF=yes
.endif

SUB_FILES=	pkg-message
SUB_LIST=	"DATADIR=${DATADIR}"

PORTDOCS=	irit.doc prog_man.html general.inf technion.inf update.new \
		coding.std coding.hints

.if !defined(WITH_MOTIF)
PLIST_SUB=	WITH_MOTIF="@comment "
.else
PLIST_SUB=	WITH_MOTIF=""
.endif

.ifndef (WITH_MOTIF)
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Define WITH_MOTIF=yes to build X11/Motif and OpenGL display drivers"
	@${ECHO_CMD} ""
.endif

pre-build:
	@${CP} ${WRKSRC}/makefile.gnux ${WRKSRC}/makefile.unx
	@${CP} ${WRKSRC}/makeflag.gnux ${WRKSRC}/makeflag.unx

do-install:
	FILES="`${FIND} ${WRKSRC}/bin -type f`";			\
	for i in $${FILES}; do						\
		if [ "`${FILE} -b $$i | ${GREP} LSB`" ]; then		\
			${INSTALL_PROGRAM} $$i ${PREFIX}/bin;		\
		fi;							\
	done

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
	@${MKDIR} ${EXAMPLESDIR}/emacs
	${INSTALL_DATA} ${WRKSRC}/emacs/irit.el ${EXAMPLESDIR}/emacs
	@${MKDIR} ${EXAMPLESDIR}/scripts
	${INSTALL_DATA} ${WRKSRC}/scripts/*.irt ${EXAMPLESDIR}/scripts

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
