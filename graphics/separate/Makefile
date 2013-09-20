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
COMMENT=	A CMYK plugin for The GIMP

BUILD_DEPENDS=	gccmakedep:${PORTSDIR}/devel/gccmakedep
LIB_DEPENDS=	liblcms.so.1:${PORTSDIR}/graphics/lcms \
		libgimp-2.0.so:${PORTSDIR}/graphics/gimp-app

USE_ZIP=	yes
USES=		gmake pkgconfig

BIN_TARGETS=	separate separate_import icc_colorspace
L10N_TARGETS=	cs es fr ja ko pl ru

.for PLUGIN in ${BIN_TARGETS}
PLIST_FILES+=	libexec/gimp/2.2/plug-ins/${PLUGIN}
.endfor
.for lang in ${L10N_TARGETS}
PLIST_FILES+=	share/locale/${lang}/LC_MESSAGES/gimp20-separate.mo
.endfor

PORTDOCS=	README*
PORTEXAMPLES=	qproof.scm qexport.scm

MAKE_ENV+=	TARGETS="${BIN_TARGETS}"

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/^CC/s|=|?=|; /^PREFIX/s|=|?=|; s| make| ${GMAKE}|; \
	    s|lib/gimp/2.0|libexec/gimp/2.2|' ${WRKSRC}/Makefile ${WRKSRC}/po/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/sample-scripts && \
	${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
	@${CAT} pkg-message

.include <bsd.port.mk>
