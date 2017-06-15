# Created by: Pietro Cerutti <gahr@gahr.ch>
# $FreeBSD$

PORTNAME=	separate
PORTVERSION=	0.5.8
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SFJP/separate-plus/47873
DISTNAME=	${PORTNAME}+-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CMYK plugin for The GIMP

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gccmakedep:devel/gccmakedep
LIB_DEPENDS=	liblcms.so.1:graphics/lcms \
		libgimp-2.0.so:graphics/gimp-app

USES=		gettext-tools gmake pkgconfig zip

BIN_TARGETS=	separate separate_import icc_colorspace
L10N_TARGETS=	cs es fr ja ko pl ru

.for plugin in ${BIN_TARGETS}
PLIST_FILES+=	libexec/gimp/2.2/plug-ins/${plugin}
.endfor
.for lang in ${L10N_TARGETS}
PLIST_FILES+=	share/locale/${lang}/LC_MESSAGES/gimp20-separate.mo
.endfor

PORTDOCS=	README*
PORTEXAMPLES=	qproof.scm qexport.scm

MAKE_ENV=	TARGETS="${BIN_TARGETS}" \
		PREFIX=${STAGEDIR}${PREFIX}

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} \
		'/^CC/s|=|?=|; s| make| ${MAKE_CMD}|; /^LIBS/s/$$/ -lm/;' \
		${WRKSRC}/Makefile ${WRKSRC}/po/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gimp/2.2/plug-ins
.for plugin in ${BIN_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/${plugin} ${STAGEDIR}${PREFIX}/libexec/gimp/2.2/plug-ins/
.endfor
.for lang in ${L10N_TARGETS}
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.gmo ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/gimp20-separate.mo
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/sample-scripts && \
		${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
