# New ports collection makefile for:	GNU Backgammon
# Date created:		8 Dec 2002
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	gnubg
PORTVERSION=	0.14.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA} \
		http://triaez.kaisei.org/~kaoru/misc/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}.tar.gz	\
		gnubg.weights-${GNUBG_WEIGHTS_VERSION}.gz	\
		gnubg_os0.bd.gz	gnubg_ts0.bd.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	kaoru@kaisei.org
COMMENT=	GNU Backgammon

MAN6=	gnubg.6

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	libxml2 gtk20
WANT_ESOUND=	yes

CONFIGURE_ARGS+=	--with-x --with-gtk2 --enable-nls --with-timecontrol --without-board3d

.if defined(HAVE_ESOUND)
CONFIGURE_ARGS += --with-esound
.else
CONFIGURE_ARGS += --without-esound
.endif

.if defined(WITH_NAS)
CONFIGURE_ARGS += --enable-nas
.else
CONFIGURE_ARGS += --disable-nas
.endif

.if defined(WITH_GUILE)
CONFIGURE_ARGS += --with-guile
.else
CONFIGURE_ARGS += --without-guile
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	2.0+
CONFIGURE_ARGS += --with-python
.else
CONFIGURE_ARGS += --without-python
.endif

INFO=	gnubg

GNUBG_WEIGHTS_VERSION=0.14

post-extract:
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg.weights-${GNUBG_WEIGHTS_VERSION}.gz > ${WRKSRC}/gnubg.weights
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg_os0.bd.gz > ${WRKSRC}/gnubg_os0.bd
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg_ts0.bd.gz > ${WRKSRC}/gnubg_ts0.bd

.include <bsd.port.mk>
