# ex:ts=8
# Ports collection makefile for:	findlib
# Date created:			Jul 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	findlib
PORTVERSION=	1.0.4
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	http://www.ocaml-programming.de/packages/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	stephane@FreeBSD.org
COMMENT=	OCaml package manager

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	all opt

PLIST_FILES=	bin/ocamlfind etc/findlib.conf

MAN1=	ocamlfind.1
MAN5=	META.5 findlib.conf.5 site-lib.5

# this list comes from the findlib configure script
OCAML_DIRS=	dbm dynlink graphics num num-top str threads unix stdlib bigarray labltk camlp4

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/findlib -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}

.for D in ${OCAML_DIRS}
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/$D -type f -name META | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
.endfor

	${ECHO_CMD} 'lib/ocaml/site-lib/num-top/num_top.cma' >> ${TMPPLIST}
	${ECHO_CMD} 'lib/ocaml/site-lib/num-top/num_top.cmi' >> ${TMPPLIST}
	${ECHO_CMD} 'lib/ocaml/site-lib/num-top/num_top_printers.cmi' >> ${TMPPLIST}
	${ECHO_CMD} 'lib/ocaml/topfind' >> ${TMPPLIST}

	@${FIND} ${PREFIX}/lib/ocaml/site-lib/findlib -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.for D in ${OCAML_DIRS}
	${ECHO_CMD} "@dirrm lib/ocaml/site-lib/$D" >> ${TMPPLIST}
.endfor

	${ECHO_CMD} '@dirrm lib/ocaml/site-lib' >> ${TMPPLIST}

.include <bsd.port.mk>
