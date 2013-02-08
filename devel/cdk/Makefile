# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	cdk
PORTVERSION=	5.0.20120323
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/cdk/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Curses Development Kit for speedy development of full screen programs

LICENSE=	BSD

USE_GMAKE=	yes
USE_NCURSES=	yes
GNU_CONFIGURE=	yes
PORTDOCS=	COPYING EXPANDING INSTALL NOTES README TODO
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

CONFIGURE_ARGS+=--with-ncurses
ALL_TARGET=	default examples demos cli cdkshlib
INSTALL_TARGET=	install installCDKSHLibrary
USE_LDCONFIG=	yes

.include "${.CURDIR}/maninfo.mk"

post-extract:
.if ! ${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES+=      ${FILESDIR}/extra-patch-Makefile.in
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/doc/cdk|/share/doc/cdk| ; s|VERSION)|VERSION_MAJOR)|' \
		-e 's|gcc|${CC}|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(INSTALL_DATA) cdk-config|$(INSTALL_SCRIPT) cdk-config|g' \
		${WRKSRC}/Makefile.in

pre-install:
.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
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

.include <bsd.port.mk>
