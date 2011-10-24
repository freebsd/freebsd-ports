# New ports collection makefile for:	ocaml-zip
# Date created:				2006-08-01
# Whom:					Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	zip
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	http://caml.inria.fr/distrib/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	caml${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml library to manipulate ZIP/GZIP/JAR archives

#USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_LDCONFIG=yes
USE_OCAML_WASH=	yes

ALL_TARGET=	all allopt
INSTALL_TARGET=	install installopt
MASTERPORT=	${PORTSDIR}/devel/ocaml-camlidl
PATTERN=	([[:space:]]*)cp([[:space:]]+.*)

.include <bsd.port.pre.mk>

post-extract:
# PREFIX, CFLAGS and permissions safeness
	@${REINPLACE_CMD} -E \
		-e "s,${PATTERN},\1\$${BSD_INSTALL_DATA}\2," \
		-e "s,(-ccopt[[:space:]])-g,\1\"${CFLAGS}\"," \
		-e "s,^(INSTALLDIR=).*,\1${OCAMLFIND_DESTDIR}/zip," \
		-e "/ldconf/d" ${WRKSRC}/Makefile

pre-install:
# For nonstandard prefixes
.if !exists(${OCAMLFIND_DESTDIR})
	${MKDIR} ${OCAMLFIND_DESTDIR}
.endif
.if !exists(${OCAMLFIND_LDCONF})
	${TOUCH} ${OCAMLFIND_LDCONF}
.endif

post-install:
	@${INSTALL_DATA} ${FILESDIR}/META ${OCAMLFIND_DESTDIR}/${PORTNAME}
	@${FIND} ${OCAMLFIND_DESTDIR}/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${OCAML_SITELIBDIR}/${PORTNAME}" >> ${TMPPLIST}

.include <bsd.port.post.mk>
