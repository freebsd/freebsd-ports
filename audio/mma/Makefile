# New ports collection makefile for:	mma
# Date created:		2007-03-10
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mma
DISTVERSION=	1.3a
#PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	http://www.mellowood.ca/${PORTNAME}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
DISTFILES=	${PORTNAME}-bin-${DISTVERSION}.tar.gz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Musical MIDI Accompaniment generator

NO_BUILD=	yes

USE_PYTHON=	2.4+

OPTIONS=	TIMIDITY	"Install timidity++ as MIDI player" Off \
		PLAYMIDI	"Install playmidi as MIDI player" Off

WRKSRC=	${WRKDIR}/${PORTNAME}-bin-${DISTVERSION}
WRKDOC=	${WRKDIR}/${PORTNAME}-pdf-${DISTVERSION:S,a,,}

CP_INSTALL_MMA=	${WRKSRC}/cp-install
FIND_FILES=	${WRKSRC} -type f -and \( -name "*.py" -or -name 'cp-install' -or -name 'mkall' \) -print0
FIND_FILES_BAK=	${WRKSRC} -type f -and \( -name "*.orig" -or -name "*.bak" \)

.if !defined (NOPORTDOCS)
DISTFILES+=	${PORTNAME}-pdf-${DISTVERSION:S,a,,}.tar.gz
.endif

.include <bsd.port.pre.mk>

XARGS_ARGS=	-0
REINPLACE_ARGS=	-i.bak -e 's,/usr/local/share/mma,${DATADIR},' \
		-e 's,/usr/local/etc,${LOCALBASE}/etc,' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},' \
		-e 's,%%PREFIX%%,${PREFIX},' \
		-e 's,/usr/bin/env python,&${PYTHON_VER},'

post-patch:
	@${FIND} ${FIND_FILES} | ${XARGS} ${XARGS_ARGS} ${REINPLACE_CMD}
	@${FIND} ${FIND_FILES_BAK} -delete
	@${TOUCH} ${WRKSRC}/includes/aria/.keepme

do-install:
	@cd ${WRKSRC} && ${CP_INSTALL_MMA}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/pdf && ${CP} ${WRKDOC}/*.pdf ${DOCSDIR}/pdf/
.endif

.if defined (WITH_TIMIDITY)
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity++
.endif

.if defined (WITH_PLAYMIDI)
RUN_DEPENDS+=	playmidi:${PORTSDIR}/audio/playmidi
.endif

.include <bsd.port.post.mk>
