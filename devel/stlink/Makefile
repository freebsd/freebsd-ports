# $FreeBSD$

PORTNAME=	stlink
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	lev@FreeBSD.org
COMMENT=	STM32 ST-Link JTAG variant tools

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=		GTK3
OPTIONS_SUB=		yes
GTK3_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-pacth-turn-off-gtk
GTK3_USE=		GNOME=gtk30

USE_GITHUB=	yes
GH_ACCOUNT=	texane

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

PORTDOCS=	README.md tested-boards.md tutorial.md

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" || ${ARCH} == "powerpc" || ${ARCH} == "arm" || ${ARCH} == "armv6" || ${ARCH} == "mips"
EXTRA_PATCHES+=	${FILESDIR}/extra-pacth-32bit
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README.md
	${INSTALL_DATA} ${WRKSRC}/doc/tested-boards.md ${STAGEDIR}${DOCSDIR}/tested-boards.md
	${INSTALL_DATA} ${WRKSRC}/doc/tutorial.md ${STAGEDIR}${DOCSDIR}/tutorial.md

.include <bsd.port.post.mk>
