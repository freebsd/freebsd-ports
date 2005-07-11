# New ports collection makefile for:	py-sybase
# Date created:				21 November 2002
# Whom:					Gregory Bond <gnb@itga.com.au>
#
# $FreeBSD$

PORTNAME=	sybase
PORTVERSION=	0.37
PORTREVISION=	2
CATEGORIES=	databases python
MASTER_SITES=	http://object-craft.com.au/projects/sybase/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${PORTNAME}-html${EXTRACT_SUFX}

MAINTAINER=	gnb@itga.com.au
COMMENT=	A Python Database API interface to the Sybase RDBMS

LIB_DEPENDS=	tds.4:${PORTSDIR}/databases/freetds

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if defined(TDS_VERSION)
TDS_SUF="=${TDS_VERSION}"
.else
pre-fetch:
	@V=`pkg_info | sed -ne 's/^freetds-0.\(..\).*/\1/p'` ; \
	if [ $$V -le 60 ]; then \
		${ECHO_MSG} "Suggest you update your FreeTDS port to at least version 0.61" ; \
		${ECHO_MSG} "Otherwise, you will need to add TDS_VERSION=$$V to the Make command" ; \
		exit 1 ;\
	fi
.endif	# defined(TDS_VERSION)

MAKE_ENV+=	SYBASE=${LOCALBASE}

.if !defined(WITHOUT_THREADS)
BUILDARGS=	-D WANT_THREADS -U WANT_BULKCOPY -D HAVE_FREETDS${TDS_SUF}
.else
BUILDARGS=	-U WANT_BULKCOPY -D HAVE_FREETDS${TDS_SUF}
.endif

# Need this because -D<> args needed for build_ext but illegal for build
do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} build_ext ${BUILDARGS} )
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYSETUP} build)

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR} ${DOCSDIR}
	@${TAR} -cf - -C ${WRKSRC}/examples . | ${TAR} -xf - -C ${EXAMPLESDIR}
	@${TAR} -cf - -C ${WRKDIR}/${PORTNAME} . | ${TAR} -xf - -C ${DOCSDIR}
.endif

.include <bsd.port.mk>
