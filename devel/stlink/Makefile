PORTNAME=	stlink
PORTVERSION=	1.7.0
DISTVERSIONPREFIX=	v
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	lev@FreeBSD.org
COMMENT=	STM32 ST-Link JTAG variant tools

LICENSE=	BSD3CLAUSE

OPTIONS_DEFINE=		GTK3 DOCS
OPTIONS_SUB=		yes
GTK3_EXTRA_PATCHES_OFF=	${FILESDIR}/extra-pacth-turn-off-gtk
GTK3_USES=		gnome
GTK3_USE=		GNOME=gtk30

USE_GITHUB=	yes
GH_ACCOUNT=	stlink-org

USES=		cmake pkgconfig
USE_CSTD=	c99
USE_LDCONFIG=	yes

PORTDOCS=	README.md ${ALLDOCS}

ALLDOCS=	compiling.md dev/developer.txt devices_boards.md \
		flashloaders.md release.md tutorial.md \
		version_support.md
		
FLASHLOADERS=	cleanroom.md linker.ld Makefile stm32f0.s stm32f4.s \
		stm32f4lv.s stm32f7.s stm32f7lv.s stm32l4.s stm32lx.s \

.include <bsd.port.pre.mk>

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/dev
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README.md
.for DOC in ${ALLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${DOC} ${STAGEDIR}${DOCSDIR}/${DOC}
.endfor
	${MKDIR} ${STAGEDIR}${DATADIR}
.for F in ${FLASHLOADERS}
	${INSTALL_DATA} ${WRKSRC}/flashloaders/${F} ${STAGEDIR}${DATADIR}/${F}
.endfor

.include <bsd.port.post.mk>
