# New ports collection makefile for:	py-irclib
# Date created:				25 April 2001
# Whom:					Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	irclib
PORTVERSION=	0.4.4
CATEGORIES=	irc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	python-irclib
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-irclib-${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	IRC protocol client library for Python

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
EXAMPLEFILES=	irccat irccat2 servermap testbot.py \
		dccreceive dccsend

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
.for file in ${EXAMPLEFILES}
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${EXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
