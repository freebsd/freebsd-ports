# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	calendar
PORTVERSION=	2.03.2
CATEGORIES=	devel
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/915/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	jaapb@kerguelen.org
COMMENT=	A date and time library for OCaml

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes

NO_STAGE=	yes
post-install:
	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}

.include <bsd.port.mk>
