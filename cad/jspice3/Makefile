# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	jspice3
PORTVERSION=	2.5.011109
PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	http://www.wrcad.com/ftp/pub/	\
		ftp://ftp.srware.com/pub/
DISTNAME=	${PORTNAME}-2.5-011109

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An adaptation of the Berkeley Spice3f4 with superconductivity

CONFLICTS=	spice-[0-9]*

OPTIONS_DEFINE=	X11 EXAMPLES
OPTIONS_DEFAULT=	X11
WRKSRC=		${WRKDIR}/${PORTNAME}-2.5

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11 xaw xt
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's+/usr/local+${PREFIX}+g ;	\
	 s+-O -g+${CFLAGS}+g;' \
		${WRKSRC}/conf/unixconf/mkheader.0
.if ${PORT_OPTIONS:MX11}
	@${REINPLACE_CMD} -e 's+#%%WITH_X%%++g' 		\
		${WRKSRC}/conf/unixconf/mkheader.0
.else
	@${ECHO} "#undef HAVE_X11" >> ${WRKSRC}/src/include/spice.h
.endif

do-build:
	@(cd ${WRKSRC};${SETENV} ${MAKE_ENV} ${SH} build)

do-install:
	@(cd ${WRKSRC}/src/bin;${SETENV} ${MAKE_ENV} ${MAKE} install)

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MV} ${PREFIX}/lib/jspice3/examples ${EXAMPLESDIR}
.else
	${RM} -R ${PREFIX}/lib/jspice3/examples
.endif

.include <bsd.port.mk>
