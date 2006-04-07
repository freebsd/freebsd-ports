# New ports collection makefile for:	py-musicbrainz
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	musicbrainz
PORTVERSION=	2.1.2
PORTEPOCH=	1
CATEGORIES=	audio python
MASTER_SITES=	ftp://ftp.musicbrainz.org/pub/musicbrainz/ \
		ftp://ftp.au.musicbrainz.org/pub/musicbrainz/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	libmusicbrainz-${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	MusicBrainz bindings for Python

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/ctypes/__init__.py:${PORTSDIR}/devel/py-ctypes
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz

EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
EXAMPLES=	cd2trm.py cdid.py cdlookup.py fileinfolookup.py findartist.py \
		findtrack.py generatetrm.py getalbum.py getcdtracklengths.py \
		gettrm.py

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILDARGS=	build_ext -I${LOCALBASE}/include -L${LOCALBASE}/lib

DESCR=		${PORTSDIR}/audio/libmusicbrainz/pkg-descr
MD5_FILE=	${PORTSDIR}/audio/libmusicbrainz/distinfo
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/musicbrainz.py \
		%%PYTHON_SITELIBDIR%%/musicbrainz.pyc \
		%%PYTHON_SITELIBDIR%%/musicbrainz.pyo

.ifndef(NOPORTDOCS)
PLIST_FILES+=	${EXAMPLES:S|^|%%EXAMPLESDIR%%/|}
PLIST_DIRS=	%%EXAMPLESDIR%%
.endif

WRKSRC=		${WRKDIR}/libmusicbrainz-${PORTVERSION}/python

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${EXAMPLES:S|^|${WRKSRC}/examples/|} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
