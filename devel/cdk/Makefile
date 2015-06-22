# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	cdk
DISTVERSION=	5.0-20120323
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://invisible-island.net/cdk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Curses Development Kit for speedy development of full screen programs

LICENSE=	BSD4CLAUSE

USES=		ncurses gmake tar:tgz
GNU_CONFIGURE=	yes
PORTDOCS=	COPYING EXPANDING INSTALL NOTES README TODO
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS+=--with-ncurses
ALL_TARGET=	default examples demos cli cdkshlib
INSTALL_TARGET=	install installCDKSHLibrary
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/doc/cdk|/share/doc/cdk| ; s|VERSION)|VERSION_MAJOR)|' \
		-e 's|gcc|${CC}|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|$$(INSTALL_DATA) cdk-config|$(INSTALL_SCRIPT) cdk-config|g' \
		${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}; \
		${FIND} cli demos examples | ${PAX} -rw ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
