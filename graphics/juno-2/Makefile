# New ports collection makefile for:	juno-2
# Date created:		11 Feb 2000
# Whom:			John Polstra <jdp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	juno-2
PORTVERSION=	1.23
CATEGORIES=	graphics
MASTER_SITES=	http://www.research.compaq.com/SRC/juno-2/ \
		http://freebsd.unixfreunde.de/sources/
DISTNAME=	juno-sources

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A powerful and extensible constraint-based drawing editor

BUILD_DEPENDS=	${L1}libm3netobj${L2}:${PORTSDIR}/lang/pm3-netobj \
		${L1}libm3formsvbt${L2}:${PORTSDIR}/lang/pm3-forms
RUN_DEPENDS=	${L1}libm3netobj${L2}:${PORTSDIR}/lang/pm3-netobj \
		${L1}libm3formsvbt${L2}:${PORTSDIR}/lang/pm3-forms

MAN1=		Juno.1
PLIST_SUB+=	SOVERSION=${SOVERSION} TARGET=${TARGET} \
		INST_TARGET=${INST_TARGET} WORDSIZE=${WORDSIZE}

BUILD1=		juno-machine \
		juno-compiler
BUILD2=		juno-app
L1=		${PREFIX}/lib/m3/${TARGET}/
PROGS=		bin/Juno
SOVERSION=	7

DATADIR=	${PREFIX}/share/Juno
EXAMPLESDIR=	${PREFIX}/share/examples/Juno

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
L2=		.so.${SOVERSION}
TARGET=		FreeBSD4
INST_TARGET=	freebsd-4
WORDSIZE=	32
.elif ${ARCH} == "alpha"
CFLAGS+=	-mieee
L2=		.so.${SOVERSION}
TARGET=		FBSD_ALPHA
INST_TARGET=	fbsd-alpha
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
	@for i in ${BUILD1}; do \
	    ${ECHO_MSG} "Building in $${i}"; \
	    (cd ${WRKSRC}/$${i} && ${PREFIX}/bin/m3build && \
		${PREFIX}/bin/m3ship) \
	done
	@${ECHO_MSG} "Generating font metrics"
	@(cd ${WRKSRC}/juno-app/pkl-fonts; ${PREFIX}/bin/m3build; \
	    cd ${TARGET}; ./PklFonts > FontData.pkl)
	@for i in ${BUILD2}; do \
	    ${ECHO_MSG} "Building in $${i}"; \
	    (cd ${WRKSRC}/$${i} && ${PREFIX}/bin/m3build && \
		${PREFIX}/bin/m3ship) \
	done
	@for i in ${PROGS}; do ${STRIP_CMD} ${PREFIX}/$$i; done
	@${ECHO_MSG} "Installing examples into ${EXAMPLESDIR}"
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/juno-app/juno-src/* ${EXAMPLESDIR}
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${FILESDIR}/COPYRIGHT ${DATADIR}

.include <bsd.port.post.mk>
