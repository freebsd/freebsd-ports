# New ports collection makefile for:	mziq
# Date created:			24 August 2001
# Whom:				Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mziq
PORTVERSION=	0.3
CATEGORIES=	audio
MASTER_SITES=	http://cseg.lucidx.com/projects/src/mziq/

MAINTAINER=	gslin@ccca.nctu.edu.tw

RUN_DEPENDS=	${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123

WRKSRC=		${WRKDIR}/MZiq

NO_BUILD=	yes
USE_PERL5=	yes

do-install:
.for FILE in gmziq jukebox mziq
	@${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for FILE in README TODO default.mz example.mz rcfile
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
