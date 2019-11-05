# Created by: bmc@WillsCreek.COM
# $FreeBSD$

PORTNAME=	tgif
PORTVERSION=	4.2.5
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.usc.edu/pub/tgif/ \
		http://groups.yahoo.com/group/tgif4-announce/files/ \
		SF
DISTNAME=	${PORTNAME}-QPL-${PORTVERSION}

MAINTAINER=	bmc@clapper.org
COMMENT=	Xlib-based two-dimensional drawing tool and hyper-object browser

LICENSE=	QPLv1
LICENSE_NAME=	Q PUBLIC LICENSE v1.0
LICENSE_FILE=	${WRKSRC}/LICENSE.QPL
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	giftopnm:graphics/netpbm

OPTIONS_DEFINE=	NLS A4SIZE DOCS
A4SIZE_DESC=	Set default paper size to A4

USES=		imake xorg
PORTDOCS=	HISTORY README
USE_XORG=	x11 xext xt sm ice

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
IMAKEDEFINES+=	WITH_NLS
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif
.if ${PORT_OPTIONS:MA4SIZE}
IMAKEDEFINES+=	WITH_A4SIZE
.endif

EXAMPLES.demo=	an-sr-flip-flop.obj launch-demo-1.obj \
		fonts.obj launch-demo.obj keys.obj slide-demo.obj example.tex
EXAMPLES.spice=	README BZ.mod DN.mod DN.sym MN.mod MN.sym MP.mod MP.sym \
		SN.mod SN.sym SP.mod SP.sym capacitor.sym connection.sym \
		demo.obj gauge.sym ground.sym in.sym out.sym port.sym \
		resistor.0tc.sym resistor.2tc.sym resistor.h.2tc.sym \
		resistor.h.sym resistor.sym

pre-configure:
		cd ${WRKSRC} && ${INSTALL_DATA} Tgif.tmpl-freebsd Tgif.tmpl
		( for D in ${IMAKEDEFINES}; do \
			${ECHO_CMD} "#define $${D}"; \
		  done; \
		  ${CAT} ${FILESDIR}/Tgif.tmpl-freebsdports; \
		) > ${WRKSRC}/Tgif.tmpl-freebsdports
post-install:
.for D in demo spice
		${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/${D}
		cd ${WRKSRC}/${D:S/demo//} \
			&& ${INSTALL_DATA} ${EXAMPLES.${D}} ${STAGEDIR}${EXAMPLESDIR}/${D}
.endfor
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
