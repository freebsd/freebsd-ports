# New ports collection makefile for:	weather
# Date created:		2010-05-25
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
#
# $FreeBSD$
#

PORTNAME=	weather
PORTVERSION=	1.5
CATEGORIES=	astro python
MASTER_SITES=	http://fungi.yuggoth.org/weather/src/ \
		http://sunpoet.net/distfiles/

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	An utility to provide current weather conditions and forecasts

USE_PYTHON=	-2.6

MAN1=		weather.1
MAN5=		weatherrc.5

post-patch:
	@${REINPLACE_CMD} -e '1 s/python/${PYTHON_VERSION}/' ${WRKSRC}/weather

do-build:
	@${WRKSRC}/weather --version

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/weather ${PREFIX}/bin/
	@${INSTALL_DATA} ${WRKSRC}/weather.py ${WRKSRC}/weather.pyc ${PYTHON_SITELIBDIR}/
	@${INSTALL_MAN} ${WRKSRC}/weather.1 ${MANPREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKSRC}/weatherrc.5 ${MANPREFIX}/man/man5/

.include <bsd.port.mk>
