# ex:ts=8
# New ports collection makefile for:	cymbaline
# Date created:			Jun 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cymbaline
PORTVERSION=	0.9
CATEGORIES=	audio python
MASTER_SITES=	http://www.silmarill.org/cymbaline/
DISTNAME=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		aumix:${PORTSDIR}/audio/aumix

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cymbaline.py ${PREFIX}/bin/cymbaline
	${INSTALL_DATA} ${WRKSRC}/mp3.py ${PYTHON_SITELIBDIR}

.include <bsd.port.mk>
