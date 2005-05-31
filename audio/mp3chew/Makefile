# New ports collection makefile for:   mp3chew
# Date created:        10 March 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mp3chew
PORTVERSION=	0.51.0
CATEGORIES=	audio
MASTER_SITES=	# none left
# http://owl.yi.org/ is never available
# http://froek.yi.org/ (a replacement) is never available
# the project isn't available on freshmeat.net anymore.
# informed maintainer - edwin 20021226

DEPRECATED=	"master site disappeared"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to rename mismatched and garbled MP3 filenames

WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	${PORTNAME}
USE_REINPLACE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
MAKE_ARGS=	CC="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		ARGS="${PTHREAD_LIBS} -lncurses"

PLIST_FILES=	bin/mp3chew
PORTDOCS=	CHANGELOG INSTALL README TODO

post-patch:
	@${REINPLACE_CMD} -e 's, _to, to,g' ${WRKSRC}/CMp3Filter.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mp3chew ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
