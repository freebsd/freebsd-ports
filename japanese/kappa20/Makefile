# New ports collection makefile for:	kappafont
# Date created:		8 Oct 1998
# Whom: Kawaguti Ginga <ginga@athena.club.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	k20fonts
PORTVERSION=	0.396
PORTREVISION=	3
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://khdd.net/20dot.fonts/:kappa20 \
		http://downloads.sourceforge.jp/x-tt/8412/:ayu20
DISTNAME=	Kappa20-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:kappa20 \
		${AYUDISTNAME}${AYU_SUFFIX}:ayu20
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ginga-freebsd@ginganet.org
COMMENT=	X11 20-dot kanji font 'Kappa20dot + ayu font'

USE_X_PREFIX=	yes
USE_BZIP2=	yes
AYUDISTNAME=	ayu20gothic-1.6
AYU_SUFFIX=	.tar.gz

BUILD_DEPENDS=	mkitalic:${PORTSDIR}/x11-fonts/mkbold-mkitalic \
		bdftopcf:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

.include <bsd.port.pre.mk>

FONTSDIR=	lib/X11/fonts/local
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ARGS=	FONTSDIR="${FONTSDIR}"
PLIST_SUB=	FONTSDIR=${FONTSDIR}
DOCSDIR=	${PREFIX}/share/doc/ja/${PORTNAME}

post-extract:
	(cd ${WRKSRC} ; ${TAR} xpzf ${DISTDIR}/${AYUDISTNAME}${AYU_SUFFIX})
	(cd ${WRKSRC} ; ${MV} Makefile Makefile.dist)
	${CP} ${FILESDIR}/Makefile.in ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/fonts.alias.ayu ${WRKSRC}/

pre-build:
	(cd ${WRKSRC} ; ${SH} makebdf.sh)

pre-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/fonts.alias ${DOCSDIR}
	@${CAT} ${WRKSRC}/fonts.alias >> ${PREFIX}/${FONTSDIR}/fonts.alias
.if !defined(NOPORTDOCS)
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README.euc-jp
.endif

post-install:
	@(cd ${PREFIX}/${FONTSDIR} ; mkfontdir)

.include <bsd.port.post.mk>
