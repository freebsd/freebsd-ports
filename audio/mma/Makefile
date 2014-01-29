# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mma
PORTVERSION=	12.02
PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	http://www.mellowood.ca/${PORTNAME}/
DISTFILES=	${PORTNAME}-bin-${PORTVERSION}.tar.gz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Musical MIDI Accompaniment generator

USES=		shebangfix
USE_PYTHON=	2
NO_STAGE=	yes

python_CMD=	${PYTHON_CMD}
python_OLD_CMD=	/usr/bin/env python
SHEBANG_FILES=	mma.py

OPTIONS_DEFINE=	TIMIDITY PLAYMIDI DOCS EXAMPLES

TIMIDITY_DESC=	Install timidity++ as MIDI player
PLAYMIDI_DESC=	Install playmidi as MIDI player

REINPLACE_ARGS=	-i.bak -e 's,%%DATADIR%%,${DATADIR},'

WRKSRC=	${WRKDIR}/${PORTNAME}-bin-${DISTVERSION}
WRKDOC=	${WRKDIR}/${PORTNAME}-pdf-${DISTVERSION:S,a,,}

MMABIN=	${PREFIX}/bin/mma

.if !defined (NO_INSTALL_MANPAGES)
MAN1=	mma.1 mma-renum.1
MAN8=	mma-libdoc.8
.endif

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
DISTFILES+=	${PORTNAME}-pdf-${DISTVERSION:S,a,,}.tar.gz
.endif

.if ${PORT_OPTIONS:MTIMIDITY}
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity++
.endif

.if ${PORT_OPTIONS:MPLAYMIDI}
RUN_DEPENDS+=	playmidi:${PORTSDIR}/audio/playmidi
.endif

post-patch:
	@${REINPLACE_CMD} ${WRKSRC}/mma.py

do-build:
	@${PYTHON_CMD} -OO -m compileall -f ${WRKSRC}/MMA

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/mma.py ${MMABIN}
.for d in lib includes MMA
	@cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR}
.endfor
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR} && cd ${WRKSRC}/egs && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/pdf && ${CP} ${WRKDOC}/*.pdf ${DOCSDIR}/pdf/ && \
	cd ${WRKSRC}/docs/html && ${COPYTREE_SHARE} . ${DOCSDIR}/html
.endif

.if !defined(NO_INSTALL_MANPAGES)
	@cd ${WRKSRC}/docs/man && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1/ && ${INSTALL_MAN} ${MAN8} ${MANPREFIX}/man/man8/
.endif

post-install:
	${MMABIN} -G

.include <bsd.port.mk>
