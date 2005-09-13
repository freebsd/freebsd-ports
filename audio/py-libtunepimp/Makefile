# New ports collection makefile for:	tunepimp python bindings
# Date created:		Sat Aug 20 15:26:15 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	libtunepimp
DISTVERSION=	0.4.0-pre5
CATEGORIES=	audio python
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/picard/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	lauri@kde.org
COMMENT=	tunepimp python bindings

BUILD_DEPENDS=	${LOCALBASE}/lib/libtunepimp.so:${PORTSDIR}/audio/libtunepimp
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python

.include <bsd.port.mk>
