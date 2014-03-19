# Created by: ijliao
# $FreeBSD$

PORTNAME=	sonice
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://freebsd.t-hosting.hu/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sonice eases reencoding of .ogg files

RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools \
		flac:${PORTSDIR}/audio/flac \
		vorbisgain:${PORTSDIR}/audio/vorbisgain \
		${PYTHON_PKGNAMEPREFIX}yaml>0:${PORTSDIR}/devel/py-yaml

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
WRKSRC=		${WRKDIR}/sonice

post-patch:
	@${MV} ${WRKSRC}/bin/sonice.py ${WRKSRC}/bin/sonice
	@${REINPLACE_CMD} '/binify/ s|\.py||' ${WRKSRC}/setup.py

.include <bsd.port.mk>
