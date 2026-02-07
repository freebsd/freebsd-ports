PORTNAME=	wsjtz
DISTVERSION=	2.7.0-rc7-1.48
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/wsjt-z/Source

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Clone of WSJT-X software with additional features
WWW=		https://sourceforge.net/projects/wsjt-z/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

PATCH_DEPENDS=	dos2unix:converters/dos2unix
BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook:textproc/docbook-xsl \
		a2x:textproc/asciidoc \
		asciidoctor:textproc/rubygem-asciidoctor \
		boost-libs>0:devel/boost-libs \
		libtool:devel/libtool
LIB_DEPENDS=	libboost_log_setup.so:devel/boost-libs \
		libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libhamlib.so:comms/hamlib \
		libreadline.so:devel/readline

USES=		cmake compiler:c++14-lang fortran makeinfo pkgconfig qt:5 zip
USE_QT=		concurrent core gui multimedia network printsupport serialport \
		sql sql-sqlite3 testlib widgets buildtools:build \
		linguisttools:build qmake:build

CMAKE_ARGS+=	-DCMAKE_PREFIX_PATH+=${LOCALBASE}/${PORTNAME:S/z/x/}/lib \
		-DLOCALBASE::STRING="${LOCALBASE}"
# for detailed debugging uncomment the next line
#CMAKE_ARGS+=   --debug-output --trace

CONFLICTS=	wsjtx

DATADIR=	${PREFIX}/share/${PORTNAME:S/z/x/}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/z/x/}

WRKSRC=		${WRKDIR}/${PORTNAME:S/z/x/}

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

pre-patch:
	${FIND} ${WRKSRC} -type f -not -name '*.png' \
		-exec dos2unix {} > /dev/null 2>&1 \;

post-install:
.for f in fcal fmeasure fmtave fst4sim ft8code jt4code jt65code jt9 jt9code \
	message_aggregator msk144code q65code q65sim udp_daemon wsjtx wsprd
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
