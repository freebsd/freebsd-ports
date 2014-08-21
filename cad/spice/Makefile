# Created by: Julian Jenkins <kaveman@magna.com.au>
# $FreeBSD$

PORTNAME=	spice
PORTVERSION=	3f5.2
PORTREVISION=	10
CATEGORIES=	cad
MASTER_SITES=	http://embedded.eecs.berkeley.edu/pubs/downloads/spice/:srcs \
		LOCAL/hrs/${PORTNAME}:docs
PKGNAMESUFFIX=	${NOX11SUFX}
DISTFILES=	spice3f5${EXTRACT_SUFX}:srcs cp.ps:docs toc.ps:docs doc.ps:docs
DIST_SUBDIR=	spice
EXTRACT_ONLY=	spice3f5${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	General-purpose circuit simulation program

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

WRKSRC=		${WRKDIR}/${PORTNAME}3f5
MAKEFILE=	${FILESDIR}/Makefile
MAKE_JOBS_UNSAFE=	yes

PORTDOCS=	spice3f3.ps.gz
PORTEXAMPLES=	bjtnoise.cir bsim1tst.cir bsim2tst.cir diffpair.cir \
		diodisto.cir ltra_1.cir ltra_2.cir ltra_3.cir \
		mixdisto.cir mos6inv.cir mosamp2.cir mosmem.cir process.mod \
		process.pro pz2.cir pzt.cir rc.cir rca3040.cir resnoise.cir \
		rtlinv.cir schmitt.cir simplepz.cir

OPTIONS_DEFINE=	DOCS EXAMPLES X11
OPTIONS_DEFAULT=DOCS EXAMPLES X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11 xaw xext xmu xt
NOX11SUFX=
CONFIGFILE=	${FILESDIR}/FreeBSD
.else
NOX11SUFX=	-nox11
CONFIGFILE=	${FILESDIR}/FreeBSD.without_x11
.endif

do-configure:
	(${CAT} ${CONFIGFILE};			\
	 ${ECHO_CMD} "CC=	${CC}";		\
	 ${ECHO_CMD} "MAKE=	${MAKE}";	\
	 ${ECHO_CMD} "CC_OPT+=	${CFLAGS}";	\
	 ${ECHO_CMD} "LOCALBASE=${LOCALBASE}";	\
	) > ${WRKSRC}/conf/FreeBSD

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/*.ps | ${GZIP_CMD} > \
	    ${STAGEDIR}${DOCSDIR}/${PORTDOCS}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && \
	    ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
