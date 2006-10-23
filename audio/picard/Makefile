# New ports collection makefile for:	picard
# Date created:		Sat Aug 20 15:26:15 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	picard
DISTVERSION=	0.7.0
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	alexbl

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	Next generation MusicBrainzTagger

LIB_DEPENDS=	ofa.0:${PORTSDIR}/audio/libofa
RUN_DEPENDS=	\
		${PYTHON_SITELIBDIR}/tunepimp/__init__.py:${PORTSDIR}/audio/py-libtunepimp \
		${PYTHON_SITELIBDIR}/musicbrainz2/__init__.py:${PORTSDIR}/audio/py-musicbrainz2

USE_WX=		2.6
WX_COMPS=	python_run
WX_UNICODE=	yes

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	systems prior to FreeBSD 5.0 do not support Unicode
.endif

.include <bsd.port.post.mk>
