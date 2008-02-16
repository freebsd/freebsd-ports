# New ports collection makefile for:	separate
# Date created:        30 January 2008
# Whom:                Pietro Cerutti <gahr@gahr.ch>
#
# $FreeBSD$
#

PORTNAME=	separate
PORTVERSION=	20070727
CATEGORIES=	graphics
MASTER_SITES=	http://www.gahr.ch/FreeBSD/distfiles/

MAINTAINER=	gahr@gahr.ch
COMMENT=	A CMYK plugin for The GIMP

BUILD_DEPENDS=	gccmakedep:${PORTSDIR}/devel/gccmakedep \
		gimp-2.4:${PORTSDIR}/graphics/gimp
LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms

WRKSRC=		${WRKDIR}/${PORTNAME}+

USE_ZIP=	yes

GIMP_PLUGINS_DIR=	libexec/gimp/2.2/plug-ins/
TARGETS=		separate separate_import icc_colorspace

.for PLUGIN in ${TARGETS}
PLIST_FILES+=	${GIMP_PLUGINS_DIR}/${PLUGIN}
.endfor

PORTDOCS=	README*
PORTEXAMPLES=	quickproof.scm quicksave.scm

MAKE_ENV+=	TARGETS="${TARGETS}"

do-install:
.for PLUGIN in ${TARGETS}
	${INSTALL_PROGRAM} ${WRKSRC}/${PLUGIN} ${PREFIX}/${GIMP_PLUGINS_DIR}/
.endfor

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README_ICC_COLORSPACE ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-scripts/for_GIMP2.3+/quickproof.scm ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample-scripts/for_GIMP2.3+/quicksave.scm ${EXAMPLESDIR}
.endif
	@${CAT} pkg-message

.include <bsd.port.mk>
