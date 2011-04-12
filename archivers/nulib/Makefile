# New ports collection makefile for:	nulib
# Date created:				Thu May  8 00:14:31 PDT 1997
# Whom:					Steven Wallace <swallace@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nulib
PORTVERSION=	3.25
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jseger
DISTNAME=	nulib325
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NuFX archive utility

WRKSRC=		${WRKDIR}/nulib
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

MAN1=		${PORTNAME}.1
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
