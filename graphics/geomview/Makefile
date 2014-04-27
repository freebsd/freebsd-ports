# Created by: fenner
# $FreeBSD$

PORTNAME=	geomview
PORTVERSION=	1.9.4
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive viewer for 3- and 4-D geometric objects

USES=		motif tar:bzip2
USE_GL=		glu
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-motif=${LOCALBASE} --with-opengl=${LOCALBASE}
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

INFO=		geomview

# Set "CPU" type for Geomview make
# Allow user to specify "make install MAPLE_LIB=foo" as geomview wants
MAKE_ENV=	CPU=FreeBSD MAPLE_LIB=${MAPLE_LIB}
INSTALL_TARGET=	install-strip

NOT_FOR_ARCHS=   amd64
NOT_FOR_ARCHS_REASON=  Segfaults on amd64
 
OPTIONS_DEFINE=  MOTION_AVG DOCS EXAMPLES
 
MOTION_AVG_DESC=    Experimental motion averaging code
MOTION_AVG_CONFIGURE_ENABLE= motion-averaging

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|doc||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} '/^install-data-am:/s|install-docDATA||g' \
		${WRKSRC}/src/bin/geomutil/math2oogl/Makefile.in \
		${WRKSRC}/src/bin/geomutil/maple2oogl/Makefile.in

post-build:
	cd ${WRKSRC}/doc && /usr/bin/makeinfo --no-split --no-validate \
		-o geomview.info geomview.texi

post-install:
	cd ${WRKSRC}/doc && ${INSTALL_MAN} *.3gv ${STAGEDIR}${MAN3PREFIX}/man/man3
	cd ${WRKSRC}/doc && ${INSTALL_MAN} *.5gv ${STAGEDIR}${MAN5PREFIX}/man/man5
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html/figs
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} OOGL.m.txt README README.gvplot \
		geomview.pdf geomview-pt_BR.pdf oogltour oogltour-pt_BR \
		${STAGEDIR}${DOCSDIR})
	cd ${WRKSRC}/doc/geomview.html \
		&& ${INSTALL_DATA} *.html ${STAGEDIR}${DOCSDIR}/html
	cd ${WRKSRC}/doc/figs \
		&& ${INSTALL_DATA} *.png ${STAGEDIR}${DOCSDIR}/html/figs
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html/pt_BR
	cd ${WRKSRC}/doc/geomview-pt_BR.html \
		&& ${INSTALL_DATA} *.html ${STAGEDIR}${DOCSDIR}/html/pt_BR
	cd ${STAGEDIR}${DOCSDIR}/html/pt_BR && ${LN} -sf ../figs .
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.c *.tcl ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
