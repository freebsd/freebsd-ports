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
		${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml

USE_PYTHON=	yes
NO_STAGE=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/sonice

post-install:
	@${MV} ${PREFIX}/bin/sonice.py ${PREFIX}/bin/sonice

.include <bsd.port.mk>
