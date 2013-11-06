# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	aureal
PORTVERSION=	1.5
PORTREVISION=	6
CATEGORIES=	audio kld
MASTER_SITES=	http://www.matey.org/au88x0/ \
		http://www.b1t.name/distfiles/ \
		http://aureal-snd.googlecode.com/files/
PKGNAMESUFFIX=	-kmod
DISTNAME=	au88x0-${PORTVERSION}_${DISTREVISION}

MAINTAINER=	c.kworr@gmail.com
COMMENT=	A FreeBSD Driver for Aureal Vortex based soundcards

BROKEN=		Does not fetch

NO_PACKAGE=	Should be in sync with the kernel to work correctly

ONLY_FOR_ARCHS=	i386
STRAYFILES=	au88x0.h au88x0.c asp10.o asp20.o asp30.o
DISTREVISION=	4

KMODDIR=	${PREFIX}/modules/au88x0
KMODDIR_REL=	${KMODDIR:S%${PREFIX}/%%}

NO_STAGE=	yes
USE_RC_SUBR=	aureal
SUB_FILES=	pkg-message
SUB_LIST=	KMODDIR=${KMODDIR}

PLIST_SUB=	KMODDIR=${KMODDIR_REL}

WRKSRC=		${WRKDIR}

MAKE_ENV=	WRKSRC="${WRKSRC}"
MAKE_ARGS=	KMODDIR="${KMODDIR}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
EXTRA_PATCHES+=	${PATCHDIR}/extra_800000_patch-au88x0.c
.endif

# Make sure kernel sources are present before going any further
.if ! exists(${SRC_BASE}/sys/dev/sound/pcm/sound.c)
IGNORE=	you need to extract kernel source tree before building this package
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

pre-install:
	${MKDIR} ${KMODDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
