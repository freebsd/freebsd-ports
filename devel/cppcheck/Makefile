# New ports collection makefile for:	cppcheck
# Date created:		March 3, 2009
# Whom:	      		Gabor Pali <pgj@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cppcheck
PORTVERSION=	1.35
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	pgj@FreeBSD.org
COMMENT=	Static analysis of C/C++ code

USE_GMAKE=	yes
USE_BZIP2=	yes
LDFLAGS+=	${PTHREAD_LIBS}
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/cppcheck

ALL_TARGET=	cppcheck

.if !defined(NO_INSTALL_MANPAGES)
BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

MANCOMPRESSED=	no
MAN1=		cppcheck.1
ALL_TARGET+=	cppcheck.1

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
