# New ports collection makefile for:	rpm
# Date created:				6 May 2003
# Whom:					Greg Lewis <glewis@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	rpm
PORTVERSION=	4.0.4
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-4.0.x/ \
		ftp://ftp.mirror.ac.uk/sites/ftp.rpm.org/pub/rpm/dist/rpm-4.0.x/

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	The RPM Package Manager

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3 \
		iconv.3:${PORTSDIR}/converters/libiconv \
		popt.0:${PORTSDIR}/devel/popt
BUILD_DEPENDS=	${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_LIBTOOL_VER=14
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_REINPLACE=	yes
LATEST_LINK=	rpm4
CONFLICTS=	beecrypt-* rpm-3.* rpm2cpio-*

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=--with-python=auto
USE_PYTHON=	yes
PLIST_SUB+=	PYTHON=""
CPPFLAGS+=	-I${PYTHON_INCLUDEDIR}
LDFLAGS+=	-L${PYTHON_LIBDIR}
.else
CONFIGURE_ARGS+=--without-python
PLIST_SUB+=	PYTHON="@comment "
.endif

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--without-db \
		--with-popt-prefix="${LOCALBASE}" \
		--sysconfdir=${PREFIX}/etc \
		--without-javaglue

MAN1=	gendiff.1
MAN8=	rpm.8 rpm2cpio.8 rpmbuild.8

post-patch:
	${REINPLACE_CMD} -e 's:%%LOCALBASE%%:${LOCALBASE}:' \
		${WRKSRC}/configure ${WRKSRC}/beecrypt/configure

post-install:
	${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
