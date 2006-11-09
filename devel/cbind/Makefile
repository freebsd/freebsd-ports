# New ports collection makefile for:   cbind
# Date created:        23 December 2002
# Whom:                David Holm <david@realityrift.com>
#
# $FreeBSD$
#

PORTNAME=	cbind
PORTVERSION=	6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.kuleuven.ac.be/pub/Ada-Belgium/cdrom/ase02_02/tools/cbind/ \
			   ftp://ftp.cnam.fr/pub2/Ada/PAL/swtools/cbind/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	david@realityrift.com
COMMENT=	Translator for "thin" Ada bindings to C

USE_ZIP=	yes

MAN1=		cbind.1

${WRKSRC}=	${WRKDIR}/${PORTNAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cbind ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/cbfe ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/cbpp ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/cbind.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DESTDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/DOCS ${DESTDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
