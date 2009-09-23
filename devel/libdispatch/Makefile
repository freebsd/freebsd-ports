# New ports collection makefile for:		libdispatch
# Date created:					2009-09-23
# Whom:						stas
#
# $FreeBSD$
#

PORTNAME=	libdispatch
PORTVERSION=	38
CATEGORIES=	devel
MASTER_SITES=	http://www.SpringDaemons.com/stas/
DISTNAME=	${PORTNAME}-r${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Grand Central Dispatch API support library

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes

#
# Get rid of .la and static library files
#
post-configure:
	@${REINPLACE_CMD} -E -e \
	'/Install the pseudo-library/,/staticlibs=/s,^,#,' ${WRKSRC}/libtool

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900002
IGNORE=	is not supported on this OS version
.endif

#
# We want the CPU to be at least i486 on i386 platform, so GCC builting atomics
# will work.
#
.if ${ARCH} == "i386"
CPUTYPE?=	i486
.endif

.include <bsd.port.post.mk>
