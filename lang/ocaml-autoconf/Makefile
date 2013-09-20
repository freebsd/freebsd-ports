# Created by: stas
# $FreeBSD$

PORTNAME=	autoconf
PORTVERSION=	1.1
CATEGORIES=	lang
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/181/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Autoconf module for ocaml

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}-1.0

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
AC_SUBDIR=	${PREFIX}/share/aclocal
PLIST_FILES=	share/aclocal/ocaml.m4

.if !defined(NOPORTDOCS)
PORTDOCS=	ocaml.m4.txt
.endif

NO_STAGE=	yes
do-install:
	${MKDIR} ${AC_SUBDIR}/
	${INSTALL_DATA} ${WRKSRC}/ocaml.m4 ${AC_SUBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/ocaml.m4.txt ${DOCSDIR}/
.endif

.include <bsd.port.mk>
