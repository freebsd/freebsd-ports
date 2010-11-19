# ex:ts=8
# New ports collection makefile for:	cdk
# Date created:				6 May 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	cdk
PORTVERSION=	5.0.20090215
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/cdk/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Curses Development Kit for speedy development of full screen programs

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
PORTDOCS=	COPYING EXPANDING INSTALL NOTES README TODO
MAKE_JOBS_UNSAFE=	yes

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
USE_LDCONFIG=	yes

.include "${.CURDIR}/maninfo.mk"

post-extract:
.if defined(NOPORTDOCS)
EXTRA_PATCHES+=      ${FILESDIR}/extra-patch-Makefile.in
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/doc/cdk|/share/doc/cdk| ; s|VERSION)|VERSION_MAJOR)|' ${WRKSRC}/Makefile.in

pre-install:
.if !defined(NOPORTEXAMPLES)
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

post-install:
.if !defined(NOPORTEXAMPLES)
	${INSTALL} -d ${EXAMPLESDIR}
	${INSTALL} -d ${EXAMPLESDIR}/cli
	cd ${WRKSRC}/cli; \
	${FIND} . | ${CPIO} -pdm -R ${LIBOWN}:${LIBGRP} ${EXAMPLESDIR}/cli
	${INSTALL} -d ${EXAMPLESDIR}/demos
	cd ${WRKSRC}/demos; \
	${FIND} . | ${CPIO} -pdm -R ${LIBOWN}:${LIBGRP} ${EXAMPLESDIR}/demos
	${INSTALL} -d ${EXAMPLESDIR}/examples
	cd ${WRKSRC}/examples; \
	${FIND} . | ${CPIO} -pdm -R ${LIBOWN}:${LIBGRP} ${EXAMPLESDIR}/examples
.endif

.include <bsd.port.post.mk>
