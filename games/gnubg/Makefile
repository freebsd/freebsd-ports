# New ports collection makefile for:	GNU Backgammon
# Date created:		8 Dec 2002
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	gnubg
PORTVERSION=	0.13.0
CATEGORIES=	games
MASTER_SITES=	ftp://alpha.gnu.org/gnu/gnubg/
DISTFILES=	${DISTNAME}.tar.gz	\
		gnubg.weights-${GNUBG_WEIGHTS_VERSION}.gz	\
		gnubg_ts0.bd.gz gnubg_os0.bd.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	kaoru@kaisei.org
COMMENT=	GNU Backgammon

MAN6=	gnubg.6

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GTK=	yes
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

GNUBG_WEIGHTS_VERSION=0.13b

do-patch:
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg_ts0.bd.gz > ${WRKSRC}/gnubg_ts0.bd
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg_os0.bd.gz > ${WRKSRC}/gnubg_os0.bd
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg.weights-${GNUBG_WEIGHTS_VERSION}.gz > ${WRKSRC}/gnubg.weights

.include <bsd.port.mk>
