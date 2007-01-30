# New ports collection makefile for:	pm3-forms
# Date created:		6 Feb 2000
# Whom:			John Polstra <jdp@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pm3-forms
PORTVERSION=	1.1.15
CATEGORIES=	lang
DISTFILES=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High-level GUI libraries and tools for the PM3 Modula-3 distribution

BUILD_DEPENDS=	${L1}libm3vbtkit${L2}:${PORTSDIR}/lang/pm3-gui \
		${NONEXISTENT}:${PORTSDIR}/lang/pm3-base:build
RUN_DEPENDS=	${L1}libm3vbtkit${L2}:${PORTSDIR}/lang/pm3-gui

DIST_SUBDIR=	pm3
INSTALL_TARGET=	all
MAN1=		formsedit.1
PLIST_SUB+=	SOVERSION=${SOVERSION} TARGET=${TARGET} \
		INST_TARGET=${INST_TARGET} WORDSIZE=${WORDSIZE}
WRKSRC=		${WRKDIRPREFIX}${.CURDIR}/../pm3-base/work/pm3-${PORTVERSION}

BUILDDIRS=	network/www/web \
		graphics/gr-libs/jvideo \
		graphics/gr-libs/videovbt \
		graphics/forms/formsvbtpixmaps \
		graphics/forms/formsvbt \
		graphics/forms/formsedit
L1=		${PREFIX}/lib/m3/${TARGET}/
PROGS=		bin/formsedit
SOVERSION=	7
# hack to work around bsd.port.mk problem
USE_BZIP2=	yes
USE_GMAKE=	yes

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
	    cd ${WRKSRC}/$${i} && ${PREFIX}/bin/m3build && \
		${PREFIX}/bin/m3ship; \
	done
	@for i in ${PROGS}; do ${STRIP_CMD} ${PREFIX}/$$i; done
	@${MKDIR} ${PREFIX}/share/pm3-forms
	@${INSTALL_DATA} ${WRKSRC}/src/COPYRIGHT ${PREFIX}/share/pm3-forms

.include <bsd.port.post.mk>
