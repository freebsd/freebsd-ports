# Ports collection makefile for:	aureal-kmod
# Date created:				15 January 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aureal-kmod
PORTVERSION=	1.5
PORTREVISION=	5
CATEGORIES=	audio kld
MASTER_SITES=	http://www.matey.org/au88x0/
DISTNAME=	au88x0-${PORTVERSION}_${DISTREVISION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A FreeBSD Driver for Aureal Vortex based soundcards

NO_PACKAGE=	Should be in sync with the kernel to work correctly

ONLY_FOR_ARCHS=	i386
SRCPREFIX?=	/usr/src
STRAYFILES=	au88x0.h au88x0.c asp10.o asp20.o asp30.o
DISTREVISION=	4

WRKSRC=		${WRKDIR}

PKGMESSAGE=	${WRKSRC}/.MESSAGE

MAKE_ENV=	WRKSRC="${WRKSRC}"

# Make sure kernel sources are present before going any further
.if ! exists(${SRCPREFIX}/sys/dev/sound/pcm/sound.c)
IGNORE=	"You need to extract kernel source tree before building this package"
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

pre-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > \
		${PKGMESSAGE}
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/aureal.sh > \
		${WRKDIR}/aureal.sh.sample
	${MKDIR} ${PREFIX}/lib/au88x0

post-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/aureal.sh.sample ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
