# New ports collection makefile for:	gauche-gdbm
# Date created:		9 September 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gdbm
PORTVERSION=	0.6.2
CATEGORIES=	databases
MASTER_SITES=	# none
PKGNAMEPREFIX=	gauche-
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	gosh:${PORTSDIR}/${GAUCHE_PORT} \
		${NONEXISTENT}:${PORTSDIR}/${GAUCHE_PORT}:configure
LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm
RUN_DEPENDS=	gosh:${PORTSDIR}/${GAUCHE_PORT}

GAUCHE_PORT=	lang/gauche

WRKSRC=		${WRKDIR}/dbm
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	GOSH=gosh \
		OPTFLAGS="${CFLAGS} -I${LOCALBASE}/include"
PLIST_SUB=	VERSION="${PORTVERSION}" \
		TARGET="${CONFIGURE_TARGET}"

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${PORTSDIR}/${GAUCHE_PORT}; ${MAKE} -V WRKSRC`/ext/dbm ${WRKDIR}/

do-install:
	${INSTALL_DATA} ${WRKSRC}/gdbm.scm `gauche-config --syslibdir`/dbm/
	${INSTALL_DATA} ${WRKSRC}/gdbm.so `gauche-config --sysarchdir`/

.include <bsd.port.mk>
