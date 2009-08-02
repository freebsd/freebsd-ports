# New ports collection makefile for:    sablevm
# Date created:         		9 July 2002
# Whom:                 		Archie Cobbs <archie@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	sablevm
PORTVERSION=	1.13
PORTREVISION=	5
CATEGORIES=	java devel
MASTER_SITES=	SF

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Java VM created by McGill University's Sable Research Group

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt \
		ffi:${PORTSDIR}/devel/libffi

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libltdl
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes

USE_GNOME=	pkgconfig
PKG_CONFIG?=	${LOCALBASE}/bin/pkg-config
CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include `${PKG_CONFIG} libffi --cflags`" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME}

OPTIONS=	SVMCP "Install SableVM classpath" ON \
		MAN "Build and install man pages" ON

CONFLICTS=	classpath-*

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SVMCP)
RUN_DEPENDS+=	${LOCALBASE}/lib/sablevm-classpath/libjavalang.so:${PORTSDIR}/java/sablevm-classpath
.endif

.if !defined(WITHOUT_MAN)
MAN1=		java-sablevm.1 sablevm.1
.endif

post-extract:
	@${REINPLACE_CMD} -e 's,^subdirs=".*,,' ${WRKSRC}/configure
.if defined(WITHOUT_MAN)
	@${REINPLACE_CMD} -e 's,^\(man_MANS = \).*,\1,' ${WRKSRC}/doc/Makefile.in
.endif

.include <bsd.port.post.mk>
