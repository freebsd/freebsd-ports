# New ports collection makefile for:    hLaTeXp pkfonts 300dpi
# Date created:                 Jun 28 2000
# Whom:                         CHOI Junho <cjh@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hLaTeXp-pkfonts
PORTVERSION=	1996.12.24
PKGNAMESUFFIX=	-${RESOLUTION}dpi
CATEGORIES=	korean print
MASTER_SITES=	ftp://knot.kaist.ac.kr/pub/htex/htex-fonts/
DISTFILES=	han.${RESOLUTION}pk.tar.gz hanja.${RESOLUTION}pk.tar.gz symb.${RESOLUTION}pk.tar.gz
DIST_SUBDIR=	htex

MAINTAINER=	cjh@FreeBSD.org

# it depends hLaTeXp
RUN_DEPENDS=	hlatex:${PORTSDIR}/korean/hlatexp

NO_BUILD=	YES
PLIST_SUB=	RESOLUTION=${RESOLUTION}

TEXMF=		${PREFIX}/share/texmf

# pkfonts dpi
RESOLUTION?=	300

do-install:
	### pk files
	${MKDIR} ${TEXMF}/fonts/pk/xhan${RESOLUTION}
.if ${RESOLUTION} == 1200
	### 1200dpi has different structure
	${INSTALL_DATA} ${WRKDIR}/x[a-j]*pk ${TEXMF}/fonts/pk/xhan${RESOLUTION}/
	${INSTALL_DATA} ${WRKDIR}/x[k-t]*pk ${TEXMF}/fonts/pk/xhan${RESOLUTION}/
.else

	### 300,600dpi
.for path in han.${RESOLUTION}pk hanja.${RESOLUTION}pk symb.${RESOLUTION}pk
	${INSTALL_DATA} ${WRKDIR}/${path}/* ${TEXMF}/fonts/pk/xhan${RESOLUTION}/
.endfor

.endif
	${CHMOD} -R a+r ${TEXMF}/fonts/pk/xhan${RESOLUTION}
	### rehash
	${PREFIX}/bin/texhash

.include <bsd.port.mk>
