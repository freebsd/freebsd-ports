# New ports collection makefile for:   mp3chew
# Date created:        10 March 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       mp3chew
PORTVERSION=	0.51.0
CATEGORIES=     audio
MASTER_SITES=	# none left
# http://owl.yi.org/ is never available
# http://froek.yi.org/ (a replacement) is never available
# the project isn't available on freshmeat.net anymore.
# informed maintainer - edwin 20021226

MAINTAINER=	greid@ukug.uk.freebsd.org

WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	${PORTNAME}
USE_REINPLACE=	yes

DOCFILES=	CHANGELOG INSTALL README TODO

post-patch:
	@${REINPLACE_CMD} -e 's, _to, to,g' ${WRKSRC}/CMp3Filter.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3chew ${PREFIX}/bin
.if !defined(NOPORTDOCS)
.for D in ${DOCFILES}
	${MKDIR} ${PREFIX}/share/doc/mp3chew
	${INSTALL_DATA} ${WRKSRC}/docs/$D ${PREFIX}/share/doc/mp3chew
.endfor
.endif

.include <bsd.port.mk>
