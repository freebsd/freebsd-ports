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

NO_PACKAGE=	package doesn't make any sense, because kld's should be in sync with running kernel to work correctly

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}

PKGMESSAGE=	${WRKSRC}/.MESSAGE

MAKE_ENV=	WRKSRC="${WRKSRC}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400000
BROKEN=		"FreeBSD 3.* isn't supported"
.elif ${OSVERSION} < 410002
BROKEN=		"Your FreeBSD 4.1 system is too old. Please update it before installing this port"
.elif ${OSVERSION} < 420000
PORTVERSION=	1.1
DISTNAME=	au88x0-${PORTVERSION}_1
.elif ${OSVERSION} < 500000
PORTVERSION=	1.3
DISTNAME=	au88x0-${PORTVERSION}_1
.endif

pre-build:
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
