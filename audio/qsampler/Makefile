PORTNAME=	qsampler
DISTVERSIONPREFIX=	qsampler_
DISTVERSION=	0_9_90
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Qt-based front end to LinuxSampler
WWW=		http://qsampler.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgig.so:audio/libgig \
		liblscp.so:audio/liblscp
RUN_DEPENDS=	linuxsampler:audio/linuxsampler

USES=		cmake compiler:c++17-lang desktop-file-utils gl localbase:ldflags pkgconfig \
		shared-mime-info qmake:no_env qt:6 xorg
USE_GL=		gl
USE_QT=		base svg tools:build

USE_GITHUB=	yes
GH_ACCOUNT=	rncbc

.include <bsd.port.mk>
