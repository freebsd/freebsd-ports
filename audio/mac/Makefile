# New ports collection makefile for:   mac
# Date created:        8 Aug 2004
# Whom:                dieringe
#
# $FreeBSD$
#

PORTNAME=	mac
PORTVERSION=	3.99.4
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.altlinux.ru/pub/distributions/ALTLinux/Sisyphus/SRPMS.classic/
DISTFILES=	mac-3.99.u4-alt2.src.rpm

MAINTAINER=	dieringe@zedat.fu-berlin.de
COMMENT=	Monkey's Audio lossless audio (de)compressor

EXTRACT_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm

EXTRACT_CMD=	rpm2cpio
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	| ${CPIO} -id --quiet && ${TAR} -xyf mac-3.99-u4-linux.tar.bz2

USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ARGS+=	--enable-backward

WRKSRC=		${WRKDIR}/mac-3.99-u4

INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not compile on 4.x due to missing multibyte string functions in libc
.endif

.include <bsd.port.post.mk>
