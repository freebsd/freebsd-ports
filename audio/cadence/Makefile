PORTNAME=	cadence
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.2
PORTREVISION=	4
CATEGORIES=	audio

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	bf25db6ebdc6437fce5a60afd203fee169efd068.diff:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of tools useful for audio production
WWW=		https://kxstudio.linuxaudio.org/Applications:Cadence

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	jackit>0:audio/jack \
		jack_capture:audio/jack-capture

USES=		compiler:c++11-lang desktop-file-utils gmake localbase pkgconfig \
		python pyqt:5 qt:5 shebangfix tar:bz2
SHEBANG_FILES=	src/*.py
USE_QT=		core gui widgets buildtools:build
USE_PYQT=	pyqt5 sip

USE_GITHUB=	yes
GH_ACCOUNT=	falkTX
GH_PROJECT=	Cadence

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
