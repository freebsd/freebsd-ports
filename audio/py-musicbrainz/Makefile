# New ports collection makefile for:	py-musicbrainz
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	musicbrainz
PORTVERSION=	1.0.b1
PORTEPOCH=	1
CATEGORIES=	audio python
MASTER_SITES=	http://icepick.info/projects/python-musicbrainz/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	MusicBrainz bindings for Python

BUILD_DEPENDS=	${PYTHONPREFIX_SITELIBDIR}/ctypes/__init__.py:${PORTSDIR}/devel/py-ctypes
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	musicbrainz.4:${LIBMUSICBRAINZ_PORTDIR}

LIBMUSICBRAINZ_PORTDIR=	${PORTSDIR}/audio/libmusicbrainz
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}
EXAMPLES=	cd2trm.py findartist.py getcdtracklengths.py cdid.py \
		findtrack.py gettrm.py cdlookup.py generatetrm.py \
		fileinfolookup.py getalbum.py

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_BUILDARGS=	build_ext -I${LOCALBASE}/include -L${LOCALBASE}/lib

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/musicbrainz.py \
		%%PYTHON_SITELIBDIR%%/musicbrainz.pyc \
		%%PYTHON_SITELIBDIR%%/musicbrainz.pyo

.ifndef(NOPORTDOCS)
PLIST_FILES+=	${EXAMPLES:S/^/%%EXAMPLESDIR%%\//}
PLIST_DIRS=	%%EXAMPLESDIR%%
.endif

post-install:
.ifndef(NOPORTDOCS)
		${MKDIR} ${EXAMPLESDIR}
.for i in ${EXAMPLES}
		${INSTALL_SCRIPT} ${WRKSRC}/examples/${i} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
