PORTNAME=	qucs-s
DISTVERSION=	0.0.24
PORTREVISION=	2
CATEGORIES=	cad

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quite Universal Circuit Simulator: GUI for circuit simulation kernels

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	ngspice:cad/ngspice_rework \
		octave:math/octave

USES=		cmake qt:5
USE_QT=		core gui printsupport svg widgets buildtools_build linguisttools_build qmake_build

USE_GITHUB=	yes
GH_ACCOUNT=	ra3xdh
GH_PROJECT=	qucs_s

OPTIONS_GROUP=		BACKENDS
OPTIONS_GROUP_BACKENDS=	XYCE

BACKENDS_DESC=		Additional backends (in addition to ngspice)

XYCE_DESC=		Xyce electronic simulator
XYCE_RUN_DEPENDS=	Xyce:cad/xyce

post-patch:
	# first the patch under files/ introduces %%PREFIX%%, and now we fix it here
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/qucs/main.cpp

.include <bsd.port.mk>
