# Ports collection makefile for:	aureal-kmod
# Date created:				15 January 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aureal-kmod
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.cis.ohio-state.edu/~matey/au88x0/
DISTNAME=	au88x0-${PORTVERSION}_${PORTREVISION}

MAINTAINER=	matey@cis.ohio-state.edu

NO_PACKAGE=	Should be in sync with the kernel to work correctly

ONLY_FOR_ARCHS=	i386
SRCPREFIX?=	/usr/src
STRAYFILES=	au88x0.h au88x0.c asp10.o asp20.o asp30.o

WRKSRC=		${WRKDIR}

PKGMESSAGE=	${WRKSRC}/.MESSAGE

MAKE_ENV=	WRKSRC="${WRKSRC}"

.include <bsd.port.pre.mk>

.if exists(${SRCPREFIX}/sys/dev/sound/pcm/sound.c)
VERSION_SOUND_C!=	${AWK} '/.*\$$FreeBSD/ { print $$4; exit; }' \
				${SRCPREFIX}/sys/dev/sound/pcm/sound.c
.else
VERSION_SOUND_C=
.endif

VERSION_SOUND_C_CURRENT:=	${VERSION_SOUND_C:S/1.//}
VERSION_SOUND_C_STABLE:=	${VERSION_SOUND_C:S/1.17.2.//}

.if ${OSVERSION} < 410000
BROKEN=		"FreeBSD 3.*, 4.0 are not supported"

.elif ${OSVERSION} < 420000
# FreeBSD 4.1, 4.1.1
PORTVERSION=	1.1
PORTREVISION=	3

.elif ${OSVERSION} < 500000
# FreeBSD 4.2
PORTVERSION=    1.3

.if ${VERSION_SOUND_C_STABLE} < 4
# FreeBSD 4.2 before kobj MFC
PORTREVISION=	1

.else
# FreeBSD 4.2 after kobj MFC
PORTREVISION=	2
MAKE_ENV+=	HAVE_KOBJ_PCM=1
.endif

.endif

.if ${OSVERSION} > 500000
# FreeBSD 5-CURRENT
.if ${VERSION_SOUND_C_CURRENT} < 40
BROKEN=		"Base system is outdated. This port needs -CURRENT after newpcm megacommit (built after 3/24/2001)"
.endif
.endif

pre-fetch:
.for STRAY in ${STRAYFILES}
.if exists(${SRCPREFIX}/sys/dev/sound/pci/${STRAY})
	@${ECHO}
	@${ECHO} "You have stray code in your tree.  Make sure you"
	@${ECHO} "do not have any of the following:"
	@${ECHO}
	@${ECHO} "${SRCPREFIX}/sys/dev/sound/pci/au88x0.c"
	@${ECHO} "${SRCPREFIX}/sys/dev/sound/pci/au88x0.h"
	@${ECHO} "${SRCPREFIX}/sys/dev/sound/pci/asp10.o"
	@${ECHO} "${SRCPREFIX}/sys/dev/sound/pci/asp20.o"
	@${ECHO} "${SRCPREFIX}/sys/dev/sound/pci/asp30.o"
	@${ECHO}
	@${FALSE}
.endif
.endfor

	@if [ ! -d /sys -o ! -d ${SRCPREFIX}/sys ]; then \
		${ECHO} "****************************************" ; \
		${ECHO} " You need to extract kernel source tree" ; \
		${ECHO} " before you build this package..." ; \
		${ECHO} "****************************************" ; \
		${FALSE} ; \
	fi

pre-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > \
		${PKGMESSAGE}
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/aureal.sh > \
		${WRKDIR}/aureal.sh.sample
	${MKDIR} ${PREFIX}/lib/au88x0

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/aureal.sh.sample ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
