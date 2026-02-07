PORTNAME=	libsdb
PORTVERSION=	0.10.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://siag.nu/pub/libsdb/
DISTNAME=	sdb-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple database library
WWW=		https://siag.nu/libsdb/

MAKE_JOBS_UNSAFE=	yes

HAS_CONFIGURE=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" CC="${CC}" CFLAGS="${CFLAGS}" MANDIR="${PREFIX}/share/man"
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.mk>
