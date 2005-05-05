# New ports collection makefile for:    tgif-nls
# Date created:         3 May 1999
# Whom:                 one@netlab.is.tsukuba.ac.jp
#
# $FreeBSD$
#

PORTNAME=	tgif
PORTVERSION=	4.1.44
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.usc.edu/pub/tgif/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tgif
PKGNAMESUFFIX=	-nls
DISTNAME=	${PORTNAME}-QPL-${PORTVERSION}

MAINTAINER=	one@netlab.is.tsukuba.ac.jp
COMMENT=	A two-dimensional drawing tool with NLS message catalogs support

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm

USE_GETTEXT=	yes
USE_IMAKE=	yes
USE_REINPLACE=	yes
MAN1=		tgif.1

.if !defined(NOPORTDOCS)
DEMO_FILES=	an-sr-flip-flop.obj launch-demo-1.obj \
		fonts.obj launch-demo.obj keys.obj slide-demo.obj example.tex
READMES=	Copyright HISTORY LICENSE.QPL README
SPICE_FILES=	README BZ.mod DN.mod DN.sym MN.mod MN.sym MP.mod MP.sym \
		SN.mod SN.sym SP.mod SP.sym capacitor.sym connection.sym \
		demo.obj gauge.sym ground.sym in.sym out.sym port.sym \
		resistor.0tc.sym resistor.2tc.sym resistor.h.2tc.sym \
		resistor.h.sym resistor.sym
.endif

post-extract:
		${RM} -f ${WRKDIR}/${DISTNAME}/Tgif.tmpl
		${CP} ${WRKDIR}/${DISTNAME}/Tgif.tmpl-freebsd \
		      ${WRKDIR}/${DISTNAME}/Tgif.tmpl

post-patch:
		${REINPLACE_CMD} -e 's|.TH tgif n|.TH tgif 1L|' \
			${WRKSRC}/tgif.man
		${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|; \
			s|/usr/share/lib|${PREFIX}/share/locale|' \
			${WRKSRC}/tgif.Xdefaults

post-install:
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}; ${MKDIR} ${EXAMPLESDIR}
		(cd ${WRKSRC} ;\
		  ${INSTALL_DATA} ${DEMO_FILES} ${EXAMPLESDIR} ;\
		  ${INSTALL_DATA} ${READMES} ${DOCSDIR} \
		)
		${MKDIR} ${EXAMPLESDIR}/spice
		(cd ${WRKSRC}/spice ;\
		  ${INSTALL_DATA} ${SPICE_FILES} ${EXAMPLESDIR}/spice \
		)
.endif
		${LN} -fs tgif ${PREFIX}/bin/tgif-nls

.include <bsd.port.mk>
