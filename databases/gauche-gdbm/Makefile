# New ports collection makefile for:	gauche-gdbm
# Date created:		9 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gdbm
PORTVERSION=	0.8.1	# Keep this in sync with lang/gauche
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

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${PORTSDIR}/${GAUCHE_PORT} && ${MAKE} -V WRKSRC`/ext/dbm ${WRKDIR}/

do-configure:
	cd `cd ${PORTSDIR}/${GAUCHE_PORT} && ${MAKE} -V WRKSRC` && ./configure --with-local=${LOCALBASE} --prefix=${LOCALBASE} --target=${CONFIGURE_TARGET} --host=${CONFIGURE_HOST} --build=${CONFIGURE_BUILD} && cd ext && ${REINPLACE_CMD} -e "s/archdir/&|sed 's,unknown-freebsd,portbld-freebsd,'/" Makefile.ext
	cd ${WRKSRC} && make clean && ${REINPLACE_CMD} -e 's/^LIBFILES.*/LIBFILES = gdbm.so/' -e 's/^SCMFILES.*/SCMFILES = gdbm.scm/' Makefile

do-install:
	cd ${WRKSRC} && make install-std

.include <bsd.port.mk>
