# New ports collection makefile for:	sunterlib
# Date created:				14 July 2004
# Whom:					bkhl@elektrubadur.se
#
# $FreeBSD$
#

PORTNAME=	sunterlib
PORTVERSION=	0.7
CATEGORIES=	devel scheme
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Contributed libraries for Scheme 48 and scsh

RUN_DEPENDS=	${LOCALBASE}/lib/scsh/scsh-install-pkg:${PORTSDIR}/devel/scsh-install-lib

NO_BUILD=	yes

do-install:
	(cd ${WRKSRC}; ${LOCALBASE}/lib/scsh/scsh-install-pkg --prefix=${PREFIX}/lib/scsh)

.include <bsd.port.mk>
