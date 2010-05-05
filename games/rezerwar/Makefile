# New ports collection makefile for:	rezerwar
# Date created:		09 Jul 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rezerwar
PORTVERSION=	0.4.1
CATEGORIES=	games
MASTER_SITES=	http://tamentis.com/projects/rezerwar/files/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Puzzle game involving organizing blocks with pipes

USE_GMAKE=	yes
USE_SDL=	sdl mixer
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	Unix
MAKE_JOBS_SAFE=	yes
CONFIGURE_ENV=	TARGET_BIN=${PREFIX}/bin \
		TARGET_DOC=${DOCSDIR} \
		TARGET_DATA=${DATADIR}

PORTDOCS=	*

.if defined(NOPORTDOCS)
post-patch:
	@${REINPLACE_CMD} -e '/TARGET_DOC/ d' ${WRKSRC}/mkfiles/Makefile.main
.endif

.include <bsd.port.mk>
