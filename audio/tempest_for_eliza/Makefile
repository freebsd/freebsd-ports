# New ports collection makefile for:   tempest_for_eliza
# Date created:        17 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       tempest_for_eliza
PORTVERSION=	1.0.2
CATEGORIES=     audio
MASTER_SITES=   http://www.erikyyy.de/tempest/

MAINTAINER=	greid@ukug.uk.freebsd.org

LIB_DEPENDS=	SDL-1.0.2:${PORTSDIR}/devel/sdl10

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/tempest
.for S in forelise jonny fruehling saints oldmacdonald ungarian
	${INSTALL_DATA} ${WRKSRC}/songs/$S ${PREFIX}/share/tempest
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tempest
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tempest
.endif

.include <bsd.port.mk>
