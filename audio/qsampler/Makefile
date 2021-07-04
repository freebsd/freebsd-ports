# Created by: trasz <trasz@FreeBSD.org

PORTNAME=	qsampler
DISTVERSIONPREFIX=	qsampler_
DISTVERSION=	0_9_4
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt-based front end to LinuxSampler

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgig.so:audio/libgig \
		liblscp.so:audio/liblscp
RUN_DEPENDS=	linuxsampler:audio/linuxsampler

USES=		autoreconf desktop-file-utils gl gmake localbase:ldflags pkgconfig \
		shared-mime-info qmake:no_env qt:5 xorg
USE_GL=		gl
USE_QT=		core gui network widgets x11extras \
		buildtools_build linguisttools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	rncbc

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-qt5

CXXFLAGS+=	-I${LOCALBASE}/include/qt5 -fPIC # https://github.com/rncbc/qsampler/issues/18
LDFLAGS+=	-llscp

post-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o ${PORTNAME}.mak \
		${QMAKE_ARGS}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/qsampler

.include <bsd.port.mk>
