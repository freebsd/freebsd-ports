# Created by: bmc@WillsCreek.COM
# $FreeBSD$

PORTNAME=	tgif
PORTVERSION=	4.2.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.usc.edu/pub/tgif/ \
		http://groups.yahoo.com/group/tgif4-announce/files/ \
		SF
DISTNAME=	${PORTNAME}-QPL-${PORTVERSION}

MAINTAINER=	bmc@clapper.org
COMMENT=	An Xlib-based two-dimensional drawing tool and hyper-object browser

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm

OPTIONS_DEFINE=	NLS A4SIZE DOCS
A4SIZE_DESC=	Set default paper size to A4

USES=		imake
USE_GCC=	any
PORTDOCS=	HISTORY README
USE_XORG=	x11 xext xt sm ice
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"
CFLAGS+=	${PTHREAD_CFLAGS}

MAN1=		tgif.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
IMAKEDEFINES+=	WITH_NLS
PLIST_SUB=	NLS=""
.else
PLIST_SUB=	NLS="@comment "
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
		${MKDIR} ${EXAMPLESDIR}/${D}
		cd ${WRKSRC}/${D:S/demo//} \
			&& ${INSTALL_DATA} ${EXAMPLES.${D}} ${EXAMPLESDIR}/${D}
.endfor
.if ${PORT_OPTIONS:MDOCS}
		${MKDIR} ${DOCSDIR}
		cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
