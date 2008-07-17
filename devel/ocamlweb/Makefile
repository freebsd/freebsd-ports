# New ports collection makefile for:	ocamlweb
# Date created:				4 February 2001
# Whom:					Patrick Doane <patrick@watson.org>
#
# $FreeBSD$
#

PORTNAME=	ocamlweb
PORTVERSION=	1.34
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.lri.fr/~filliatr/ftp/ocamlweb/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTDOCS}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.ORG
COMMENT=	A literate programming tool for Objective Caml

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base

GNU_CONFIGURE= yes
PLIST_SUB+=	TEXMFDIR=${TEXMFDIR} \
		MKTEXLSR=${MKTEXLSR}

TEXMFDIR?=	share/texmf
MKTEXLSR?=	${LOCALBASE}/bin/mktexlsr

.if !defined(NOPORTDOCS)
PORTDOCS=	${PORTNAME}-${PORTVERSION}-man.ps.gz
.endif

MAN1=		ocamlweb.1

post-install:
	${MKTEXLSR} ${PREFIX}/${TEXMFDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DISTDIR}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
