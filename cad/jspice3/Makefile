# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	jspice3
PORTVERSION=	2.5.011109
PORTREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.wrcad.com/ftp/pub/
DISTNAME=	${PORTNAME}-2.5-011109

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adaptation of the Berkeley Spice3f4 with superconductivity

BROKEN=		unfetchable

CONFLICTS=	spice-[0-9]*

OPTIONS_DEFINE=	X11 EXAMPLES
OPTIONS_DEFAULT=	X11
WRKSRC=		${WRKDIR}/${PORTNAME}-2.5

X11_USE=	XORG=x11,xaw,xt

pre-configure:
	@${REINPLACE_CMD} -e 's+/usr/local+${PREFIX}+g;s+-O -g+${CFLAGS}+g;' \
		${WRKSRC}/conf/unixconf/mkheader.0

pre-configure-X11-on:
	@${REINPLACE_CMD} -e 's+#%%WITH_X%%++g' \
		${WRKSRC}/conf/unixconf/mkheader.0

pre-configure-X11-off:
	@${ECHO} "#undef HAVE_X11" >> ${WRKSRC}/src/include/spice.h

do-build:
	(cd ${WRKSRC};${SETENV} ${MAKE_ENV} ${SH} build)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/jspice3/helpdir \
		${STAGEDIR}${PREFIX}/lib/jspice3/sced \
		${STAGEDIR}${PREFIX}/lib/jspice3/scripts
	(cd ${WRKSRC}/src/bin && ${INSTALL_PROGRAM} jspice3 nutmeg help \
		multidec proc2mod spiced xeditor ${STAGEDIR}${PREFIX}/bin)
	${INSTALL_DATA} ${WRKSRC}/lib/mfbcap ${WRKSRC}/lib/news \
		${STAGEDIR}${PREFIX}/lib/jspice3
	${INSTALL_DATA} ${WRKSRC}/lib/helpdir/* \
		${STAGEDIR}${PREFIX}/lib/jspice3/helpdir
	${INSTALL_DATA} ${WRKSRC}//lib/sced/* \
		${STAGEDIR}${PREFIX}/lib/jspice3/sced
	${INSTALL_DATA} ${WRKSRC}/lib/scripts/* \
		${STAGEDIR}${PREFIX}/lib/jspice3/scripts
do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/examples/jspice3/cryocmos \
		${STAGEDIR}${PREFIX}/share/examples/jspice3/josephson
	${INSTALL_DATA} ${WRKSRC}/examples/*.* \
		${STAGEDIR}${PREFIX}/share/examples/jspice3
	${INSTALL_DATA} ${WRKSRC}/examples/cryocmos/* \
		${STAGEDIR}${PREFIX}/share/examples/jspice3/cryocmos
	${INSTALL_DATA} ${WRKSRC}/examples/josephson/* \
		${STAGEDIR}${PREFIX}/share/examples/jspice3/josephson

.include <bsd.port.mk>
