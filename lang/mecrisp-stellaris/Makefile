PORTNAME=	mecrisp-stellaris
PORTVERSION=	2.6.3
CATEGORIES=	lang
MASTER_SITES=	SF/mecrisp

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Native code Forth system for ARM
WWW=		https://mecrisp.sourceforge.net

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

.if defined(QEMU_EMULATING)
IGNORE_aarch64=	fails to build with qemu-user-static: \
		qemu-aarch64-static cannot execute armv7 binaries
.endif
ONLY_FOR_ARCHS=		aarch64 armv6 armv7
ONLY_FOR_ARCHS_REASON=	written in ARM assembly

BUILD_DEPENDS=	arm-none-eabi-binutils>2.25:devel/binutils@arm_none_eabi

# stripping eats our hand-crafted ELF binaries, so don't do that
# the binaries are free of symbols or stuff like that anyway
STRIP=

PKGMESSAGE=	pkg-message-${ARCH}

BINSUFFIX_armv6=	-armv6
BINSUFFIX=		${BINSUFFIX_${ARCH}}

# Can't use the release script as it tries to build a bunch of stuff
# that won't build correctly.  This does the relevant parts manually.
do-build:
	cd ${WRKSRC}/mecrisp-stellaris-source/freebsd-ra && ${SH} -v assemble
	${CP} ${WRKSRC}/mecrisp-stellaris-source/freebsd-ra/mecrisp-stellaris-freebsd${BINSUFFIX} \
	    ${WRKSRC}/freebsd-ra/mecrisp-stellaris-freebsd
	cd ${WRKSRC}/freebsd-ra && ${SH} -v buildcore-freebsd

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/KNOWN-ISSUES ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/common && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd-ra/mecrisp-stellaris-freebsd-with-disassembler-and-math \
	    ${STAGEDIR}${PREFIX}/bin/mecrisp-stellaris

.include <bsd.port.mk>
