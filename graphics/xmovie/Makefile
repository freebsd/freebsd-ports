# New ports collection makefile for:	xmovie
# Date created:		20 December 1998
# Whom:			MIHIRA Sanpei Yoshiro <sanpei@sanpei.org>
#
# $FreeBSD$
#

PORTNAME=	xmovie
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	imura
# Distfile has no version info. The original site is below.
# MASTER_SITES=	http://heroine.linuxbox.com/
DISTNAME=	${PORTNAME}-i586-${PORTVERSION}

MAINTAINER=	sanpei@FreeBSD.org

RUN_DEPENDS=	${LINUX_BASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base \
		${LINUX_BASE}/usr/lib/libjpeg.so.62.0.0:${PORTSDIR}/graphics/linux-jpeg \
		${LINUX_BASE}/usr/lib/libpng.so.2.1.0.3:${PORTSDIR}/graphics/linux-png

ONLY_FOR_ARCHS=	i386
DOC_DIR=	${PREFIX}/share/doc/xmovie
LINUX_BASE=	/compat/linux
NO_BUILD=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/xmovie-i586

# Linux binary should not be stripped by INSTALL_PROGRAM as it uses
# /usr/bin/strip which then brands the binary as a FreeBSD ELF one.
STRIP=

do-patch:
	@${DO_NADA}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xmovie ${PREFIX}/bin
	@brandelf -t Linux ${PREFIX}/bin/xmovie
	@${INSTALL_PROGRAM} ${WRKSRC}/mpeg2toc ${PREFIX}/bin
	@brandelf -t Linux ${PREFIX}/bin/mpeg2toc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOC_DIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOC_DIR}/README
	@${INSTALL_DATA} ${WRKSRC}/docs/index.html ${DOC_DIR}/index.html
.endif
.include <bsd.port.mk>
