# Created by: Alexander Churanov <churanov.port.maintainer@gmail.com>
# $FreeBSD$

PORTNAME=	boost-libs
COMMENT=	Free portable C++ libraries (without Boost.Python)

BUILD_DEPENDS+=	bjam:${PORTSDIR}/devel/boost-jam

OPTIONS_DEFINE=	VERSBOSE_BUILD DEBUG ICU OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	ICU
VERBOSE_BUILD_DESC=	Show compiler messages
ICU_DESC=		Boost.Regex with ICU unicode support

.include "${.CURDIR}/../boost-all/common.mk"

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../boost-all/compiled.mk"

BJAM_ARGS+=	--without-python

.if ${PORT_OPTIONS:MICU}
LIB_DEPENDS+=	icuuc:${PORTSDIR}/devel/icu
BJAM_ARGS+=	-sICU_PATH=${LOCALBASE}
.else
USE_ICONV=	yes
BJAM_ARGS+=	-sICONV_PATH=${LOCALBASE}
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64: invokes i386 assembler
.endif

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${BJAM} ${BJAM_ARGS} stage
	@cd ${WRKSRC}/stage/lib && \
		( for l in lib*.so.*; do ${LN} -sf $${l} $${l%.*}; done )

do-install:
	@cd ${WRKSRC} && \
		${SETENT} ${MAKE_ENV} ${BJAM} ${BJAM_ARGS} install
# For some reasons BJAM forget about the links
	@cd ${WRKSRC}/stage/ && ${FIND} lib -type l | ${PAX} -rw -p p ${PREFIX}

# display pkg-message
post-install:
	@${TOUCH} ${PKGMESSAGE}

	@${CAT} ${PKG_MESSAGE_FILE_THREADS} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}

	@${REINPLACE_CMD} \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g" \
		-e "s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g" \
		-e "s|%%PYTHON_LIBDIR%%|${PYTHON_LIBDIR}|g" \
		-e "s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|g" ${PKGMESSAGE}

	@if [ -s ${PKGMESSAGE} ]; then \
	${CAT} ${PKGMESSAGE}; \
	fi

.include <bsd.port.post.mk>
