# New ports collection makefile for:	audio/linux-f8-mikmod
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	mikmod
PORTVERSION=	3.2.2
PORTREVISION=	1
CATEGORIES=	audio linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	MikMod Sound Library (Linux Fedora 8)

CONFLICTS=	linux-mikmod-[0-9]* linux-f10-mikmod-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	8
RPMVERSION=	6.fc8
BRANDELF_FILES=	usr/bin/mikmod
USE_LDCONFIG=	yes

PLIST_FILES=	usr/bin/mikmod usr/share/man/man1/mikmod.1.gz \
		usr/lib/libmikmod.so.2 usr/lib/libmikmod.so.2.0.4
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	AUTHORS COPYING NEWS README TODO
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
