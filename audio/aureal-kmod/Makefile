# Ports collection makefile for:	aureal-kmod
# Date created:				15 January 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aureal-kmod
PORTVERSION=	1.5
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://home.columbus.rr.com/amatey/au88x0/
DISTNAME=	au88x0-${PORTVERSION}_${PORTREVISION}

MAINTAINER=	lx@matey.org

NO_PACKAGE=	Should be in sync with the kernel to work correctly

ONLY_FOR_ARCHS=	i386
SRCPREFIX?=	/usr/src
STRAYFILES=	au88x0.h au88x0.c asp10.o asp20.o asp30.o

WRKSRC=		${WRKDIR}

PKGMESSAGE=	${WRKSRC}/.MESSAGE

MAKE_ENV=	WRKSRC="${WRKSRC}"

.include <bsd.port.pre.mk>

.if exists(${SRCPREFIX}/sys/dev/sound/pcm/sound.c)
VERSION_SOUND_C!=	ident < ${SRCPREFIX}/sys/dev/sound/pcm/sound.c | \
			${AWK} '{ print $$3; exit }'
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

.elif ${OSVERSION} < 440000
# FreeBSD 4.2, 4.3
PORTVERSION=    1.3

.if ${VERSION_SOUND_C_STABLE} < 4
# FreeBSD 4.2 before kobj MFC
PORTREVISION=	1

.else
# FreeBSD 4.2 after kobj MFC, FreeBSD 4.3
PORTREVISION=	2
MAKE_ENV+=	HAVE_KOBJ_PCM=1
.endif

.elif ${OSVERSION} < 450004
# FreeBSD 4.4, 4.5-
PORTVERSION=	1.3
PORTREVISION=	3
MAKE_ENV+=	HAVE_KOBJ_PCM=1

.elif ${OSVERSION} < 500000
# FreeBSD 4.5+
.if ${VERSION_SOUND_C_STABLE} < 12
BROKEN=		"Base system is outdated. This port needs -STABLE after 2002-04-22."
.endif
PORTVERSION=	1.3
PORTREVISION=	4
MAKE_ENV+=	HAVE_KOBJ_PCM=1
.endif

.if ${OSVERSION} > 500000
# FreeBSD 5-CURRENT
.if ${VERSION_SOUND_C_CURRENT} < 70
BROKEN=		"Base system is outdated. This port needs -CURRENT after 2002-04-04."
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
	@if [ ! -d /sys -a ! -d ${SRCPREFIX}/sys ]; then \
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
