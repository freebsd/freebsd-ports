# ex:ts=8
# Ports collection makefile for:	sonice
# Date created:			Jan 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sonice
PORTVERSION=	1.2
CATEGORIES=	audio
MASTER_SITES=	http://www.cyclooctane.com/sonice/release/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools \
		flac:${PORTSDIR}/audio/flac

USE_ZIP=	yes
USE_PYTHON=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sonice.py ${PREFIX}/bin/sonice
.for file in comatoys ogg
	${INSTALL_SCRIPT} ${WRKSRC}/${file}.py ${PYTHON_SITELIBDIR}
.endfor

.include <bsd.port.mk>
