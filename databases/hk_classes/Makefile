# New ports collection makefile for:	hk_classes
# Date created:				25 July 2002
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	hk_classes
PORTVERSION=	0.6.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	hk-classes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"C++ Library for rapid development of database applications"

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		mysqlclient.10:${PORTSDIR}/databases/mysql323-client
BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL} \
		-with-mysql-dir=${LOCALBASE} \
		--with-mysql-incdir=${LOCALBASE}/include/mysql
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${LOCALBASE}/lib/mysql"
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL=	yes

.include <bsd.port.mk>
