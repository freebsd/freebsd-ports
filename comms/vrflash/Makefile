# New ports collection makefile for:	vrflash
# Date created:				07.Jul 2001
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	vrflash
PORTVERSION=	0.20
CATEGORIES=	comms
MASTER_SITES=	http://www.apex.net/~jeff/agenda-utils/vrflash-unix/

MAINTAINER=	dinoex@FreeBSD.org

GNU_CONFIGURE=	yes
DOCS=		agenda-flashing-overview.txt troubleshooting.txt \
		pmon-protect-unprotect.txt usage.txt

do-install:
	${INSTALL_PROGRAM} -m 755 ${WRKSRC}/vrflash ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
