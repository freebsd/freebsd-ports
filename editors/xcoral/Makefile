# Created by: erich@rrnet.com
# $FreeBSD$

PORTNAME=	xcoral
PORTVERSION=	3.47
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	http://xcoral.free.fr/

PATCH_SITES=	http://aldan.algebra.com/~mi/port-stuff/
PATCHFILES=	xcoral-alpheus-and-peneus-2019.patch.bz2

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Multiwindow mouse-based text editor for X

LICENSE=	GPLv2

USES=		bison compiler:c11 xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/share
LIBS+=		-lgnuregex

PLIST_SUB=	VERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's| regex\.[co] | |g ; \
		 s| -g | |g' ${WRKSRC}/Makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xcoral ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/SmacLib/* ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
