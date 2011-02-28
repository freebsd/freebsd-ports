# New ports collection makefile for:	xz
# Date created:		2009-09-16
# Whom:			naddy
#
# $FreeBSD$
#

PORTNAME=	xz
PORTVERSION=	5.0.1
CATEGORIES=	archivers
#MASTER_SITES=	http://tukaani.org/xz/
# tukaani.org doesn't interop with fetch(1) as of 2011-02-28
MASTER_SITES=	${MASTER_SITE_NETBSD}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	LZMA compression and decompression tools

CONFLICTS=	lzma-[0-9]* lzmautils-[0-9]* lzmalib-[0-9]*

MAKE_JOBS_SAFE=	yes
USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes

# As we want to use xz for extraction of port's distfiles,
# it cannot depend on gettext.
CONFIGURE_ARGS=	--disable-nls

# pick up assembly language optimizations
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-freebsd${OSREL}

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-dist_docDATA install-dist_examplesDATA
.endif

MAN1=	lzmainfo.1 xz.1 xzdec.1 xzdiff.1 xzgrep.1 xzless.1 xzmore.1

MLINKS=	xz.1 lzcat.1		xzdiff.1 lzcmp.1 \
	xzdiff.1 lzdiff.1	xzgrep.1 lzegrep.1 \
	xzgrep.1 lzfgrep.1	xzgrep.1 lzgrep.1 \
	xzless.1 lzless.1	xz.1 lzma.1 \
	xzdec.1 lzmadec.1	xzmore.1 lzmore.1 \
	xz.1 unlzma.1		xz.1 unxz.1 \
	xz.1 xzcat.1		xzdiff.1 xzcmp.1 \
	xzgrep.1 xzegrep.1	xzgrep.1 xzfgrep.1

PORTDOCS=	AUTHORS COPYING COPYING.GPLv2 NEWS README THANKS TODO \
		faq.txt history.txt lzma-file-format.txt xz-file-format.txt \
		examples

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900012 || (${OSVERSION} < 900000 && ${OSVERSION} >= 800505)
IGNORE=	is already in the base system
.endif

.include <bsd.port.post.mk>
