# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mma
PORTVERSION=	14.07
PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	http://www.mellowood.ca/${PORTNAME}/
DISTFILES=	${PORTNAME}-bin-${PORTVERSION}.tar.gz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Musical MIDI Accompaniment generator

LICENSE=	GPLv2

RUN_DEPENDS=	aplaymidi:${PORTSDIR}/audio/alsa-utils \
		timidity:${PORTSDIR}/audio/timidity++

MMABIN=	${PREFIX}/bin/mma

OPTIONS_DEFINE=	DOCS EXAMPLES

REINPLACE_ARGS=	-i.bak -E -e 's,/usr(/bin/(aplaymidi|arecord|timidity)),${LOCALBASE}\1,g'

SHEBANG_FILES=	mma.py
SUB_FILES=	mma_g.py
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

USES=		shebangfix
USE_PYTHON=	yes

WRKDOC=	${WRKDIR}/${PORTNAME}-pdf-${DISTVERSION:S,a,,}
WRKSRC=	${WRKDIR}/${PORTNAME}-bin-${DISTVERSION}

python_CMD=	${PYTHON_CMD}
python_OLD_CMD=	/usr/bin/env python

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${PORTNAME}-pdf-${DISTVERSION:S,a,,}.tar.gz
.endif

post-patch:
	@(cd ${WRKSRC} && \
	${REINPLACE_CMD} mma-splitrec util/mma-splitrec.py)

do-build:
	@${PYTHON_CMD} -O -m compileall -f ${WRKSRC}/MMA
	@${PYTHON_CMD} -OO -m compileall -f ${WRKSRC}/MMA

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/mma.py ${STAGEDIR}${MMABIN}
.for d in lib includes MMA
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR} "-not -name *\.bak"
.endfor
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/egs && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/pdf
	(cd ${WRKDOC} && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/pdf/ "! -name README")
	(cd ${WRKSRC}/docs/html && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/html)
	(cd ${WRKSRC}/docs/man && \
	${COPYTREE_SHARE} . ${STAGEDIR}${MANPREFIX}/man/man1/ "! -name mma-libdoc.8" && \
	${INSTALL_MAN} mma-libdoc.8 ${STAGEDIR}${MANPREFIX}/man/man8/)

post-install:
	# update mma library (mma -g) to use ${DATADIR} path
	@(cd ${STAGEDIR}${DATADIR} && \
	${PYTHON_CMD} ${WRKDIR}/mma_g.py)

.include <bsd.port.mk>
