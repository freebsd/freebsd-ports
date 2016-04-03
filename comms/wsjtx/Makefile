# $FreeBSD$

PORTNAME=	wsjtx
PORTVERSION=	1.6.0
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/wsjt/${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}:src \
		http://www.physics.princeton.edu/pulsar/K1JT/wsjtx-doc/:docs \
		LOCAL/db:docs
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:src \
		wsjtx-main-${PORTVERSION}.html:docs

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Weak signal ham radio communication package

LICENSE=	GPLv3

BUILD_DEPENDS=	a2x:textproc/asciidoc
LIB_DEPENDS=	libfftw3.so:math/fftw3 \
		libfftw3f.so:math/fftw3-float \
		libhamlib.so:comms/hamlib \
		libxslt.so:textproc/libxslt
RUN_DEPENDS=	${LOCALBASE}/bin/kvasd:comms/kvasd

MAKE_JOBS_UNSAFE=	yes
USE_GCC=	yes
USE_GL=		yes
USE_QT5=	gui buildtools qmake_build widgets multimedia concurrent serialport
USES=		cmake compiler fortran pkgconfig tar:tgz
CMAKE_ARGS+=	-DPORT_BUILDING::STRING="ON" \
		-DWSJT_SKIP_MANPAGES::BOOL="YES" \
		-DCMAKE_PREFIX_PATH+=${LOCALBASE}/wsjtx/lib
WRKSRC=		${WRKDIR}/${PORTNAME}

do-extract:
	${TAR} xf ${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} -C${WRKDIR}
	${TAR} xf ${WRKDIR}/${PORTNAME}-${PORTVERSION}/src/wsjtx.tgz -C${WRKDIR}

post-install:
	${MKDIR} -v ${STAGEDIR}${MANPREFIX}/man/man1
	${CP} ${FILESDIR}/*.gz ${STAGEDIR}${MANPREFIX}/man/man1
	${CP} ${DISTDIR}/${PORTNAME}-main-${PORTVERSION}.html ${STAGEDIR}${DOCSDIR}
.for f in AUTHORS BUGS COPYING INSTALL NEWS README THANKS
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/debian/changelog.Debian.gz ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/debian/copyright ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
