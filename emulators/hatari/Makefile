# New ports collection makefile for:    hatari
# Date created:         15 March 2004
# Whom:                 Michael Neumann <mneumann@ntecs.de>
#
# $FreeBSD$
#

PORTNAME=	hatari
PORTVERSION=	0.95
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Atari ST emulator

USE_GNOME=	gnometarget
USE_SDL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR}

MAN1=		hatari.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/hatari.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/images/*.png ${DOCSDIR}/images
.endif

.include <bsd.port.mk>
