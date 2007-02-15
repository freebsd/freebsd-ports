# New ports collection makefile for:	sonata
# Date created:		2007-01-22
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sonata
PORTVERSION=	1.0.1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	An elegant music player for MPD

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

USE_GETTEXT=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

RM_OPTS=	-R

OPTIONS=	MPD	"Install Music Player Daemon" on \
		TAGLIB	"Install support for editing metadata" off \
		SOAPPY	"Install support for automatic lyrics fetching" off

.include <bsd.port.pre.mk>

.if defined (WITH_MPD)
RUN_DEPENDS+=	mpd:${PORTSDIR}/audio/musicpd
.endif

.if defined (WITH_TAGLIB)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/tagpy/__init__.py:${PORTSDIR}/audio/py-tagpy
.endif

.if defined (WITH_SOAPPY)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/SOAPpy/__init__.py:${PORTSDIR}/net/py-soappy
.endif

.if defined (NOPORTDOCS)
post-install:
	${RM} ${RM_OPTS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
