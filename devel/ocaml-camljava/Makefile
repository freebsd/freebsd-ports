# New ports collection makefile for:	camljava
# Date created:		2006-07-31
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	camljava
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	devel java
MASTER_SITES=	http://caml.inria.fr/distrib/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OCaml-Java library interface

USE_OCAML=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.5+

.include <bsd.port.pre.mk>

post-extract:
	@${REINPLACE_CMD} -e "s,^\(JAVAC=\).*,\1${JAVAC},g" \
		-e "s,^\(JDKHOME=\).*,\1${JAVA_HOME},g" \
		-e "s,include/linux,include/freebsd,g" \
		-e "s,^CFLAGS=.*,#\&,g" \
		-e "s,^\(CC=\).*,#\&,g" \
		-e "s,i386,${ARCH},g" \
		${WRKSRC}/Makefile.config

	${REINPLACE_CMD} \
		-e "s,^\(OCAMLLIB=\).*,\1${PREFIX}/lib/ocaml,g" \
		-e "/^install/,/^$$/s,\([ \t]*\)cp,\1${INSTALL_DATA},g" \
		${WRKSRC}/lib/Makefile

pre-install:
.if !exists(${PREFIX}/lib/ocaml)
	${MKDIR} ${PREFIX}/lib/ocaml
	@${ECHO_CMD} "@dirrm lib/ocaml" >> ${TMPPLIST}
.endif

test:
	@${ECHO_CMD} "Testing IDL library"
	cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${MAKE} all

.include <bsd.port.post.mk>
