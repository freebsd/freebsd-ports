# New ports collection makefile for:	scsh-install-lib
# Date created:				14 July 2004
# Whom:					bkhl@elektrubadur.se
#
# $FreeBSD$
#

PORTNAME=	scsh-install-lib
PORTVERSION=	1.1.2
CATEGORIES=	devel scheme
MASTER_SITES=	http://lamp.epfl.ch/~schinz/scsh_packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An scsh library for installing other scsh packages

RUN_DEPENDS=	scsh:${PORTSDIR}/lang/scsh

NO_BUILD=	yes

do-install:
	(cd ${WRKSRC}; ./install.scm --bindir ${PREFIX}/lib/scsh --prefix ${PREFIX}/lib/scsh)

.include <bsd.port.mk>
