# New ports collection makefile for:	gauche-gdbm
# Date created:		9 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gdbm
PORTVERSION=	0.8.5	# Keep this in sync with lang/gauche
CATEGORIES=	databases scheme
MASTER_SITES=	# none
PKGNAMEPREFIX=	gauche-
DISTFILES=	# none

MAINTAINER=	erik@smluc.org
COMMENT=	GDBM interface for Gauche

BUILD_DEPENDS=	gosh:${PORTSDIR}/${GAUCHE_PORT} \
		${NONEXISTENT}:${PORTSDIR}/${GAUCHE_PORT}:build
LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm
RUN_DEPENDS=	gosh:${PORTSDIR}/${GAUCHE_PORT}

GAUCHE_PORT=	lang/gauche

WRKSRC=		${WRKDIR}/dbm
MAKE_ARGS=	GOSH=gosh \
		OPTFLAGS="${CFLAGS} -I${LOCALBASE}/include"
PLIST_SUB=	VERSION="${PORTVERSION}" \
		TARGET="${CONFIGURE_TARGET}"
USE_REINPLACE=	yes

GUACHE_BUILDDIR=`cd ${PORTSDIR}/${GAUCHE_PORT} && ${MAKE} -V WRKSRC`

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf ${GUACHE_BUILDDIR}/ext/dbm ${WRKDIR}/

do-configure:
	cd ${WRKSRC} && make clean && ${REINPLACE_CMD} -e 's/^LIBFILES.*/LIBFILES = gdbm.so/' -e 's/^SCMFILES.*/SCMFILES = gdbm.scm/' Makefile

do-install:
	cd ${WRKSRC} && make install-std

.include <bsd.port.mk>
