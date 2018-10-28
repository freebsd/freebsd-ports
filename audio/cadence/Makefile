# $FreeBSD$

PORTNAME=	cadence
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0-7
DISTVERSIONSUFFIX=	-g4a5f5b4
CATEGORIES=	audio

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of tools useful for audio production

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	jackit>0:audio/jack

USES=		gmake compiler:c++11-lang tar:bz2 localbase pkgconfig python:3.4+ pyqt:5 qt:5 shebangfix
SHEBANG_FILES=	src/*.py
USE_GITHUB=	yes
GH_ACCOUNT=	falkTX
GH_PROJECT=	Cadence
USE_QT=		core gui widgets buildtools_build
USE_PYQT=	core_run gui_run network_run widgets_run sip xml_build

CXXFLAGS+=	-DJACKBRIDGE_PROPER_CPP11_SUPPORT=yes

post-patch:
	@${REINPLACE_CMD} 's|exec $$PYTHON |exec ${PYTHON_CMD} |' ${WRKSRC}/data/cadence
	@cd ${WRKSRC}/data && ${REINPLACE_CMD} ' \
		s|#!/bin/bash|#!/bin/sh| ; \
		s|ps -f -u |ps -U |' \
		cadence cadence-aloop-daemon cadence-jacksettings cadence-logs \
		cadence-pulse2jack cadence-pulse2loopback cadence-render \
		cadence-session-start catarina catia claudia claudia-launcher

.include <bsd.port.mk>
