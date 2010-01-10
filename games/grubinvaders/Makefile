# New ports collection makefile for:	grubinvaders
# Date created:        			13 April 2002
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grubinvaders
PORTVERSION=	1.0.0
CATEGORIES=	games
MASTER_SITES=	http://www.erikyyy.de/invaders/
DISTNAME=	invaders-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi boot compliant game for i386

RUN_DEPENDS=	${LOCALBASE}/sbin/grub:${PORTSDIR}/sysutils/grub

MAKEFILE=	${FILESDIR}/Makefile
ONLY_FOR_ARCHS=	i386
STRIP=
WRKSRC=		${WRKDIR}/invaders
ALL_TARGET=	clean all
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/invaders ${DATADIR}

.include <bsd.port.mk>
