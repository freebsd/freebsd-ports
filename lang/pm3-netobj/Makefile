# New ports collection makefile for:	pm3-netobj
# Date created:		11 Feb 2000
# Whom:			John Polstra <jdp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pm3-netobj
PORTVERSION=	1.1.15
CATEGORIES=	lang
DISTFILES=

MAINTAINER=	jdp@FreeBSD.org
COMMENT=	PM3 distributed objects package supporting robust distributed applications

BUILD_DEPENDS=	${L1}libm3tcp${L2}:${PORTSDIR}/lang/pm3-net \
		${L1}libm3tk${L2}:${PORTSDIR}/lang/pm3-m3tk
RUN_DEPENDS=	${L1}libm3tcp${L2}:${PORTSDIR}/lang/pm3-net \
		${L1}libm3tk${L2}:${PORTSDIR}/lang/pm3-m3tk
DEPENDS=	${PORTSDIR}/lang/pm3-base:configure

DIST_SUBDIR=	pm3
INSTALL_TARGET=	all
MAN1=		netobjd.1 stubgen.1
PLIST_SUB+=	SOVERSION=${SOVERSION} TARGET=${TARGET} \
		TARGETDIR=${TARGETDIR} WORDSIZE=${WORDSIZE}
WRKSRC=		${WRKDIRPREFIX}${.CURDIR}/../pm3-base/work/pm3-${PORTVERSION}

BUILDDIRS=	network/netobjects/netobj \
		network/netobjects/netobjd \
		network/netobjects/stubgen
PROGS=		bin/netobjd \
		bin/stubgen
L1=		${PREFIX}/lib/m3/${TARGET}/
SOVERSION=	7
# hack to work around bsd.port.mk problem
USE_BZIP2=	yes

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
L2=		.so.${SOVERSION}.0
TARGET=		FreeBSD2
TARGETDIR=	freebsd-2
WORDSIZE=	32
.elif ${ARCH} == "i386"
L2=		.so.${SOVERSION}
.if ${OSVERSION} < 400011
TARGET=		FreeBSD3
TARGETDIR=	freebsd-3
.else
TARGET=		FreeBSD4
TARGETDIR=	freebsd-4
.endif
WORDSIZE=	32
.elif ${ARCH} == "alpha"
.if ${OSVERSION} < 400011
IGNORE=		Not supported on older versions of FreeBSD/Alpha
.endif
CFLAGS+=	-mieee
L2=		.so.${SOVERSION}
TARGET=		FBSD_ALPHA
TARGETDIR=	fbsd-alpha
WORDSIZE=	64
.endif

.if !defined(TARGET)
pre-fetch:
	@${ECHO_MSG} "Cannot determine M3 target for this architecture"
	@${FALSE}
.endif

do-build:
	@${ECHO_MSG} "This port does everything in the install step."
	@${ECHO_MSG} "The build step is a no-op."

do-install:
	@for i in ${BUILDDIRS}; do \
	    ${ECHO_MSG} "Building in $${i}"; \
	    cd ${WRKSRC}/$${i} && ${PREFIX}/bin/m3build && \
		${PREFIX}/bin/m3ship; \
	done
	@for i in ${PROGS}; do ${STRIP_CMD} ${PREFIX}/$$i; done
	@${MKDIR} ${PREFIX}/share/pm3-netobj
	@${INSTALL_DATA} ${WRKSRC}/src/COPYRIGHT ${PREFIX}/share/pm3-netobj

.include <bsd.port.post.mk>
