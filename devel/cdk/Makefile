# ex:ts=8
# New ports collection makefile for:	cdk
# Date created:				6 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	cdk
PORTVERSION=	4.9.10.20020809
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://dickey.his.com/cdk/
DISTNAME=	${PORTNAME}-4.9.10-20020809
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses Development Kit for speedy development of full screen programs

USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
NOPRECIOUSMAKEVARS= yes # Otherwise 'make readmes' is broken

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/include/ncurses/ncurses.h)
TERMINFO=	${LOCALBASE}/share/misc/terminfo
CPPFLAGS=	-I${LOCALBASE}/include -I${LOCALBASE}/include/ncurses
LIBS+=		-L${LOCALBASE}/lib -lncurses
LDFLAGS+=	-Wl,-rpath,${LOCALBASE}/lib
CONFIGURE_ENV+=	TERMINFO="${TERMINFO}"\
		CPPFLAGS="${CPPFLAGS}"\
		LIBS="${LIBS}"\
		LDFLAGS="${LDFLAGS}"
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif # exists(${LOCALBASE}/include/ncurses/ncurses.h)

CONFIGURE_ARGS+=--with-ncurses
ALL_TARGET=	default examples demos cli cdkshlib
INSTALL_TARGET=	install installCDKSHLibrary
INSTALLS_SHLIB=	yes

.include "${.CURDIR}/maninfo.mk"

post-configure:
	${REINPLACE_CMD} -e 's|^DOCUMENT_DIR.*$$|DOCUMENT_DIR=${DOCSDIR}|' \
		-e 's|^CDKSHLIB.*$$|CDKSHLIB=$$(SONAME)|' \
		${WRKSRC}/Makefile

post-install:
	${MKDIR} ${EXAMPLESDIR}/cli
	cd ${WRKSRC}/cli; \
	${FIND} . | ${CPIO} -pdm -R ${LIBOWN}:${LIBGRP} ${EXAMPLESDIR}/cli
	${MKDIR} ${EXAMPLESDIR}/demos
	cd ${WRKSRC}/demos; \
	${FIND} . | ${CPIO} -pdm -R ${LIBOWN}:${LIBGRP} ${EXAMPLESDIR}/demos
	${MKDIR} ${EXAMPLESDIR}/examples
	cd ${WRKSRC}/examples; \
	${FIND} . | ${CPIO} -pdm -R ${LIBOWN}:${LIBGRP} ${EXAMPLESDIR}/examples

.include <bsd.port.post.mk>
