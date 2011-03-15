# New ports collection makefile for:    sced
# Date created:         27  Dec 1996
# Whom:                 proff@iq.org
#
# $FreeBSD$
#

PORTNAME=	sced
PORTVERSION=	1.03
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.wisc.edu/~schenney/sced/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCene EDitor for povray/renderman/genray/etc

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray

USE_XORG=	x11 xt xaw
GNU_CONFIGURE=	yes

MAN1=		sced.1

do-install:
	${INSTALL_PROGRAM}  ${WRKSRC}/sced ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/sced.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/sced
	${INSTALL_DATA} ${WRKSRC}/scenerc ${PREFIX}/share/sced/sample.scenerc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/sced
	${INSTALL_DATA} ${WRKSRC}/docs/guide.* ${PREFIX}/share/doc/sced
.endif

.include <bsd.port.mk>
