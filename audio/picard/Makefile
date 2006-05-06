# New ports collection makefile for:	picard
# Date created:		Sat Aug 20 15:26:15 UTC 2005
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	picard
DISTVERSION=	0.6.0
CATEGORIES=	audio python
MASTER_SITES=	https://helixcommunity.org/download.php/1791/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Next generation MusicBrainzTagger

RUN_DEPENDS=	\
		${PYTHON_SITELIBDIR}/tunepimp/__init__.py:${PORTSDIR}/audio/py-libtunepimp \
		${PYTHON_SITELIBDIR}/musicbrainz.py:${PORTSDIR}/audio/py-musicbrainz \
		${PYTHON_SITELIBDIR}/wx-2.6-gtk2-unicode/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython26-unicode

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

SOURCEFILE=	${DISTNAME}${EXTRACT_SUFX}
PICARD_MODULES=	browser lib ui

post-extract:
# build a fake module directory structure
	@${MKDIR} ${WRKSRC}/${PORTNAME}
.for dir in ${PICARD_MODULES}
	@${MV} ${WRKSRC}/${dir} ${WRKSRC}/${PORTNAME}
.endfor
# use a locally made __init__.py to enable the fake
# directory structure to work
	@${SED} -E \
		-e 's|%%VERSION%%|${DISTVERSION}|' \
		${FILESDIR}/__init__.py \
		> ${WRKSRC}/${PORTNAME}/__init__.py
# use a locally made setup
	@${CP} ${FILESDIR}/setup.py ${WRKSRC}

post-patch:
# avoid using such a generic script name
	@${MV} ${WRKSRC}/tagger.py ${WRKSRC}/mb_tagger.py
# update the launch script
	@${REINPLACE_CMD} -E \
		-e 's|/usr/bin/env python|${PYTHON_CMD}|' \
		-e 's|tagger.py|${PREFIX}/bin/mb_tagger.py|' \
		${WRKSRC}/MBTagger
# update modules to the fake module directory structure
.for module in ${PICARD_MODULES}
	@${FIND} ${WRKSRC}/ -type f -name "*py" \
		-print0 | ${XARGS} -0 -n 1 \
		${REINPLACE_CMD} -E \
		-e 's|^from[[:space:]]+(${module})|from ${PORTNAME}.\1|'
.endfor

post-install:
	@${LN} -sf MBTagger ${PREFIX}/bin/${PORTNAME}

pre-everything::
.ifndef(WITHOUT_PSYCO)
	@${ECHO_MSG} '===> Define WITHOUT_PSYCO to disable devel/py-psyco optimization'
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	systems prior to FreeBSD 5.0 do not support Unicode
.endif

.if ${ARCH} != "i386"
WITHOUT_PSYCO=	yes
.endif

.ifndef(WITHOUT_PSYCO)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco

EXTRA_PATCHES+=	${FILESDIR}/extra-psyco-patch-tagger.py
.endif

.include <bsd.port.post.mk>
