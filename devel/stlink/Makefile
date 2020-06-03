# $FreeBSD$

PORTNAME=	stlink
PORTVERSION=	1.6.1
#PORTREVISION=	0
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
GH_ACCOUNT=	texane
GH_TAGNAME=	v${PORTVERSION}

USES=		cmake pkgconfig
USE_LDCONFIG=	yes

PORTDOCS=	README.md ${ALLDOCS}

ALLDOCS=	compiling.md developer.txt devices_boards.md \
		flashloaders.md release.md tutorial.md \
		version_support.md

.include <bsd.port.pre.mk>

.if ! ${ARCH:M*64*}
EXTRA_PATCHES+=	${FILESDIR}/extra-pacth-32bit
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/README.md
.for DOC in ${ALLDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${DOC} ${STAGEDIR}${DOCSDIR}/${DOC}
.endfor

.include <bsd.port.post.mk>
