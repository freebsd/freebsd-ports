# Created by: Andreev Maxim <andreevmaxim@gmail.com>
# $FreeBSD$

PORTNAME=	qconf
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to create configure script for qmake-based project

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake:no_env qt:4 tar:bzip2
USE_QT=		corelib xml moc_build qmake_build rcc_build
HAS_CONFIGURE=	yes
MAKE_ARGS=	INSTALL_ROOT="${STAGEDIR}"

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir=${DATADIR:S,/qconf,,} \
		--qtdir=${PREFIX} \
		--verbose

USE_GITHUB=	yes
GH_ACCOUNT=	psi-plus

.include <bsd.port.mk>
