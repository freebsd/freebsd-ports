# ex:ts=8
# Ports collection makefile for:	sonice
# Date created:			Jan 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sonice
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://freebsd.t-hosting.hu/${PORTNAME}/

MAINTAINER=	gkovedan@t-hosting.hu
COMMENT=	Sonice eases reencoding of .ogg files

RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools \
		flac:${PORTSDIR}/audio/flac \
		vorbisgain:${PORTSDIR}/audio/vorbisgain \
		${PYTHON_SITELIBDIR}/yaml/__init__.py:${PORTSDIR}/devel/py-yaml

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
WRKSRC=		${WRKDIR}/sonice

post-install:
	@${MV} ${PREFIX}/bin/sonice.py ${PREFIX}/bin/sonice

.include <bsd.port.mk>
