# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aureal
PORTVERSION=	1.5
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	${PORTNAME}-snd
PKGNAMESUFFIX=	-kmod
DISTNAME=	au88x0-${PORTVERSION}_4

MAINTAINER=	c.kworr@gmail.com
COMMENT=	Driver for Aureal Vortex based soundcards

ONLY_FOR_ARCHS=	i386
STRAYFILES=	au88x0.h au88x0.c asp10.o asp20.o asp30.o

KMODDIR=	${PREFIX}/modules/au88x0
KMODDIR_REL=	${KMODDIR:S%${PREFIX}/%%}

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
SUB_LIST=	KMODDIR=${KMODDIR}

WRKSRC=		${WRKDIR}

MAKE_ENV=	WRKSRC="${WRKSRC}"
MAKE_ARGS=	KMODDIR="${KMODDIR}"

USES=		kmod

.include <bsd.port.pre.mk>

EXTRA_PATCHES+=	${PATCHDIR}/extra_800000_patch-au88x0.c

.if ${OSVERSION} >= 1000000
BROKEN=	does not build
.endif

pre-everything::
.for STRAY in ${STRAYFILES}
.if exists(${SRC_BASE}/sys/dev/sound/pci/${STRAY})
	@${ECHO}
	@${ECHO} "You have stray code in your tree.  Make sure you"
	@${ECHO} "do not have any of the following:"
	@${ECHO}
	@${ECHO} "${SRC_BASE}/sys/dev/sound/pci/au88x0.c"
	@${ECHO} "${SRC_BASE}/sys/dev/sound/pci/au88x0.h"
	@${ECHO} "${SRC_BASE}/sys/dev/sound/pci/asp10.o"
	@${ECHO} "${SRC_BASE}/sys/dev/sound/pci/asp20.o"
	@${ECHO} "${SRC_BASE}/sys/dev/sound/pci/asp30.o"
	@${ECHO}
	@${FALSE}
.endif
.endfor

.include <bsd.port.post.mk>
