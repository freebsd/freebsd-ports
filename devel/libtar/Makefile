# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	libtar
PORTVERSION=	1.2.11
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.feep.net/pub/software/libtar/

MAINTAINER=	manuelj.munoz@gmail.com
COMMENT=	A library for manipulating POSIX and GNU tar files

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_LDCONFIG=	yes

NO_STAGE=	yes
post-install:
	${INSTALL_DATA} ${WRKSRC}/lib/libtar.so.0 ${PREFIX}/lib
	${LN} -sf libtar.so.0 ${PREFIX}/lib/libtar.so

.include <bsd.port.pre.mk>
.include "files/manpages"

CPPFLAGS+=	-fPIC

.include <bsd.port.post.mk>
