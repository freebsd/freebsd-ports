# Ports collection makefile for:	aureal-kmod
# Date created:				15 January 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aureal-kmod
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.cis.ohio-state.edu/~matey/au88x0/
DISTNAME=	au88x0-${PORTVERSION}

MAINTAINER=	matey@cis.ohio-state.edu

NO_PACKAGE=	Should be in sync with the kernel to work correctly

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}

PKGMESSAGE=	${WRKSRC}/.MESSAGE

MAKE_ENV=	WRKSRC="${WRKSRC}"

.include <bsd.port.pre.mk>

.if exists(/usr/src/sys/dev/sound/pcm/sound.c)
VERSION_SOUND_C!=	${AWK} '/.*\$$FreeBSD/ { print $$4; exit; }' \
				/usr/src/sys/dev/sound/pcm/sound.c
.else
VERSION_SOUND_C=
.endif

VERSION_SOUND_C:=	${VERSION_SOUND_C:S/.//g}

.if ${OSVERSION} < 410000
BROKEN=		"FreeBSD 3.*, 4.0 are not supported"

.elif ${OSVERSION} < 420000
# FreeBSD 4.1, 4.1.1
PORTVERSION=	1.1
PORTREVISION=	2

.elif ${OSVERSION} < 500000
# FreeBSD 4.2
PORTVERSION=    1.3

.if ${VERSION_SOUND_C} < 11724
# FreeBSD 4.2 before kobj MFC
PORTREVISION=	1

.else
# FreeBSD 4.2 after kobj MFC
PORTREVISION=	2
MAKE_ENV+=	HAVE_KOBJ_PCM=1
.endif

.endif

.if ${OSVERSION} < 500000
DISTNAME=	au88x0-${PORTVERSION}_${PORTREVISION}
.endif

pre-fetch:
	@if [ ! -d /sys -o ! -d /usr/src/sys ]; then \
		${ECHO} "****************************************" ; \
		${ECHO} " You need to extract kernel source tree" ; \
		${ECHO} " before you build this package..." ; \
		${ECHO} "****************************************" ; \
		${FALSE} ; \
	fi

pre-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	${MKDIR} ${PREFIX}/lib/au88x0

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
