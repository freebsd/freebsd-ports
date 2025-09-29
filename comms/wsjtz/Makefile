PORTNAME=	wsjtz
DISTVERSION=	2.5.4-1.22
PORTREVISION=	13
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/wsjt-z/Source

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Clone of WSJT-X software with additional features
WWW=		https://sourceforge.net/projects/wsjt-z/

LICENSE=	GPLv3

LIB_DEPENDS=	libboost_log_setup.so:devel/boost-libs \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libhamlib.so:comms/hamlib \
		libreadline.so:devel/readline
BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook:textproc/docbook-xsl \
		a2x:textproc/asciidoc \
		asciidoctor:textproc/rubygem-asciidoctor \
		boost-libs>0:devel/boost-libs \
		libtool:devel/libtool

USES=		cmake compiler:c++14-lang fortran makeinfo pkgconfig qt:5 zip
USE_QT=		concurrent core gui multimedia network printsupport serialport \
		sql sql-sqlite3 testlib widgets buildtools:build \
		linguisttools:build qmake:build

CONFLICTS=	wsjtx

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
