# Ports collection makefile for:	valgrind
# Date created:				April 19 2004
# Whom:					Simon Barner <barner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	valgrind
PORTVERSION=	3.5.0
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	A (memory) debugging and profiling tool

CONFLICTS=	valgrind-snapshot-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700104
IGNORE=	your FreeBSD version is not supported
.endif

.if ${ARCH} == "amd64"
PLIST_SUB+=	AMD64=""
. if !exists(/usr/lib32)
CONFIGURE_ARGS+=	--enable-only64bit
PLIST_SUB+=	X86="@comment "
. else
PLIST_SUB+=	X86=""
. else
. endif
.else
PLIST_SUB+=	X86=""
PLIST_SUB+=	AMD64="@comment "
.endif

.include <bsd.port.post.mk>
