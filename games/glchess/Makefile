# New ports collection makefile for:	glchess
# Date created:				Wed Jul 18 08:35:56 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	glchess
PORTVERSION=	0.4.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@FreeBSD.org

RUN_DEPENDS=	crafty:${PORTSDIR}/games/crafty \
		gnuchess:${PORTSDIR}/games/gnuchess
LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USE_X_PREFIX=	yes
USE_GTK=	yes
USE_MESA=	yes
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"

MAN6=		${PORTNAME}.6

pre-patch:
	@${PERL} -pi.orig -e 's!/usr/local/share/games/glchess!${DATADIR}!' \
		${WRKSRC}/../glchessrc
	@${PERL} -pi.orig -e 's!/etc!${PREFIX}/etc!' \
		${WRKSRC}/config.c
	@${PERL} -pi.orig -e 's|VERSION|\"${PORTVERSION}\"|' \
		${WRKSRC}/dialog.c ${WRKSRC}/interface.c
	@${PERL} -pi.orig -e 's|VERSION|${PORTVERSION}|; \
		s|\"DATE\"||' ${WRKSRC}/../man/${PORTNAME}.6
	@${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/textures
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/../glchessrc \
		${PREFIX}/etc
	@${INSTALL_MAN} ${WRKSRC}/../man/${PORTNAME}.6 \
		${PREFIX}/man/man6
	@${INSTALL_DATA} ${WRKSRC}/../textures/*.rgb \
		${DATADIR}/textures
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README TODO
	@${INSTALL_DATA} ${WRKSRC}/../${file} ${DOCSDIR}
.endfor
.endif #NOPORTDOCS

.include <bsd.port.mk>
