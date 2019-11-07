# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	jspice3
DISTVERSION=	2.5-110615
CATEGORIES=	cad
MASTER_SITES=	http://www.wrcad.com/ftp/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adaptation of the Berkeley Spice3f4 with superconductivity

BROKEN_aarch64=	Fails to link jspice3

CONFLICTS=	spice-[0-9]*

OPTIONS_DEFINE=	X11 EXAMPLES
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=		yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

X11_USES=	xorg
X11_USE=	XORG=x11,xaw,xt

post-patch:
	@${REINPLACE_CMD} -e \
		'/^prefix/s|=.*|= ${PREFIX}| ; \
		 /^SPICE_HOST/s|=.*|= localhost| ; \
		 /^CC_OPT/s|=.*|= ${CFLAGS}|' \
		${WRKSRC}/conf/unixconf/mkheader.0
	@cd ${WRKSRC}/src && \
		${REINPLACE_CMD} 's,va_copy,var_copy,g' include/cpextern.h \
		lib/fte/options.c lib/cp/variable.c

post-patch-X11-off:
	@${REINPLACE_CMD} -e \
		'/$$makeprog depend/s|^|#|' \
		${WRKSRC}/build
	@${REINPLACE_CMD} -e \
		's|^LIBX|#LIBX| ; \
		 s|-DWANT_X11||' \
		${WRKSRC}/conf/unixconf/mkheader.0

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
