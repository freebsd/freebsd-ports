# New ports collection makefile for:	arch
# Date created:		6 February 2002
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arch
PORTVERSION=	1.0.p16
CATEGORIES=	devel
MASTER_SITES=	ftp://regexps.com/pub/src/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pre/}

MAINTAINER=	wjv@FreeBSD.org

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/src/=build
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=	--prefix ${PREFIX}
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}

pre-configure:
	@ ${MKDIR} ${CONFIGURE_WRKSRC}

post-build:
.if defined(WITH_TESTS)
	@ cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} \
	  ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test
.endif

post-install:
.if !defined(NOPORTDOCS)
.for format in html ps texi
	@ ${MKDIR} ${DOCSDIR}/${format}
	@ ${INSTALL_DATA} ${WRKSRC}/docs/${format}/*.${format} \
	  ${DOCSDIR}/${format}
.endfor
	@ ${INSTALL_DATA} ${WRKSRC}/docs/examples/README* ${DOCSDIR}
.endif

.include <bsd.port.mk>
