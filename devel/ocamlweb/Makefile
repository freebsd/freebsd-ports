# New ports collection makefile for:	ocamlweb
# Date created:				4 February 2001
# Whom:					Patrick Doane <patrick@watson.org>
#
# $FreeBSD$
#

PORTNAME=	ocamlweb
PORTVERSION=	0.9
CATEGORIES=	devel
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/ocamlweb/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	patrick@watson.org

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

GNU_CONFIGURE= yes

.if !defined(NOPORTDOCS)
DOCFILES=	${PORTNAME}-man.ps.gz
.endif

post-install:
.if !defined{NOPORTDOCS}
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_MAN} ${DISTDIR}/${PORTNAME}-man.ps.gz ${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
