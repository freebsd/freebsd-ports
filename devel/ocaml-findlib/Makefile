# ex:ts=8
# Ports collection makefile for:	findlib
# Date created:			Jul 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	findlib
PORTVERSION=	1.0.3
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.ocaml-programming.de/packages/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	stephane@FreeBSD.org
COMMENT=	OCaml package manager

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/ocamlfind etc/findlib.conf

MAN1=	ocamlfind.1
MAN5=	META.5 findlib.conf.5 site-lib.5

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/findlib -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}

# this list comes from the findlib configure script
.for D in dbm dynlink graphics num num-top str threads unix stdlib bigarray labltk camlp4
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/$D -type f -name META | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
.endfor

	@${FIND} ${PREFIX}/lib/ocaml/site-lib/findlib -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
