# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	libtar
PORTVERSION=	1.2.11
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/libtar/libtar-1.2.11.tar.gz/604238e8734ce6e25347a58c4f1a1d7e/

MAINTAINER=	manuelj.munoz@gmail.com
COMMENT=	Library for manipulating POSIX and GNU tar files

USES=		cpe gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPE_VENDOR=	feep

CPPFLAGS+=	-fPIC

post-install:
	${INSTALL_LIB} ${WRKSRC}/lib/libtar.so.0 ${STAGEDIR}${PREFIX}/lib
	${LN} -sf libtar.so.0 ${STAGEDIR}${PREFIX}/lib/libtar.so

.include <bsd.port.mk>
