# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mma
PORTVERSION=	15.12
PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	http://www.mellowood.ca/${PORTNAME}/
DISTFILES=	${PORTNAME}-bin-${PORTVERSION}.tar.gz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Musical MIDI Accompaniment generator

LICENSE=	GPLv2

RUN_DEPENDS=	aplaymidi:audio/alsa-utils \
		timidity:audio/timidity++

MMABIN=	${PREFIX}/bin/mma

NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

REINPLACE_ARGS=	-i.bak -E -e 's,/usr(/bin/(aplaymidi|arecord|timidity)),${LOCALBASE}\1,g'

SHEBANG_FILES=	mma.py
SUB_FILES=	mma_g.py
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

USES=		python shebangfix

WRKDOC=	${WRKDIR}/${PORTNAME}-pdf-${DISTVERSION:S,a,,}
WRKSRC=	${WRKDIR}/${PORTNAME}-bin-${DISTVERSION}

DOCS_DISTFILES=	${PORTNAME}-pdf-${DISTVERSION:S,a,,}.tar.gz

post-patch:
	@(cd ${WRKSRC} && \
	${REINPLACE_CMD} mma-splitrec util/mma-splitrec.py)

do-build:
	@${PYTHON_CMD} -O -m compileall -f ${WRKSRC}/MMA
	@${PYTHON_CMD} -OO -m compileall -f ${WRKSRC}/MMA

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/mma.py ${STAGEDIR}${MMABIN}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "lib includes MMA" ${STAGEDIR}${DATADIR} "-not -name *\.bak"
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/egs && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
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
