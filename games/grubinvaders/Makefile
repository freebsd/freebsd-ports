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

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	This is grubinvaders, a multi boot compliant game for i386

RUN_DEPENDS=	${LOCALBASE}/sbin/grub:${PORTSDIR}/sysutils/grub

MAKEFILE=	${FILESDIR}/Makefile
ONLY_FOR_ARCHS=	i386
STRIP=
WRKSRC=		${WRKDIR}/invaders
ALL_TARGET=	clean all

do-install:
	${MKDIR} ${PREFIX}/share/grubinvaders
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/grubinvaders
	${INSTALL_PROGRAM} ${WRKSRC}/invaders ${PREFIX}/share/grubinvaders
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
