PORTNAME=	boost-headers
PORTREVISION?=	0

COMMENT=	Free portable C++ libraries (without Boost.Python)
WWW=		https://www.boost.org/

LICENSE=	BSL
LICENSE_FILE=	${WRKSRC}/LICENSE_1_0.txt

BUILD_DEPENDS+=	bjam:devel/boost-jam

.include "${.CURDIR}/../boost-all/common.mk"

.include "${.CURDIR}/../boost-all/compiled.mk"

MAKE_ARGS+=	--with-headers
ALL_TARGET=	stage

.include <bsd.port.pre.mk>

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		${MAKE_ARGS:NDESTDIR=*:S,^--prefix=,&${STAGEDIR},} ${INSTALL_TARGET}
	@${FIND} ${STAGEDIR}${PREFIX}/lib/cmake -type f -exec \
		${REINPLACE_CMD} -i '' -e 's,${STAGEDIR},,' {} +
# For some reasons BJAM forget about the links
	@cd ${WRKSRC}/stage/ && ${FIND} lib -type l | ${PAX} -rw -p p ${STAGEDIR}${PREFIX}

# display pkg-message
post-install:
	@${TOUCH} ${PKGMESSAGE}

	@${CAT} ${PKG_MESSAGE_FILE_THREADS} >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}

	@${REINPLACE_CMD} \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g" \
		-e "s|%%PYTHON_LIBDIR%%|${PYTHON_LIBDIR}|g" \
		-e "s|%%PYTHON_VERSION%%|${PYTHON_VERSION}|g" ${PKGMESSAGE}

.include <bsd.port.post.mk>
