# $FreeBSD$

PORTNAME=	mecrisp-stellaris
DISTVERSION=	2.5.6
CATEGORIES=	lang
MASTER_SITES=	SF/mecrisp

MAINTAINER=	fuz@fuz.su
COMMENT=	Native code Forth system for ARM

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	armv7
ONLY_FOR_ARCHS_REASON=	written in ARM Thumb2 assembly

# stripping eats our hand-crafted ELF binaries, so don't do that
# the binaries are free of symbols or stuff like that anyway
STRIP=
# definitions assuming we build on ARM
BINARY_ALIAS=	arm-none-eabi-as=${AS} \
		arm-none-eabi-ld=${LD} \
		arm-none-eabi-objcopy=${OBJCOPY}

OPTIONS_DEFINE=		EXTRAS
OPTIONS_DEFAULT=	EXTRAS
EXTRAS_DESC=		Add disassembler and math library to Forth core
EXTRAS_VARS=		PROGRAM=mecrisp-stellaris-freebsd-with-disassembler-and-math
EXTRAS_VARS_OFF=	PROGRAM=mecrisp-stellaris-freebsd

.include <bsd.port.options.mk>

# Can't use the release script as it tries to build a bunch of stuff
# that won't build correctly.  This does the relevant parts manually.
do-build:
	cd ${WRKSRC}/mecrisp-stellaris-source/freebsd-ra && ${SETENV} ${MAKE_ENV} ${SH} assemble
	${CP} ${WRKSRC}/mecrisp-stellaris-source/freebsd-ra/mecrisp-stellaris-freebsd ${WRKSRC}/freebsd-ra/
	cd ${WRKSRC}/freebsd-ra && ${SETENV} ${MAKE_ENV} ${SH} buildcore-freebsd

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/KNOWN-ISSUES ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/common; ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
	${INSTALL_PROGRAM} ${WRKSRC}/freebsd-ra/${PROGRAM} ${STAGEDIR}${PREFIX}/bin/mecrisp-stellaris

.include <bsd.port.mk>
