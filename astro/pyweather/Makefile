# New ports collection makefile for:	pyWeather
# Date created:		18 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	pyWeather
PORTVERSION=	0.1b
CATEGORIES=	astro python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	will
DISTNAME=	pyWeather

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python script that downloads weather data and can be cronned

USE_REINPLACE=	yes
USE_PYTHON=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/pyWeather

post-patch:
	@${REINPLACE_CMD} -e "s:/usr/bin/python:${PYTHON_CMD}:g ; \
		s:pyWeather.py:pyWeather:g" ${WRKSRC}/pyWeather.py

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/pyWeather.py ${PREFIX}/bin/pyWeather

.include <bsd.port.mk>
