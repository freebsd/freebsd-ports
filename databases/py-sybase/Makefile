# Created by: Gregory Bond <gnb@itga.com.au>
# $FreeBSD$

PORTNAME=	sybase
PORTVERSION=	0.37
PORTREVISION=	5
CATEGORIES=	databases python
MASTER_SITES=	http://object-craft.com.au/projects/sybase/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-html${EXTRACT_SUFX}

MAINTAINER=	gnb@itga.com.au
COMMENT=	Python Database API interface to the Sybase RDBMS

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libct.so:databases/freetds

USES=		python:2.7
USE_PYTHON=	distutils

OPTIONS_DEFINE=	DOCS THREADS EXAMPLES
OPTIONS_DEFAULT=THREADS

.if defined(TDS_VERSION)
TDS_SUF="=${TDS_VERSION}"
.else

.include <bsd.port.options.mk>

pre-build:
	@V=`${PKG_INFO} | ${SED} -ne 's/^freetds-0.\(..\).*/\1/p'` ; \
	if [ $$V -le 60 ]; then \
		${ECHO_MSG} "Suggest you update your FreeTDS port to at least version 0.61" ; \
		${ECHO_MSG} "Otherwise, you will need to add TDS_VERSION=$$V to the Make command" ; \
		exit 1 ;\
	fi
.endif	# defined(TDS_VERSION)

MAKE_ENV+=	SYBASE=${LOCALBASE}

.if ${PORT_OPTIONS:MTHREADS}
BUILDARGS=	-D WANT_THREADS -U WANT_BULKCOPY -D HAVE_FREETDS${TDS_SUF}
.else
BUILDARGS=	-U WANT_BULKCOPY -D HAVE_FREETDS${TDS_SUF}
.endif

# Need this because -D<> args needed for build_ext but illegal for build
do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} build_ext ${BUILDARGS} )
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} build)

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR} ${STAGEDIR}${DOCSDIR}
	@${TAR} -cf - -C ${WRKSRC}/examples . | ${TAR} -xf - -C ${STAGEDIR}${EXAMPLESDIR}
	@${TAR} -cf - -C ${WRKDIR}/${PORTNAME} . | ${TAR} -xf - -C ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
