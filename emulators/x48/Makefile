# New ports collection makefile for:	x48
# Date created:		Thu Oct 24 13:10:59 CDT 1996
# Whom:			erich@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	x48
PORTVERSION=	0.4.1e
CATEGORIES=	emulators
MASTER_SITES=	http://www.hpcalc.org/hp48/pc/emulators/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/e//}

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README doc/CARDS.doc doc/ROMDump.doc
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
