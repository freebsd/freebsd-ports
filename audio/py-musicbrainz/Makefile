# New ports collection makefile for:	py-musicbrainz
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	musicbrainz
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	# none
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	MusicBrainz bindings for Python

EXTRACT_DEPENDS=	${NONEXISTENT}:${LIBMUSICBRAINZ_PORTDIR}:patch
LIB_DEPENDS=	musicbrainz.3:${LIBMUSICBRAINZ_PORTDIR}

LIBMUSICBRAINZ_PORTDIR=	${PORTSDIR}/audio/libmusicbrainz

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILDARGS=	build_ext -I${LOCALBASE}/include -L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -fs `cd ${LIBMUSICBRAINZ_PORTDIR}; ${MAKE} -V WRKSRC`/python ${WRKSRC}

.include <bsd.port.post.mk>
