# New ports collection makefile for:	mziq
# Date created:			24 August 2001
# Whom:				Gea-Suan Lin <gslin@ccca.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mziq
PORTVERSION=	0.4.2
CATEGORIES=	audio
MASTER_SITES=	http://cseg.lucidx.com/projects/src/mziq/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Perl frontend to mpg123

RUN_DEPENDS=	${LOCALBASE}/bin/mpg123:${PORTSDIR}/audio/mpg123

WRKSRC=		${WRKDIR}/MZiq

NO_BUILD=	yes
USE_PERL5=	yes

PORTDOCS=	${DOC_FILES}
PLIST_FILES=	bin/gmziq bin/jukebox bin/mziq

DOC_FILES=	README TODO default.mz example.mz rcfile

do-install:
.for FILE in gmziq jukebox mziq
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
