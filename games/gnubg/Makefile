# New ports collection makefile for:	GNU Backgammon
# Date created:		8 Dec 2002
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	gnubg
PORTVERSION=	0.13.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA} \
		http://triaez.kaisei.org/~kaoru/misc/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}.tar.gz	\
		gnubg.weights-${GNUBG_WEIGHTS_VERSION}.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	kaoru@kaisei.org
COMMENT=	GNU Backgammon

MAN6=	gnubg.6

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
WANT_ESOUND=	yes

.if defined(HAVE_ESOUND)
CONFIGURE_ARGS += --with-esound
.else
CONFIGURE_ARGS += --without-esound
.endif

.if defined(WITH_NAS)
CONFIGURE_ARGS += --enable-nas
.endif

.if defined(WITH_GUILE)
CONFIGURE_ARGS += --with-guile
.endif

INFO=	gnubg

GNUBG_WEIGHTS_VERSION=0.13b

post-extract:
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg.weights-${GNUBG_WEIGHTS_VERSION}.gz > ${WRKSRC}/gnubg.weights

post-build:
	@(cd ${WRKSRC} && ./makebearoff -t 6x6 -f gnubg_ts0.bd)

.include <bsd.port.mk>
