# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	dkftpbench
PORTVERSION=	0.45
PORTREVISION=	2
CATEGORIES=	benchmarks ftp
MASTER_SITES=	http://www.kegel.com/dkftpbench/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	FTP benchmark program

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/dkftpbench

post-patch:
	@${REINPLACE_CMD} \
		-e '/^noinst_PROGRAMS =/s/=.*/=/' \
		-e '/^lib_LIBRARIES =/s/=.*/=/' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
