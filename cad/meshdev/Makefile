# New ports collection Makefile for:    meshdev
# Date created:                         6 February 2012
# Whom:                                 gahr
#
# $FreeBSD$
#

PORTNAME=	meshdev
PORTVERSION=	0.5
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_LOCAL}/gahr/ \
		http://people.freebsd.org/~gahr/distfiles/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A mesh comparison software

BUILD_WRKSRC=	${WRKSRC}/build
INSTALL_WRKSRC=	${WRKSRC}/bin

MAKEFILE=	Makefile.release.gcc

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
