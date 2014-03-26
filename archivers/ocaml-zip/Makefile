# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	zip
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://caml.inria.fr/distrib/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	caml${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml library to manipulate ZIP/GZIP/JAR archives

USE_OCAML=	yes
USE_OCAML_LDCONFIG=yes
USE_OCAML_WASH=	yes

ALL_TARGET=	all allopt
INSTALL_TARGET=	install installopt
PATTERN=	([[:space:]]*)cp([[:space:]]+.*)

post-extract:
# PREFIX, CFLAGS and permissions safeness
	@${REINPLACE_CMD} -E \
		-e "s,${PATTERN},\1\$${BSD_INSTALL_DATA}\2," \
		-e "s,(-ccopt[[:space:]])-g,\1\"${CFLAGS}\"," \
		-e "s,^(INSTALLDIR=).*,\1${STAGEDIR}${OCAMLFIND_DESTDIR}/zip," \
		-e "/ldconf/d" ${WRKSRC}/Makefile

post-install:
	${INSTALL_DATA} ${FILESDIR}/META ${STAGEDIR}${OCAMLFIND_DESTDIR}/${PORTNAME}
	@${FIND} ${STAGEDIR}${OCAMLFIND_DESTDIR}/${PORTNAME} -type f | \
		${SED} "s,^${STAGEDIR}${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${OCAML_SITELIBDIR}/${PORTNAME}" >> ${TMPPLIST}

.include <bsd.port.mk>
