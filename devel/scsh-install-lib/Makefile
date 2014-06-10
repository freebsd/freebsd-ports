# Created by: bkhl@elektrubadur.se
# $FreeBSD$

PORTNAME=	scsh-install-lib
PORTVERSION=	1.3.0
CATEGORIES=	devel scheme
MASTER_SITES=	http://lamp.epfl.ch/~schinz/scsh_packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scsh library for installing other scsh packages

RUN_DEPENDS=	scsh:${PORTSDIR}/lang/scsh

PLIST_SUB=	VER=${PORTVERSION}

NO_BUILD=	yes

NO_STAGE=	yes
do-install:
	(cd ${WRKSRC}; ./install.scm --bindir ${PREFIX}/lib/scsh --prefix ${PREFIX}/lib/scsh)

.include <bsd.port.mk>
