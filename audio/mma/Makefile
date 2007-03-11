# New ports collection makefile for:	mma
# Date created:		2007-03-10
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mma
PORTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	http://www.mellowood.ca/${PORTNAME}/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
DISTFILES=	${PORTNAME}-bin-${PORTVERSION}.tar.gz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Musical MIDI Accompaniment generator

NO_BUILD=	yes

USE_PYTHON=	2.4+

OPTIONS=	TIMIDITY	"Install timidity++ as MIDI player" On \
		PLAYMIDI	"Install playmidi as MIDI player" Off

WRKSRC=	${WRKDIR}/${PORTNAME}-bin-${PORTVERSION}
WRKDOC=	${WRKDIR}/${PORTNAME}-pdf-${PORTVERSION}

CP_INSTALL_MMA=	${WRKSRC}/cp-install
FIND_FILES=	${WRKSRC} -type f -and \( -name "*.py" -or -name 'cp-install' -or -name 'mkall' \)
FIND_FILES_BAK=	${WRKSRC} -type f -and \( -name "*.orig" -or -name "*.bak" \)
FIND_DOCS=	. -type f -name "*.pdf"

.if !defined (NOPORTDOCS)
DISTFILES+=	${PORTNAME}-pdf-${PORTVERSION}.tar.gz
.endif


PLIST_SUB=	PORTEXAMPLES=${PORTEXAMPLES}

post-patch:
	@${FIND} ${FIND_FILES} -exec ${REINPLACE_CMD} \
	    -e 's,/usr/local/share/mma,${DATADIR},' \
	    -e 's,/usr/local/etc,${LOCALBASE}/etc,' \
	    -e 's,%%DOCSDIR%%,${DOCSDIR},' \
	    -e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},' \
	    -e 's,%%PREFIX%%,${PREFIX},' \
	    -e 's,#!/usr/bin/env python,&${PYTHON_VER},' {} ";"
	@${FIND} ${FIND_FILES_BAK} -delete
	@${TOUCH} ${WRKSRC}/includes/aria/.keepme

do-install:
	@cd ${WRKSRC} && ${ENV} NOPORTDOCS=${NOPORTDOCS} WITHOUT_EXAMPLES=${WITHOUT_EXAMPLES} ${CP_INSTALL_MMA}
.if !defined(NOPORTDOCS)
	@cd ${WRKDOC} && ${MKDIR} ${DOCSDIR}/pdf && ${FIND} ${FIND_DOCS} -exec ${INSTALL_DATA} {} ${DOCSDIR}/pdf/ ";"
.endif

.include <bsd.port.pre.mk>

.if defined (WITHOUT_EXAMPLES)
PORTEXAMPLES=	"@comment "
.else
PORTEXAMPLES=	""
.endif

.if defined (WITH_TIMIDITY)
RUN_DEPENDS+=	timidity:${PORTSDIR}/audio/timidity++
.endif

.if defined (WITH_PLAYMIDI)
RUN_DEPENDS+=	playmidi:${PORTSDIR}/audio/playmidi
.endif

.include <bsd.port.post.mk>
