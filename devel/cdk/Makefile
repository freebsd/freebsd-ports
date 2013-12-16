# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	cdk
PORTVERSION=	5.0.20120323
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/cdk/ \
		http://fossies.org/linux/misc/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses Development Kit for speedy development of full screen programs

LICENSE=	BSD

USES=		ncurses gmake
GNU_CONFIGURE=	yes
PORTDOCS=	COPYING EXPANDING INSTALL NOTES README TODO
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS+=--with-ncurses
ALL_TARGET=	default examples demos cli cdkshlib
INSTALL_TARGET=	install installCDKSHLibrary
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/doc/cdk|/share/doc/cdk| ; s|VERSION)|VERSION_MAJOR)|' \
		-e 's|gcc|${CC}|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(INSTALL_DATA) cdk-config|$(INSTALL_SCRIPT) cdk-config|g' \
		${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/cli
	cd ${WRKSRC}/cli; \
	${FIND} . | ${CPIO} -pdm -R ${LIBOWN}:${LIBGRP} ${STAGEDIR}${EXAMPLESDIR}/cli
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/demos
	cd ${WRKSRC}/demos; \
	${FIND} . | ${CPIO} -pdm -R ${LIBOWN}:${LIBGRP} ${STAGEDIR}${EXAMPLESDIR}/demos
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/examples
	cd ${WRKSRC}/examples; \
	${FIND} . | ${CPIO} -pdm -R ${LIBOWN}:${LIBGRP} ${STAGEDIR}${EXAMPLESDIR}/examples
.endif

.include <bsd.port.mk>
