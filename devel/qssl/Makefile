# New ports collection makefile for:	qssl
# Date created:		10 November 2002
# Whom:			dd
#
# $FreeBSD$
#

PORTNAME=	qssl
PORTVERSION=	2.0
CATEGORIES=	devel security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	psi

MAINTAINER=	dd@FreeBSD.org
COMMENT=	QSSL is a Qt plugin that helps applications use OpenSSL

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

SHLIB_MAJOR=	1

USE_OPENSSL=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
MAKE_ARGS=	QTDIR=${X11BASE}
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"
USE_QT_VER=	3

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ARGS} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ qssl.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/libqssl.so \
		${PREFIX}/lib/libqssl.so.${SHLIB_MAJOR}
	${LN} -s libqssl.so.${SHLIB_MAJOR} ${PREFIX}/lib/libqssl.so

.include <bsd.port.mk>
