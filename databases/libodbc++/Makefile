# New ports collection makefile for:	libodbc++
# Date created:		26 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libodbc++
PORTVERSION=	0.2.3
PORTREVISION=	2
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	libodbcxx

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	A C++ class library and toolset for ODBC access to data sources

USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
USE_GNOME=	pkgconfig
INSTALLS_SHLIB=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-isqlxx

# libodbc++ needs an ODBC driver manager to be installed, and it supports
# both iODBC and unixODBC.  The following variable may be set at build-time
# to either "iodbc" or "unixodbc", with the latter being the default:
DRIVER_MANAGER?=	unixodbc

.if ${DRIVER_MANAGER} == "iodbc"
LIB_DEPENDS=	iodbc.3:${PORTSDIR}/databases/libiodbc
CONFIGURE_ARGS+=	--with-iodbc=${LOCALBASE}
.else	# assume we're using unixODBC
LIB_DEPENDS=	odbc.1:${PORTSDIR}/databases/unixODBC
CONFIGURE_ARGS+=	--with-odbc=${LOCALBASE}
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS}"
CXXFLAGS+=	${PTHREAD_CFLAGS}
.endif

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	INSTALL progref

.include <bsd.port.mk>
