PORTNAME=	camljava
DISTVERSION=	0.5
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

MAKE_ARGS=	-e
MAKE_ENV+=	CAMLJAVALIB=${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME} \
		JDKHOME=${JAVA_HOME}

.include <bsd.port.pre.mk>

.if ${JAVA_PORT_VERSION} >= 11
MAKE_ENV+=	JNILIBOPTS="-L${JAVA_HOME}/lib -L${JAVA_HOME}/lib/server -Wl,-rpath=${JAVA_HOME}/lib -Wl,-rpath=${JAVA_HOME}/lib/server"
.else
MAKE_ENV+=	JNILIBOPTS="-L${JAVA_HOME}/jre/lib/${ARCH} -L${JAVA_HOME}/jre/lib/${ARCH}/server -Wl,-rpath=${JAVA_HOME}/jre/lib/${ARCH} -Wl,-rpath=${JAVA_HOME}/jre/lib/${ARCH}/server -Wl,-rpath=${JAVA_HOME}/jre/lib/${ARCH}/native_threads"
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e "s,include/linux,include/${OPSYS:tl}," \
		${WRKSRC}/Makefile.config

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME}
	@(cd ${WRKSRC}/lib; ${INSTALL_DATA} \
		jni.cma jni.cmi jni.cmxa jni.a libcamljni.a jni.mli camljava.jar \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/${PORTNAME})

test:
	@${ECHO_CMD} "Testing camljava library"
	${SETENVI} ${MAKE_ENV} ${MAKE} -C ${WRKSRC} ${MAKE_ARGS} tst

.include <bsd.port.post.mk>
