# New ports collection makefile for:	pm3-m3tk
# Date created:		11 Feb 2000
# Whom:			John Polstra <jdp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pm3-m3tk
PORTVERSION=	1.1.15
CATEGORIES=	lang
DISTFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modula-3 source code analysis and transformation toolkit (PM3 distribution)

BUILD_DEPENDS=	${L1}libm3${L2}:${PORTSDIR}/lang/pm3-base \
		/nonexistent:${PORTSDIR}/lang/pm3-base:configure
RUN_DEPENDS=	${L1}libm3${L2}:${PORTSDIR}/lang/pm3-base

DIST_SUBDIR=	pm3
INSTALL_TARGET=	all
PLIST_SUB+=	SOVERSION=${SOVERSION} TARGET=${TARGET} \
		INST_TARGET=${INST_TARGET} WORDSIZE=${WORDSIZE}
WRKSRC=		${WRKDIRPREFIX}${.CURDIR}/../pm3-base/work/pm3-${PORTVERSION}

BUILDDIRS=	language/modula3/m3tools/m3tk
L1=		${PREFIX}/lib/m3/${TARGET}/
SOVERSION=	7
USE_GMAKE=	yes
# hack to work around bsd.port.mk problem
USE_BZIP2=	yes

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
	@for i in ${BUILDDIRS}; do \
	    ${ECHO_MSG} "Building in $${i}"; \
	    (ulimit -d `ulimit -Hd` && ulimit -m `ulimit -Hm` && \
		cd ${WRKSRC}/$${i} && ${PREFIX}/bin/m3build && \
		    ${PREFIX}/bin/m3ship) \
	done
	@${MKDIR} ${PREFIX}/share/pm3-m3tk
	@${INSTALL_DATA} ${WRKSRC}/src/COPYRIGHT ${PREFIX}/share/pm3-m3tk

.include <bsd.port.post.mk>
