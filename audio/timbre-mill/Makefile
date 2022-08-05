PORTNAME=	timbre-mill
DISTVERSION=	0.5.6
CATEGORIES=	audio
MASTER_SITES=	https://github.com/sadko4u/timbre-mill/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Timbre Mill tool for timbre correction

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libiconv.so:converters/libiconv \
		libsndfile.so:audio/libsndfile # for some reason binaries aren't linked with shared libs

USES=		gmake iconv localbase:ldflags pkgconfig

WRKSRC=		${WRKDIR}/${PORTNAME}

BINARY_ALIAS=	make=${GMAKE} \
		g++=${CXX}

PLIST_FILES=	bin/${PORTNAME}

pre-configure:
	 @cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} config

post-install:
	# remove redundant symlink
	@cd ${STAGEDIR}${PREFIX}/bin && \
		${RM} ${PORTNAME} && \
		${MV} ${PORTNAME}-${DISTVERSION} ${PORTNAME}
	# strip binary
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
