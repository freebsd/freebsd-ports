PORTNAME=	deliverance
DISTVERSION=	0.0.16
CATEGORIES=	java science
MASTER_SITES=	https://repo1.maven.org/maven2/io/teknek/${PORTNAME}/web/${DISTVERSION}/:web \
		https://repo1.maven.org/maven2/io/teknek/${PORTNAME}/deliverance-antares-cli/${DISTVERSION}/:antares \
		https://repo1.maven.org/maven2/io/teknek/${PORTNAME}/nanocode-deliverance/${DISTVERSION}/:nanocode
DISTFILES=	${WEB_DISTFILE}:web \
		${ANTARES_DISTFILE}:antares \
		${NANOCODE_DISTFILE}:nanocode
EXTRACT_ONLY=	${DISTFILE_source}

USE_GITHUB=	nodefault
GH_ACCOUNT=	edwardcapriolo:source
GH_PROJECT=	deliverance:source
GH_TAGNAME=	v${DISTVERSION}:source

MAINTAINER=	edlinuxguru@gmail.com
COMMENT=	Java AI inference engine
WWW=		https://github.com/edwardcapriolo/deliverance

LICENSE=	APACHE20

TEST_DEPENDS=	curl:ftp/curl

USES=		compiler:c11 java
JAVA_VERSION=	25+
USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	${PORTNAME}-bin \
		${PORTNAME}-antares \
		${PORTNAME}-dead-to-rights \
		${PORTNAME}-nanocode \
		pkg-message
SUB_LIST=	JAVA=${JAVA} \
		WEB_JAR=${JAVAJARDIR}/${PORTNAME}/${WEB_JAR} \
		ANTARES_JAR=${JAVAJARDIR}/${PORTNAME}/${ANTARES_JAR} \
		NANOCODE_JAR=${JAVAJARDIR}/${PORTNAME}/${NANOCODE_JAR} \
		NATIVE_LIB_DIR=${PREFIX}/lib/${PORTNAME} \
		DELIVERANCE_USER=${DELIVERANCE_USER} \
		DELIVERANCE_GROUP=${DELIVERANCE_GROUP} \
		ETCDIR=${ETCDIR}

WEB_DISTFILE=	web-${DISTVERSION}.jar
ANTARES_DISTFILE=	deliverance-antares-cli-${DISTVERSION}-all.jar
NANOCODE_DISTFILE=	nanocode-deliverance-${DISTVERSION}-all.jar
WEB_JAR=	${PORTNAME}.jar
ANTARES_JAR=	${PORTNAME}-antares-cli.jar
NANOCODE_JAR=	nanocode-${PORTNAME}.jar
NATIVE_SRC=	${WRKSRC_source}/native/src/main/c
NATIVE_LIB_DIR=	${WRKDIR}/native-lib
NATIVE_CFLAGS_amd64=	-mavx2 -mfma
NATIVE_CFLAGS_aarch64=	-march=armv8.2-a+dotprod -D__ARM_NEON__ -flax-vector-conversions
NATIVE_CFLAGS_arm64=	${NATIVE_CFLAGS_aarch64}
NATIVE_CFLAGS=	${CFLAGS} -fPIC -fno-omit-frame-pointer -Wunused-variable ${NATIVE_CFLAGS_${ARCH}}
DELIVERANCE_USER=	${PORTNAME}
DELIVERANCE_GROUP=	${PORTNAME}
DELIVERANCE_LONGTEST?=	no
# Long test model cache location. Default reuses the invoking user's normal
# Deliverance cache, usually ~/.deliverance. For isolated test downloads use:
# LONG_TEST_HOME_DIR=${WRKDIR}/deliverance-longhome
LONG_TEST_HOME_DIR?=	${HOME}

PLIST_FILES=	bin/${PORTNAME} \
		bin/${PORTNAME}-antares \
		bin/${PORTNAME}-dead-to-rights \
		bin/${PORTNAME}-nanocode \
		${JAVAJARDIR}/${PORTNAME}/${WEB_JAR} \
		${JAVAJARDIR}/${PORTNAME}/${ANTARES_JAR} \
		${JAVAJARDIR}/${PORTNAME}/${NANOCODE_JAR} \
		lib/${PORTNAME}/libdeliverance.so \
		lib/${PORTNAME}/libdeliverance_tensor2.so \
		"@dir ${ETCDIR}" \
		"@sample ${ETCDIR}/deliverance.properties.sample" \
		"@sample ${ETCDIR}/nanocode-antares-1b.json.sample" \
		"@sample ${ETCDIR}/nanocode-qwen3-0.6b-jq4.json.sample" \
		"@dir(${DELIVERANCE_USER},${DELIVERANCE_GROUP},0755) /var/db/${PORTNAME}" \
		"@dir(${DELIVERANCE_USER},${DELIVERANCE_GROUP},0755) /var/db/${PORTNAME}/.deliverance" \
		"@dir(${DELIVERANCE_USER},${DELIVERANCE_GROUP},0755) /var/db/${PORTNAME}/.deliverance/kv-cache" \
		"@dir(${DELIVERANCE_USER},${DELIVERANCE_GROUP},0755) /var/log/${PORTNAME}"

USERS=		${DELIVERANCE_USER}
GROUPS=		${DELIVERANCE_GROUP}

do-build:
	${MKDIR} ${NATIVE_LIB_DIR}
	${CC} ${NATIVE_CFLAGS} -shared ${LDFLAGS} \
		-I${NATIVE_SRC}/simd \
		${NATIVE_SRC}/simd/vector_simd.c \
		${NATIVE_SRC}/simd/vector_runtime.c \
		-lm -o ${NATIVE_LIB_DIR}/libdeliverance.so
	${CC} ${NATIVE_CFLAGS} -shared ${LDFLAGS} \
		-I${NATIVE_SRC}/tensor2 \
		${NATIVE_SRC}/tensor2/tensor2_native.c \
		-o ${NATIVE_LIB_DIR}/libdeliverance_tensor2.so

do-install:
	${MKDIR} ${STAGEDIR}${JAVAJARDIR}/${PORTNAME}
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/db/${PORTNAME}/.deliverance/kv-cache
	${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	${INSTALL_DATA} ${DISTDIR}/${WEB_DISTFILE} \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/${WEB_JAR}
	${INSTALL_DATA} ${DISTDIR}/${ANTARES_DISTFILE} \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/${ANTARES_JAR}
	${INSTALL_DATA} ${DISTDIR}/${NANOCODE_DISTFILE} \
		${STAGEDIR}${JAVAJARDIR}/${PORTNAME}/${NANOCODE_JAR}
	${INSTALL_LIB} ${NATIVE_LIB_DIR}/libdeliverance.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/libdeliverance.so
	${INSTALL_LIB} ${NATIVE_LIB_DIR}/libdeliverance_tensor2.so \
		${STAGEDIR}${PREFIX}/lib/${PORTNAME}/libdeliverance_tensor2.so
	${INSTALL_DATA} ${FILESDIR}/deliverance.properties.sample \
		${STAGEDIR}${ETCDIR}/deliverance.properties.sample
	${INSTALL_DATA} ${FILESDIR}/nanocode-antares-1b.json.sample \
		${STAGEDIR}${ETCDIR}/nanocode-antares-1b.json.sample
	${INSTALL_DATA} ${FILESDIR}/nanocode-qwen3-0.6b-jq4.json.sample \
		${STAGEDIR}${ETCDIR}/nanocode-qwen3-0.6b-jq4.json.sample
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-bin \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-antares \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-antares
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-dead-to-rights \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-dead-to-rights
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}-nanocode \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}-nanocode

do-test:
	@PORT=18080; \
	CONFIG=${WRKDIR}/deliverance-test.properties; \
	HOME_DIR=$$(mktemp -d ${WRKDIR}/deliverance-home.XXXXXX); \
	LOG=${WRKDIR}/deliverance-test.log; \
	RESPONSE=${WRKDIR}/deliverance-longtest-stream.txt; \
	${RM} -f $${CONFIG}; \
	printf '%s\n' "server.port=$${PORT}" \
		"deliverance.tensor.operations.type=simd" > $${CONFIG}; \
	${JAVA} --enable-native-access=ALL-UNNAMED \
		--add-modules jdk.incubator.vector \
		--add-opens java.base/java.nio=ALL-UNNAMED \
		-XX:-UseCompactObjectHeaders \
		-Djava.library.path=${NATIVE_LIB_DIR} \
		-Duser.home=$${HOME_DIR} \
		-Dspring.config.location=file:$${CONFIG} \
		-jar ${DISTDIR}/${WEB_DISTFILE} > $${LOG} 2>&1 & \
	PID=$$!; \
	trap 'kill $${PID} >/dev/null 2>&1 || true; wait $${PID} >/dev/null 2>&1 || true' EXIT INT TERM; \
	COUNT=0; \
	READY=0; \
	while [ $${COUNT} -lt 60 ]; do \
		if ${LOCALBASE}/bin/curl -fsS -H 'Content-Type: application/json' http://127.0.0.1:$${PORT}/models 2>/dev/null | ${GREP} -q '"object"[[:space:]]*:[[:space:]]*"list"'; then \
			READY=1; \
			break; \
		fi; \
		COUNT=$$((COUNT + 1)); \
		sleep 1; \
	done; \
	if [ $${READY} -ne 1 ]; then \
		${CAT} $${LOG}; \
		exit 1; \
	fi; \
	if [ "${DELIVERANCE_LONGTEST}" != "yes" ]; then \
		exit 0; \
	fi; \
	printf '%s\n' 'Long inference test enabled.'; \
	printf '%s\n' 'The streaming response is printed exactly as the server sends it.'; \
	kill $${PID} >/dev/null 2>&1 || true; \
	wait $${PID} >/dev/null 2>&1 || true; \
	PORT=18081; \
	CONFIG=${WRKDIR}/deliverance-longtest.properties; \
	HOME_DIR=${LONG_TEST_HOME_DIR}; \
	${MKDIR} $${HOME_DIR}; \
	LOG=${WRKDIR}/deliverance-longtest.log; \
	printf '%s\n' "First run will fetch the Qwen3-0.6B-JQ4 model under: $${HOME_DIR}/.deliverance"; \
	${RM} -f $${CONFIG}; \
	printf '%s\n' "server.port=$${PORT}" \
		"deliverance.tensor.operations.type=simd" \
		"deliverance-model.configs[0].model-owner=edwardcapriolo" \
		"deliverance-model.configs[0].model-name=Qwen3-0.6B-JQ4" \
		"deliverance-model.configs[0].inference-type=GENERATION" \
		"deliverance-model.configs[0].output-head-quantization=Q4" > $${CONFIG}; \
	${JAVA} --enable-native-access=ALL-UNNAMED \
		--add-modules jdk.incubator.vector \
		--add-opens java.base/java.nio=ALL-UNNAMED \
		-XX:-UseCompactObjectHeaders \
		-Xmx6G \
		-Djava.library.path=${NATIVE_LIB_DIR} \
		-Duser.home=$${HOME_DIR} \
		-Dspring.config.location=file:$${CONFIG} \
		-jar ${DISTDIR}/${WEB_DISTFILE} > $${LOG} 2>&1 & \
	PID=$$!; \
	COUNT=0; \
	READY=0; \
	while [ $${COUNT} -lt 600 ]; do \
		if ${LOCALBASE}/bin/curl -fsS -H 'Content-Type: application/json' http://127.0.0.1:$${PORT}/models 2>/dev/null | ${GREP} -q 'Qwen3-0.6B-JQ4'; then \
			READY=1; \
			break; \
		fi; \
		COUNT=$$((COUNT + 1)); \
		sleep 1; \
	done; \
	if [ $${READY} -ne 1 ]; then \
		${CAT} $${LOG}; \
		exit 1; \
	fi; \
	printf '%s\n' 'Streaming Qwen3-0.6B-JQ4 response:'; \
	${LOCALBASE}/bin/curl -fsS --no-buffer -H 'Content-Type: application/json' \
		-d '{"model":"Qwen3-0.6B-JQ4","stream":true,"max_tokens":384,"chat_template_kwargs":{"enable_thinking":false},"messages":[{"role":"user","content":"Deliverance is an AI Inference engine that runs on Java and can leverage native code for optimizations. Tell me why FreeBSD is a great operating system to run Deliverance."}]}' \
		http://127.0.0.1:$${PORT}/chat/completions | /usr/bin/tee $${RESPONSE} | /usr/bin/awk 'match($$0, /"content":"[^"]*"/) { s=substr($$0, RSTART+11, RLENGTH-12); printf "%s", s; fflush() }'; \
	printf '\n'; \
	if ${GREP} -q '\[DONE\]' $${RESPONSE}; then \
		exit 0; \
	fi; \
	${CAT} $${LOG}; \
	exit 1

.include <bsd.port.mk>
