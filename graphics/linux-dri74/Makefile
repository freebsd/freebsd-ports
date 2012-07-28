# New ports collection makefile for:	graphics/linux-dri74
# Date created:				2009-05-06
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	dri
PORTVERSION=	7.4
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	ftp://ftp.ipt.ru/pub/download/ \
		http://people.freebsd.org/~bsam/download/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Mesa-based DRI libraries, drivers, and binaries (Linux Ubuntu 9.0.4)

CONFLICTS=	linux_dri-6.5.2006* linux-libGLU-[0-9]* linux_dri-[0-9]* linux-f8-dri-[0-9]* linux-f10-dri-[0-9]* \
		linux-f10-libGLU-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
USE_BZIP2=	yes
USE_LINUX_PREFIX=yes
USE_LDCONFIG=	yes

do-install:
	@cd ${WRKSRC} && ${SH} -c '(${FIND} -d . | ${CPIO} -dumpl ${PREFIX}) > /dev/null 2>&1'

.include <bsd.port.pre.mk>

pre-fetch:
.if ${OSVERSION} < 702000
IGNORE=		you need FreeBSD>=7.2 RELEASE with Linux emulation 2.6.x
.endif

.include <bsd.port.post.mk>
