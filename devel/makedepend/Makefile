# New ports collection makefile for:		makedepend
# Version required:				95.07.05
# Date created:					August 15th 1997
# Whom:						Ian Vaudrey
#
# $Id$
#

DISTNAME=	cyrus-imapd-v1.5.2
PKGNAME=	makedepend-95.07.05
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=	i.vaudrey@cableinet.co.uk

WRKSRC=		${WRKDIR}/${DISTNAME}/makedepend
GNU_CONFIGURE=	YES

MAN1=		makedepend.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/makedepend ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mkdepend.man ${PREFIX}/man/man1/makedepend.1

.include <bsd.port.mk>
