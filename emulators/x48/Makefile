# New ports collection makefile for:	x48
# Date created:		Thu Oct 24 13:10:59 CDT 1996
# Whom:			erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	x48
PORTVERSION=	0.4.1
CATEGORIES=	emulators
MASTER_SITES=	http://home.earthlink.net/~rmmlgetz/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/x48
.for file in README doc/CARDS.doc doc/ROMDump.doc
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/x48
.endfor
.endif

.include <bsd.port.mk>
