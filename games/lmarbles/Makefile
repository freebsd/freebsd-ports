# New ports collection makefile for:	marbles
# Date created:		12 June 2002
# Whom:			verm@drunkmonk.net
#
# $FreeBSD$
#

PORTNAME=	lmarbles
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/lgames/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A challenging puzzle game similar to Atomix

USE_SDL=	sdl mixer
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${DATADIR}

MAN6=		${PORTNAME}.6

post-patch:
	@${REINPLACE_CMD} -e 's|(datadir)/icons|(datadir)/pixmaps|g' \
		${WRKSRC}/Makefile.in

post-install:
	@${CHMOD} 2755 ${PREFIX}/bin/${PORTNAME}
	@${CHOWN} root:games ${PREFIX}/bin/${PORTNAME}
	@${CHMOD} 0664 ${DATADIR}/${PORTNAME}.prfs
	@${CHOWN} root:games ${DATADIR}/${PORTNAME}.prfs
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/manual/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
