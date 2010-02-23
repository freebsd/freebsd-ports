# New ports collection makefile for:	ocaml-doc
# Date created:		2004-02-03
# Whom:			Eugene Ossintsev
#
# $FreeBSD$
#

PORTNAME=	ocaml
PORTVERSION=	3.11
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/distrib/${DISTNAME}/ \
		ftp://ftp.inria.fr/INRIA/caml-light/${DISTNAME}/ \
		ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/caml-light/${DISTNAME}/
PKGNAMESUFFIX=	-doc
DISTFILES=	${DISTNAME}-refman.html.tar.gz \
		${DISTNAME}-refman.ps.gz \
		${DISTNAME}-refman.pdf
EXTRACT_ONLY=	${DISTNAME}-refman.html.tar.gz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Documentation (HTML, PS) for the Objective Caml

NO_BUILD=	yes

PORTDOCS=	*

.ifdef(NOPORTDOCS)
IGNORE=		installs only documentation and you have NOPORTDOCS defined
.endif

do-install:
	@${MKDIR} ${DOCSDIR}/html/libref
	cd ${WRKDIR}/htmlman/libref && ${INSTALL_DATA} * ${DOCSDIR}/html/libref
	cd ${WRKDIR}/htmlman && ${INSTALL_DATA} [a-km-z]* libg* ${DOCSDIR}/html
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}-refman.ps.gz ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}-refman.pdf ${DOCSDIR}

.include <bsd.port.mk>
