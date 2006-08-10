# New ports collection makefile for:	GNU Backgammon
# Date created:		8 Dec 2002
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	gnubg
PORTVERSION=	0.14.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GNU_ALPHA}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}.tar.gz	\
		gnubg.weights-${GNUBG_WEIGHTS_VERSION}.gz	\
		gnubg_os0.bd.gz	gnubg_ts0.bd.gz
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Backgammon

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm \
		gmp.7:${PORTSDIR}/math/libgmp4 \
		gtkextra-x11-2.0.1:${PORTSDIR}/x11-toolkits/gtkextra2

USE_GNOME=	gnomehack gnometarget gtk20 libxml2
USE_GETOPT_LONG=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_path_ARTSC_CONFIG=no ac_cv_path_LIBART_CONFIG=no
CONFIGURE_ARGS=	--with-x --with-gtk2 --enable-nls --with-timecontrol \
		--without-board3d

MAN6=		gnubg.6
INFO=		gnubg

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

GNUBG_WEIGHTS_VERSION=	0.14

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
.else
CONFIGURE_ENV+=	ac_cv_path_AUDIOFILE_CONFIG=no ac_cv_path_ESD_CONFIG=no
.endif

.if defined(WITH_NAS)
CONFIGURE_ARGS+=	--enable-nas
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

.if defined(WITH_GUILE)
CONFIGURE_ARGS+=	--with-guile
.else
CONFIGURE_ARGS+=	--without-guile
.endif

.if defined(WITH_PYTHON)
USE_PYTHON=	2.0+
CONFIGURE_ARGS+=	--with-python
.else
CONFIGURE_ARGS+=	--without-python
.endif

post-extract:
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg.weights-${GNUBG_WEIGHTS_VERSION}.gz > ${WRKSRC}/gnubg.weights
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg_os0.bd.gz > ${WRKSRC}/gnubg_os0.bd
	${GUNZIP_CMD} --stdout ${DISTDIR}/${DIST_SUBDIR}/gnubg_ts0.bd.gz > ${WRKSRC}/gnubg_ts0.bd

post-patch:
.for file in gnubg.c makebearoff.c makebearoff1.c makehyper.c
	${REINPLACE_CMD} -e 's|"getopt\.h"|<getopt.h>|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
