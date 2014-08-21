# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	dkftpbench
PORTVERSION=	0.45
PORTREVISION=	2
CATEGORIES=	benchmarks ftp
MASTER_SITES=	http://www.kegel.com/dkftpbench/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	FTP benchmark program

PLIST_FILES=	bin/dkftpbench

GNU_CONFIGURE=	yes

USE_AUTOTOOLS=	automake14 autoconf

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} >= 1000000
BROKEN=		does not build on FreeBSD 10 or better
.endif

.include <bsd.port.post.mk>
