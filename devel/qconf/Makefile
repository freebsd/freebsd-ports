PORTNAME=	qconf
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to create configure script for qmake-based project
WWW=		https://github.com/psi-im/qconf

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Not ported to Qt6, has no consumers
EXPIRATION_DATE=	2026-10-31

USES=		qmake:no_env qt:5 tar:bzip2
USE_QT=		core gui xml \
		buildtools:build qmake:build
HAS_CONFIGURE=	yes
MAKE_ARGS=	INSTALL_ROOT="${STAGEDIR}"

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir=${DATADIR:S,/qconf,,} \
		--qtdir=${PREFIX} \
		--verbose

USE_GITHUB=	yes
GH_ACCOUNT=	psi-plus

.include <bsd.port.mk>
