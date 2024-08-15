PORTNAME=	camljava
DISTVERSION=	0.4
CATEGORIES=	devel java
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	freebsd@dev.thsi.be
COMMENT=	OCaml-Java library interface
WWW=		https://caml.inria.fr/

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	xavierleroy
GH_PROJECT=	camljava
GH_TAGNAME=	${PORTNAME}${DISTVERSION:S/.//}
USE_JAVA=	yes
USE_OCAML=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,^\(JAVAC=\).*,\1${JAVAC},g" \
		-e "s,^\(JDKHOME=\).*,\1${JAVA_HOME},g" \
		-e "s,include/linux,include/freebsd,g" \
		-e "s,^CFLAGS=.*,#\&,g" \
		-e "s,^\(CC=\).*,#\&,g" \
		-e "s,i386,${ARCH},g" \
		${WRKSRC}/Makefile.config
	@${REINPLACE_CMD} -e 's,(int64,&_t,' ${WRKSRC}/lib/jnistubs.c

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}
	@(cd ${WRKSRC}/lib; ${INSTALL_DATA} \
		jni.cma jni.cmi jni.cmxa jni.a libcamljni.a jni.mli camljava.jar \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME})

test:
	@${ECHO_CMD} "Testing IDL library"
	cd ${WRKSRC}/test && ${SETENV} ${MAKE_ENV} ${MAKE} all

.include <bsd.port.mk>
