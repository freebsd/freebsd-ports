PORTNAME=	timbre-mill
DISTVERSION=	0.5.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/sadko4u/timbre-mill/releases/download/${DISTVERSION}/
DISTNAME=	${PORTNAME}-src-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Timbre Mill tool for timbre correction
WWW=		https://github.com/sadko4u/timbre-mill

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=	undefined symbol: lsp::aarch64::dsp_init(), see https://github.com/sadko4u/timbre-mill/issues/4
BROKEN_armv6=	clang crashes after printing "Unable to encode MCOperand!"
BROKEN_armv7=	compilation fails: operand must be an immediate in the range, see https://github.com/sadko4u/timbre-mill/issues/5
BROKEN_i386=	clang crashes, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=265680

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
