# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	libtar
PORTVERSION=	1.2.11
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.feep.net/pub/software/libtar/

MAINTAINER=	manuelj.munoz@gmail.com
COMMENT=	library for manipulating POSIX and GNU tar files

BROKEN=		unfetchable
USES=		cpe gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPE_VENDOR=	feep

CPPFLAGS+=	-fPIC

post-install:
	${INSTALL_LIB} ${WRKSRC}/lib/libtar.so.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libtar.so.0 ${STAGEDIR}${PREFIX}/lib/libtar.so

.include <bsd.port.mk>
