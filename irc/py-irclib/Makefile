# New ports collection makefile for:	py-irclib
# Date created:				25 April 2001
# Whom:					Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	irclib
PORTVERSION=	0.4.8
CATEGORIES=	irc python
MASTER_SITES=	SF/python-${PORTNAME}/python-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-irclib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC protocol client library for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PYDISTUTILS_PKGNAME=	python-irclib
EXAMPLEFILES=	irccat irccat2 servermap testbot.py \
		dccreceive dccsend
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

.if !defined(NOPORTEXAMPLES)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLEFILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${EXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
