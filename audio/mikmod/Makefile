# New ports collection makefile for:	mikmod
# Version required:	2.14
# Date created:		20 April 1997
# Whom:			doconnor@ist.flinders.edu.au
#
# $Id$
#

DISTNAME=	mikmod-2.14-unix
PKGNAME=	mikmod-2.14
CATEGORIES=	audio
MASTER_SITES=	http://www.chiark.greenend.org.uk/~stevem/mikmod/

MAINTAINER=	doconnor@ist.flinders.edu.au

WRKSRC=		${WRKDIR}/${DISTNAME}/source
MAN1=		mikmod.1

do-install:
	( cd ${WRKSRC} ; ${INSTALL_PROGRAM} mikmod mikcvt ${PREFIX}/bin )
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/docs/mikmod.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
