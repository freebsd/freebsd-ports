# New ports collection makefile for:    unrar
# Version required:     2.01
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.11 1998/09/23 01:01:20 steve Exp $
#

DISTNAME=       unrar-2.06.1
CATEGORIES=	archivers
MASTER_SITES=   ${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	utils/compress

MAINTAINER=     ache@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME}/src

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} -D_UNIX unrar.c -o unrar

do-install:
	@cd ${WRKSRC} && ${INSTALL_PROGRAM} unrar ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/unrar
	@cd ${WRKDIR}/${DISTNAME} && ${INSTALL_MAN} README.TXT LICENSE.TXT \
		${PREFIX}/share/doc/unrar
.endif

.include <bsd.port.mk>
