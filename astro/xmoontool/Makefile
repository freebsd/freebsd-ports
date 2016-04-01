# Created by: Frank W. Josellis <frank@dynamical-systems.org>
# $FreeBSD$

PORTNAME=	xmoontool
PORTVERSION=	3.0.3
PORTREVISION=	8
CATEGORIES=	astro
MASTER_SITES=	http://www.senax.net/xmoontool/

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	Version of John Walker's classical moontool for X11/Motif

OPTIONS_DEFINE=	DOCS LIBNOVA MONOCHROME
OPTIONS_DEFAULT=	LIBNOVA
LIBNOVA_DESC=	libnova support
MONOCHROME_DESC=	Use monochrome display

USES=		motif

PORTDOCS=	NOTES
PLIST_FILES=	bin/xmoontool man/man1/xmoontool.1.gz

LIBNOVA_MAKE_ENV_OFF=	WITHOUT_LIBNOVA=yes
LIBNOVA_LIB_DEPENDS=	libnova.so:astro/libnova
MONOCHROME_MAKE_ENV=	DEFINES=""

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmoontool ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmoontool.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
