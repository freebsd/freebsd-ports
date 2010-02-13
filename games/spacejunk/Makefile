# New ports collection makefile for:	spacejunk
# Date created:		21 Jan 2010
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	spacejunk
PORTVERSION=	1.0.3
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A video game about traveling in 2D planetary systems

USE_SDL=	sdl mixer image
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="${PTHREAD_LIBS}"

SUB_FILES=	spacejunk

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' ${WRKSRC}/src/gem-uta.c \
		${WRKSRC}/libinfo/gem-uta.c
	@${REINPLACE_CMD} -e 's|data/|${DATADIR}/&|' ${WRKSRC}/src/*.c*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/spacejunk ${PREFIX}/libexec/
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} 'data config.txt' ${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/spacejunk ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${COPYTREE_SHARE} '*' ${DOCSDIR}/
.endif

.include <bsd.port.mk>
