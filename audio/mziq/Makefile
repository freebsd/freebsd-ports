# New ports collection makefile for:	mziq
# Date created:			24 August 2001
# Whom:				Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mziq
PORTVERSION=	0.2.44
CATEGORIES=	audio
MASTER_SITES=	http://cseg.lucidx.com/mziq/
DISTNAME=	${PORTNAME}

MAINTAINER=	gslin@ccca.nctu.edu.tw

RUN_DEPENDS=	${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123

WRKSRC=		${WRKDIR}/MZiq

BINS=		gmziq jukebox mziq
DOCS=		LASTLOG README TODO rcfile

NO_BUILD=	yes
USE_PERL5=	yes

do-install:
.for FILE in ${BINS}
	@${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
