# New ports collection makefile for:	linux-allegro
# Date created:				18 Nov 2003
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	allegro
PORTVERSION=	4.0.3
PORTREVISION=	4
CATEGORIES=	devel linux
MASTER_SITES=	http://membres.lycos.fr/ebotcazou/allegro/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Cross-platform game programming library (linux version)

CONFLICTS=	linux-f8-allegro-[0-9]* linux-f10-allegro-[0-9]*

USE_LINUX_RPM=		yes
USE_LINUX_APPS=		xorglibs
ONLY_FOR_ARCHS=		i386 amd64
DIST_SUBDIR=		rpm
USE_LDCONFIG=		yes
SRC_DISTFILES=

MD5_FILE=	${MASTERDIR}/distinfo

post-extract:
	@cd ${WRKSRC}/usr/lib; \
	${LN} -s liballeg-4.0.3.so liballeg.so.4.0

.include <bsd.port.mk>
