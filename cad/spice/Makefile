# Created by: Julian Jenkins <kaveman@magna.com.au>
# $FreeBSD$

PORTNAME=	spice
PORTVERSION=	3f5.2
PORTREVISION=	9
CATEGORIES=	cad
MASTER_SITES=	http://embedded.eecs.berkeley.edu/pubs/downloads/spice/:sources
PKGNAMESUFFIX=	${NOX11SUFX}
DISTFILES=	spice3f5${EXTRACT_SUFX}:sources	cp.ps toc.ps doc.ps
DIST_SUBDIR=	spice
EXTRACT_ONLY=	spice3f5${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General-purpose circuit simulation program

LICENSE=	SPICE
LICENSE_NAME=	BSD Copyright
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME}3f5
MAKEFILE=	${FILESDIR}/Makefile
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS X11
OPTIONS_DEFAULT=DOCS X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11 xaw xext xmu xt
NOX11SUFX=
.else
NOX11SUFX=	-nox11
MAKE_ARGS+=	-DWITHOUT_X11
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/ucb|${LOCALBASE}/bin|' \
		${WRKSRC}/util/build

do-configure:
	@${CP} ${FILESDIR}/FreeBSD ${WRKSRC}/conf/FreeBSD
	@${CP} ${FILESDIR}/FreeBSD.without_x11 \
		${WRKSRC}/conf/FreeBSD.without_x11
	@${REINPLACE_CMD} -e 's+@CC@+${CC}+ ; s+@CFLAGS@+${CFLAGS}+ ; \
	    s+@X11BASE@+${LOCALBASE}+;' \
	    ${WRKSRC}/conf/FreeBSD ${WRKSRC}/conf/FreeBSD.without_x11

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CAT} ${DISTDIR}/${DIST_SUBDIR}/*.ps > \
		${STAGEDIR}${DOCSDIR}/spice3f3.ps
	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/*.ps
.endif
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.cir ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
