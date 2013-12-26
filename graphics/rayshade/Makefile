# Created by: giffunip@asme.org
# $FreeBSD$

PORTNAME=	rayshade
PORTVERSION=	4.0.6
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://ccl.net/cca/software/SOURCES/C/rayshade/ \
		http://www.mirrorservice.org/sites/graphics.stanford.edu/pub/rayshade/ \
		ftp://graphics.stanford.edu/pub/rayshade/
DISTFILES=	${PORTNAME}.${PORTVERSION}.tar.Z ${GUIDE_PS_Z}
DIST_SUBDIR=	rayshade
EXTRACT_ONLY=	${PORTNAME}.${PORTVERSION}.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible system for creating ray-traced images

BUILD_DEPENDS=	$(LOCALBASE)/lib/librle.a:${PORTSDIR}/graphics/urt

OPTIONS_DEFINE=	DOCS EXAMPLES

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION:R}

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
ALL_TARGET=	# empty

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/rayshade

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
GUIDE_PS_Z=	guide.ps.Z
.endif

.if defined(BATCH) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS=	< ${WRKDIR}/config.ans
.endif

pre-configure:
	@${SED} -e \
		"s,@CFLAGS@,${CFLAGS},g ; \
		 s,@CC@,${CC},g ; \
		 s,@LOCALBASE@,${LOCALBASE},g ; \
		 s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/config.ans > ${WRKDIR}/config.ans

do-install:
	(cd ${WRKSRC}/rayshade && ${INSTALL_PROGRAM} rayshade \
		${STAGEDIR}${PREFIX}/bin)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${DISTDIR}/${DIST_SUBDIR} && ${INSTALL_DATA} ${GUIDE_PS_Z} \
		${STAGEDIR}${DOCSDIR})
.endif
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/Examples && ${INSTALL_DATA} * \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
