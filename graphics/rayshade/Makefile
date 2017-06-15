# Created by: giffunip@asme.org
# $FreeBSD$

PORTNAME=	rayshade
PORTVERSION=	4.0.6
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://ccl.net/cca/software/SOURCES/C/rayshade/ \
		http://www.mirrorservice.org/sites/graphics.stanford.edu/pub/rayshade/ \
		ftp://graphics.stanford.edu/pub/rayshade/
DISTFILES=	${PORTNAME}.${PORTVERSION}.tar.Z
DIST_SUBDIR=	rayshade
EXTRACT_ONLY=	${PORTNAME}.${PORTVERSION}.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible system for creating ray-traced images

LICENSE=	rayshade
LICENSE_NAME=	Rayshade license
LICENSE_FILE=	${WRKSRC}/Doc/Copyright
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

DEPRECATED=	Depends on expiring graphics/urt
EXPIRATION_DATE=2017-04-01

BUILD_DEPENDS=	${LOCALBASE}/lib/librle.a:graphics/urt

WRKSRC=		${WRKDIR}/${PORTNAME}.${PORTVERSION:R}

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
ALL_TARGET=	# empty

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/rayshade

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCS_DISTFILES=	guide.ps.Z

.include <bsd.port.options.mk>

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
	${INSTALL_PROGRAM} ${WRKSRC}/rayshade/rayshade \
		${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/guide.ps.Z \
		${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/Examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
