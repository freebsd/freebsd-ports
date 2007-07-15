# New ports collection makefile for: wyrd
# Date created:                      Apr 5 2006
# Whom:                              Russell A. Jackson <raj@csub.edu>
#
# $FreeBSD$
#

PORTNAME=	wyrd
PORTVERSION=	1.4.2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.eecs.umich.edu/~pelzlpj/wyrd/

MAINTAINER=	raj@csub.edu
COMMENT=	A curses front end to remind

BUILD_DEPENDS=	${LOCALBASE}/bin/ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS=	${LOCALBASE}/bin/remind:${PORTSDIR}/deskutils/remind

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=	wyrd.1
MAN5=	wyrdrc.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wyrd.opt ${PREFIX}/bin/wyrd
	${INSTALL_DATA} ${WRKSRC}/wyrdrc ${PREFIX}/etc/wyrdrc
	${INSTALL_MAN} ${WRKSRC}/doc/wyrd.1 ${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/wyrdrc.5 ${MAN5PREFIX}/man/man5

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual.html ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/manual.pdf ${DOCSDIR}/
.endif

.include <bsd.port.mk>
