# New ports collection makefile for:	mma
# Date created:		2007-03-10
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mma
DISTVERSION=	1.7
PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	http://www.mellowood.ca/${PORTNAME}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
DISTFILES=	${PORTNAME}-bin-${DISTVERSION}.tar.gz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Musical MIDI Accompaniment generator

USE_PYTHON=	2.5+

OPTIONS=	TIMIDITY	"Install timidity++ as MIDI player" Off \
		PLAYMIDI	"Install playmidi as MIDI player" Off

REINPLACE_ARGS=	-i.bak -e 's,%%DATADIR%%,${DATADIR},'

WRKSRC=	${WRKDIR}/${PORTNAME}-bin-${DISTVERSION}
WRKDOC=	${WRKDIR}/${PORTNAME}-pdf-${DISTVERSION:S,a,,}

MMABIN=	${PREFIX}/bin/mma

.if !defined (NOPORTDOCS)
DISTFILES+=	${PORTNAME}-pdf-${DISTVERSION:S,a,,}.tar.gz
.if !defined (NO_INSTALL_MANPAGES)
MAN1=	mma.1 mma-renum.1
MAN8=	mma-libdoc.8
.endif
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
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR} && cd ${WRKSRC}/egs && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/pdf && ${CP} ${WRKDOC}/*.pdf ${DOCSDIR}/pdf/ && \
	cd ${WRKSRC}/docs/html && ${COPYTREE_SHARE} . ${DOCSDIR}/html
.if !defined(NO_INSTALL_MANPAGES)
	@cd ${WRKSRC}/docs/man && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1/ && ${INSTALL_MAN} ${MAN8} ${MANPREFIX}/man/man8/
.endif
.endif

post-install:
	${MMABIN} -G

.include <bsd.port.pre.mk>

.if defined (WITH_TIMIDITY)
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity++
.endif

.if defined (WITH_PLAYMIDI)
RUN_DEPENDS+=	playmidi:${PORTSDIR}/audio/playmidi
.endif

.include <bsd.port.post.mk>
