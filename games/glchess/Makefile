# New ports collection makefile for:	glchess
# Date created:				Wed Jul 18 08:35:56 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	glchess
PORTVERSION=	0.3.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org

RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty \
		gnuchess:${PORTSDIR}/games/gnuchess
LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
USE_MESA=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

MAN6=		${PORTNAME}.6
MANCOMPRESSED=	yes

pre-patch:
	@${PERL} -pi.orig -e 's!/usr/local/share/games/glchess!${DATADIR}!' \
		${WRKSRC}/glchessrc
	@${PERL} -pi.orig -e 's!/etc!${PREFIX}/etc!' \
		${WRKSRC}/src/config.c

do-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/textures
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/glchessrc \
		${PREFIX}/etc
	@${INSTALL_MAN} ${WRKSRC}/man/glchess.6.gz \
		${PREFIX}/man/man6
	@${INSTALL_DATA} ${WRKSRC}/textures/* \
		${DATADIR}/textures
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README TODO
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif #NOPORTDOCS

.include <bsd.port.mk>
