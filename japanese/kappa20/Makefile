# New ports collection makefile for:	kappafont
# Date created:		8 Oct 1998
# Whom: Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	k20fonts
PORTVERSION=	0.396
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://khdd.net/20dot.fonts/:kappa20 \
		http://downloads.sourceforge.jp/x-tt/5194/:ayu20
DISTNAME=	Kappa20-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:kappa20 \
		${AYUDISTNAME}${AYU_SUFFIX}:ayu20
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ginga-freebsd@ginganet.org
COMMENT=	X11 20-dot kanji font 'Kappa20dot + ayu font'

USE_X_PREFIX=	yes
USE_BZIP2=	yes
AYUDISTNAME=	ayu20gothic-1.4
AYU_SUFFIX=	.tar.gz

BUILD_DEPENDS=	mkitalic:${PORTSDIR}/x11-fonts/mkitalic \
		bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

.include <bsd.port.pre.mk>

FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ARGS=	FONTSDIR="${FONTSDIR}"
PLIST_SUB=	FONTSDIR=${FONTSDIR}

post-extract:
	(cd ${WRKSRC} ; ${TAR} xpzf ${DISTDIR}/${AYUDISTNAME}${AYU_SUFFIX})
	(cd ${WRKSRC} ; ${MV} Makefile Makefile.dist)
	${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/fonts.alias.ayu ${WRKSRC}/

pre-build:
	(cd ${WRKSRC} ; ${SH} makebdf.sh)

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ja/${PORTNAME}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${PREFIX}/share/doc/ja/${PORTNAME}/README.euc-jp
.endif

.include <bsd.port.post.mk>
