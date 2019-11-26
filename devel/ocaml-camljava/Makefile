# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	camljava
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	devel java
MASTER_SITES=	http://caml.inria.fr/distrib/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml-Java library interface

USE_OCAML=	yes
USE_JAVA=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,^\(JAVAC=\).*,\1${JAVAC},g" \
		-e "s,^\(JDKHOME=\).*,\1${JAVA_HOME},g" \
		-e "s,include/linux,include/freebsd,g" \
		-e "s,^CFLAGS=.*,#\&,g" \
		-e "s,^\(CC=\).*,#\&,g" \
		-e "s,i386,${ARCH},g" \
		${WRKSRC}/Makefile.config
	@${REINPLACE_CMD} -e 's,(int64,&_t,' ${WRKSRC}/lib/jnistubs.c

test:
	@${ECHO_CMD} "Testing IDL library"
	cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${MAKE} all

.include <bsd.port.mk>
