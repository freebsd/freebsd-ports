# Created by: Eugene Ossintsev
# $FreeBSD$

PORTNAME=	ocaml
PORTVERSION=	3.12.1
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/distrib/${DISTNAME:R}/ \
		ftp://ftp.inria.fr/INRIA/caml-light/${DISTNAME:R}/ \
		ftp://ftp.kurims.kyoto-u.ac.jp/pub/lang/caml-light/${DISTNAME:R}/
PKGNAMESUFFIX=	-doc
DISTFILES=	${DISTNAME}-refman-html.tar.gz \
		${DISTNAME:R}-refman.ps.gz \
		${DISTNAME:R}-refman.pdf
EXTRACT_ONLY=	${DISTNAME}-refman-html.tar.gz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Documentation (HTML, PS) for the Objective Caml

NO_BUILD=	yes

PORTDOCS=	${DISTNAME:R}-refman.ps \
		${DISTNAME:R}-refman.pdf \
		html

.ifdef(NOPORTDOCS)
IGNORE=		installs only documentation and you have NOPORTDOCS defined
.endif

do-install:
	@${MKDIR} ${DOCSDIR}/html/libref
	cd ${WRKDIR}/htmlman/libref && ${INSTALL_DATA} * ${DOCSDIR}/html/libref
	cd ${WRKDIR}/htmlman && ${INSTALL_DATA} [a-km-z]* libg* ${DOCSDIR}/html
	cp ${DISTDIR}/${DISTNAME:R}-refman.ps.gz ${WRKDIR}
	${GUNZIP_CMD} ${WRKDIR}/${DISTNAME:R}-refman.ps.gz
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME:R}-refman.ps ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME:R}-refman.pdf ${DOCSDIR}

.include <bsd.port.mk>
