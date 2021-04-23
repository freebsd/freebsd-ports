PORTNAME=	mecrisp-stellaris
DISTVERSION=	2.5.8
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF/mecrisp

MAINTAINER=	fuz@fuz.su
COMMENT=	Native code Forth system for ARM

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=		EXTRAS
OPTIONS_DEFAULT=	EXTRAS
EXTRAS_DESC=		Add disassembler and math library to Forth core
EXTRAS_VARS=		PROGRAM=mecrisp-stellaris-freebsd-with-disassembler-and-math
EXTRAS_VARS_OFF=	PROGRAM=mecrisp-stellaris-freebsd

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1300000
ONLY_FOR_ARCHS=	armv6 armv7
.else
ONLY_FOR_ARCHS=	armv6 armv7 aarch64
.endif
ONLY_FOR_ARCHS_REASON=	written in ARM assembly

BUILD_DEPENDS=	arm-none-eabi-binutils>2.25:devel/binutils@arm_none_eabi

AFLAGS.armv6=	-march=armv6 --defsym m0core=1
MAKE_ENV+=	AFLAGS="${AFLAGS.${ARCH}}"

# stripping eats our hand-crafted ELF binaries, so don't do that
# the binaries are free of symbols or stuff like that anyway
STRIP=

# Can't use the release script as it tries to build a bunch of stuff
# that won't build correctly.  This does the relevant parts manually.
do-build:
	cd ${WRKSRC}/mecrisp-stellaris-source/freebsd-ra && ${SETENV} ${MAKE_ENV} ${SH} -v assemble
	${CP} ${WRKSRC}/mecrisp-stellaris-source/freebsd-ra/mecrisp-stellaris-freebsd ${WRKSRC}/freebsd-ra/
	cd ${WRKSRC}/freebsd-ra && ${SETENV} ${MAKE_ENV} ${SH} -v buildcore-freebsd

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/KNOWN-ISSUES ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/common; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd-ra/${PROGRAM} ${STAGEDIR}${PREFIX}/bin/mecrisp-stellaris

.include <bsd.port.post.mk>
