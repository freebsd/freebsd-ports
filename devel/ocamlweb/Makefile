# New ports collection makefile for:	ocamlweb
# Date created:				4 February 2001
# Whom:					Patrick Doane <patrick@watson.org>
#
# $FreeBSD$
#

PORTNAME=	ocamlweb
PORTVERSION=	1.31
CATEGORIES=	devel
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/ocamlweb/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jkoshy@FreeBSD.ORG

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX

GNU_CONFIGURE= yes

.if !defined(NOPORTDOCS)
DOCFILES=	${PORTNAME}-${PORTVERSION}-man.ps.gz
.endif

MAN1=		ocamlweb.1

post-install:
.if !defined{NOPORTDOCS}
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-man.ps.gz ${DOCSDIR}
.endif

.include <bsd.port.mk>
