# $FreeBSD$

PORTNAME=	cadence
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
PORTREVISION=	4
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of tools useful for audio production

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	jackit>0:audio/jack

USES=		compiler:c++11-lang gmake localbase pkgconfig \
		python:3.4+ pyqt:5 qt:5 shebangfix tar:bz2
SHEBANG_FILES=	src/*.py
USE_GITHUB=	yes
GH_ACCOUNT=	falkTX
GH_PROJECT=	Cadence
USE_QT=		core gui widgets buildtools_build
USE_PYQT=	core_run gui_run network_run widgets_run sip xml dbussupport

CXXFLAGS+=	-DJACKBRIDGE_PROPER_CPP11_SUPPORT=yes
# Give the Makefile the proper versioned binaries of PyQt
BINARY_ALIAS=	pyuic5=${LOCALBASE}/bin/pyuic5-${PYTHON_VER} \
		pyrcc5=${LOCALBASE}/bin/pyrcc5-${PYTHON_VER}

.include <bsd.port.pre.mk>

post-patch:
	@cd ${WRKSRC}/data && ${REINPLACE_CMD} ' \
		s|#!/bin/bash|#!/bin/sh| ; \
		s|exec $$PYTHON |exec ${PYTHON_CMD} | ; \
		s|ps -f -u |ps -U |' \
		cadence cadence-aloop-daemon cadence-jacksettings cadence-logs \
		cadence-pulse2jack cadence-pulse2loopback cadence-render \
		cadence-session-start catarina catia claudia claudia-launcher
	${REINPLACE_CMD} -e 's|-mtune=generic||' ${WRKSRC}/c++/Makefile.mk
.if ! ${ARCH} == amd64 && ! ${ARCH} == i386
	${REINPLACE_CMD} -e 's|-msse -mfpmath=sse||' ${WRKSRC}/c++/Makefile.mk
.endif

.include <bsd.port.post.mk>
