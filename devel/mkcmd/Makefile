# New ports collection makefile for: mkcmd
# Date created:        17 November 1999
# Whom:                ajk@waterspout.com
#
# $FreeBSD$
#

PORTNAME=	mkcmd
PORTVERSION=	8.13d
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.physics.purdue.edu/pub/pundits/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ajk@waterspout.com

BUILD_DEPENDS=	makeme:${PORTSDIR}/devel/msrc0

MAKE_FLAGS=
MAKEFILE=
MAN1=		mkcmd.1
MAN5=		mkcmd.5

do-build:
	@(cd ${WRKSRC}/bin/mkcmd && ${SETENV} ${MAKE_ENV} makeme \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

do-install:
.for d in bin/mkcmd lib/mkcmd
	@(cd ${WRKSRC}/$d && ${SETENV} ${MAKE_ENV} makeme \
	    ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor
	${INSTALL_MAN} ${WRKSRC}/bin/mkcmd/mkcmd.man \
	    ${PREFIX}/man/man1/mkcmd.1
	${INSTALL_MAN} ${WRKSRC}/lib/mkcmd/mkcmd.man \
	    ${PREFIX}/man/man5/mkcmd.5

.include <bsd.port.mk>
