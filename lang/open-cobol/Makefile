# ex:ts=8
# Ports collection makefile for:	open-cobol
# Date created:			Aug 6, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	open-cobol
PORTVERSION=	0.23
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open-source COBOL compiler

LIB_DEPENDS=	ltdl.4:${PORTSDIR}/devel/libltdl \
		gmp.6:${PORTSDIR}/math/libgmp4

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-readline
INSTALLS_SHLIB=	yes

INFO=		open-cobol

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
LDFLAGS+=	-lintl
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
