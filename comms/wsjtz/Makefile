PORTNAME=	wsjtz
DISTVERSION=	2.5.4-1.22
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/wsjt-z/Source

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Clone of WSJT-X software with additional features

CONFLICTS=	wsjtx

LICENSE=	GPLv3

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor \
		autoconf>=2.69:devel/autoconf \
		automake>=1.16.1:devel/automake \
		a2x:textproc/asciidoc \
		boost-libs>0:devel/boost-libs \
		libtool:devel/libtool \
		${LOCALBASE}/share/xsl/docbook:textproc/docbook-xsl
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libxslt.so:textproc/libxslt \
		libhamlib.so:comms/hamlib \
		libreadline.so:devel/readline \
		libportaudio.so:audio/portaudio

USES=		cmake compiler:c++11-lib fortran gl \
		makeinfo pkgconfig qt:5 zip
USE_GL=		glu
USE_QT=		core gui network widgets \
		multimedia concurrent printsupport serialport sql sql-sqlite3 \
		testlib buildtools_build linguisttools_build qmake_build

CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH+=${LOCALBASE}/wsjtx/lib \
		-DLOCALBASE::STRING="${LOCALBASE}"
# for detailed debugging uncomment the next line
#CMAKE_ARGS+=   --debug-output --trace
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/z/x/}
DATADIR=	${PREFIX}/share/${PORTNAME:S/z/x/}
WRKSRC=		${WRKDIR}/wsjtx

.include <bsd.port.pre.mk>

.if ${GCC_DEFAULT} >= 10
# workaround for More actual than formal arguments in procedure call at (1)
FFLAGS+=	-fallow-argument-mismatch
.endif

post-install:
.for f in fcal fmeasure fmtave fst4sim ft8code jt4code jt65code jt9 jt9code \
	message_aggregator msk144code q65code q65sim udp_daemon wsjtx wsprd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

.include <bsd.port.post.mk>
