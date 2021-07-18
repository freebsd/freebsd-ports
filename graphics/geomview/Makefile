# Created by: fenner

PORTNAME=	geomview
PORTVERSION=	1.9.5
PORTREVISION=	4
CATEGORIES=	graphics education
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive viewer for 3- and 4-D geometric objects

LICENSE=	LGPL21+ # COPYING mentions LGPL21, source files LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		gl libtool makeinfo motif tar:bzip2
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-htmlbrowser=xdg-open --with-pdfviewer=xdg-open \
		--with-motif=${LOCALBASE} --with-opengl=${LOCALBASE}
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

INFO=		geomview

OPTIONS_DEFINE=		DOCS EXAMPLES MOTION_AVG
MOTION_AVG_DESC=	Experimental motion averaging code
MOTION_AVG_CONFIGURE_ENABLE=	motion-averaging

post-patch:
	@${REINPLACE_CMD} -e \
		'/^install-data-am:/s|install-info-am|| ; \
		 /install-man/s|install-nobase_infoimgDATA||' \
		${WRKSRC}/doc/Makefile.in

post-build:
	@(cd ${WRKSRC}/doc && makeinfo --no-split --no-validate \
		-o geomview.info geomview.texi)

post-install:
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} geomview.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH})

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README \
		${STAGEDIR}${DOCSDIR})

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} *.c *.tcl \
		${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
