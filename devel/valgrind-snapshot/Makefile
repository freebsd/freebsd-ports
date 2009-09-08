# Ports collection makefile for:	valgrind
# Date created:				April 19 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	valgrind
PORTVERSION=	10776
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/
PKGNAMESUFFIX=	-snapshot

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A (memory) debugging and profiling tool

CONFLICTS=	valgrind-[0-9]*
LATEST_LINK=	valgrind-snapshot

ONLY_FOR_ARCHS=	i386 amd64

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700104
IGNORE=	your FreeBSD version is not supported
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64=""
.else
PLIST_SUB+=	AMD64="@comment "
.endif

.include <bsd.port.post.mk>
