# New ports collection makefile for:	cppcheck
# Date created:		March 3, 2009
# Whom:	      		Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cppcheck
PORTVERSION=	1.47
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Static analysis of C/C++ code

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre

USE_GMAKE=	yes
USE_BZIP2=	yes
LDFLAGS+=	${PTHREAD_LIBS} -L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/cppcheck

ALL_TARGET=	cppcheck

.if !defined(NO_INSTALL_MANPAGES)
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

MANCOMPRESSED=	no
MAN1=		cppcheck.1
ALL_TARGET+=	man

post-install:
	@${INSTALL_MAN} ${WRKSRC}/cppcheck.1 ${PREFIX}/man/man1
.endif

post-patch:
	@${REINPLACE_CMD} -e '/CXXFLAGS=/d ; /CXX=/d' \
		${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cppcheck ${PREFIX}/bin

regression-test: build
	@(cd ${BUILD_WRKSRC}; \
		${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} test)

.include <bsd.port.mk>
