# Created by: Andreev Maxim <andreevmaxim@gmail.com>
# $FreeBSD$

PORTNAME=	qconf
PORTVERSION=	2.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to create configure script for qmake-based project

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2
USE_QT4=	corelib xml moc_build qmake_build rcc_build
HAS_CONFIGURE=	yes
QT_NONSTANDARD=	yes
MAKE_ARGS=	INSTALL_ROOT="${STAGEDIR}"

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--datadir=${DATADIR:S,/qconf,,} \
		--qtdir=${PREFIX} \
		--verbose

USE_GITHUB=	yes
GH_ACCOUNT=	psi-plus

.include <bsd.port.mk>
