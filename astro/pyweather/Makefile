# New ports collection makefile for:	pyWeather
# Date created:		18 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	pyWeather
PORTVERSION=	0.1b
CATEGORIES=	astro python
MASTER_SITES=	ftp://ftp.FreeBSD.org/pub/FreeBSD/ports/local-distfiles/will/
DISTNAME=	pyWeather

MAINTAINER=	will@FreeBSD.org

RUN_DEPENDS=	${PYTHON}:${PORTSDIR}/lang/python

NO_BUILD=	yes
PYTHON?=	${LOCALBASE}/bin/python

pre-install:
	@${PERL} -pi -e "s:/usr/bin/python:${PYTHON}:g" ${WRKSRC}/pyWeather.py
	@${PERL} -pi -e "s:pyWeather.py:pyWeather:g" ${WRKSRC}/pyWeather.py

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/pyWeather.py ${PREFIX}/bin/pyWeather

.include <bsd.port.mk>
