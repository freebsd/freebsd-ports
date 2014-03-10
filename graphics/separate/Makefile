# Created by: Pietro Cerutti <gahr@gahr.ch>
# $FreeBSD$

PORTNAME=	separate
PORTVERSION=	0.5.8
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SFJP
MASTER_SITE_SUBDIR=	separate-plus/47873
DISTNAME=	${PORTNAME}+-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	CMYK plugin for The GIMP

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS EXAMPLES

BUILD_DEPENDS=	gccmakedep:${PORTSDIR}/devel/gccmakedep
LIB_DEPENDS=	liblcms.so.1:${PORTSDIR}/graphics/lcms \
		libgimp-2.0.so:${PORTSDIR}/graphics/gimp-app

USES=		gmake pkgconfig zip

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

MAKE_ENV+=	TARGETS="${BIN_TARGETS}" \
		PREFIX=${STAGEDIR}${PREFIX}

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^CC/s|=|?=|; s| make| ${MAKE_CMD}|;' \
	    ${WRKSRC}/Makefile ${WRKSRC}/po/Makefile

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gimp/2.2/plug-ins
.for plugin in ${BIN_TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/${plugin} ${STAGEDIR}${PREFIX}/libexec/gimp/2.2/plug-ins/
.endfor
.for lang in ${L10N_TARGETS}
	${INSTALL_DATA} ${WRKSRC}/po/${lang}.gmo ${STAGEDIR}${PREFIX}/share/locale/${lang}/LC_MESSAGES/gimp20-separate.mo
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/sample-scripts && \
	    ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif
	@${CAT} pkg-message

.include <bsd.port.mk>
