# $FreeBSD$

# The version should match the one imported into base in later releases,
# so ports can expect the same features across all branches.

PORTNAME=	xz
PORTVERSION=	5.0.4
CATEGORIES=	archivers
#MASTER_SITES=	http://tukaani.org/xz/
# tukaani.org still doesn't interop with fetch(1) as of 2013-01-06
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	naddy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LZMA compression and decompression tools

CONFLICTS=	lzma-[0-9]* lzmautils-[0-9]* lzmalib-[0-9]*

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USES=	pathfix
GNU_CONFIGURE=	yes

DEPRECATED=	Available in base distribution for all supported releases

# As we want to use xz for extraction of port distfiles,
# it cannot depend on gettext.
CONFIGURE_ARGS=	--disable-nls

# pick up assembly language optimizations
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-freebsd${OSREL}

INSTALL_TARGET=	install install-dist_docDATA install-dist_examplesDATA \
		install-dist_examplesoldDATA

PORTDOCS=	AUTHORS COPYING COPYING.GPLv2 NEWS README THANKS TODO \
		faq.txt history.txt lzma-file-format.txt xz-file-format.txt \
		examples examples_old

regression-test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
