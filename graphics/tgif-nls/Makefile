# New ports collection makefile for:    tgif-nls
# Date created:         3 May 1999
# Whom:                 one@netlab.is.tsukuba.ac.jp
#
# $FreeBSD$
#

PORTNAME=	tgif
PORTVERSION=	4.1.40
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.cs.umd.edu/pub/tgif/ \
		ftp://ftp.cs.ucla.edu/pub/tgif/ \
		ftp://download.sourceforge.net/tgif/
PKGNAMESUFFIX=	-nls

MAINTAINER=	one@netlab.is.tsukuba.ac.jp

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
MAN1=		tgif.1

.if !defined(NOPORTDOCS)
TGIFDOC=	${PREFIX}/share/doc/tgif
TGIFDEMO=	${PREFIX}/share/examples/tgif
DEMO_FILES=	an-sr-flip-flop.obj launch-demo-1.obj \
		fonts.obj launch-demo.obj keys.obj slide-demo.obj example.tex
READMES=	Copyright HISTORY README
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

pre-install:
		(cd ${WRKSRC} ;\
		  ${MV} tgif.Xdefaults tgif.Xdefaults.org; \
		  ${SED} -e "s#/usr/local#${PREFIX}#" \
		         -e "s#/usr/share/lib#${PREFIX}/share/locale#" \
		         tgif.Xdefaults.org > tgif.Xdefaults \
		)

post-install:
.if !defined(NOPORTDOCS)
		${MKDIR} ${TGIFDOC}; ${MKDIR} ${TGIFDEMO}
		(cd ${WRKSRC} ;\
		  ${INSTALL_DATA} ${DEMO_FILES} ${TGIFDEMO} ;\
		  ${INSTALL_DATA} ${READMES} ${TGIFDOC} \
		)
		${MKDIR} ${TGIFDEMO}/spice
		(cd ${WRKSRC}/spice ;\
		  ${INSTALL_DATA} ${SPICE_FILES} ${TGIFDEMO}/spice \
		)
.endif
		${LN} -fs tgif ${PREFIX}/bin/tgif-nls

.include <bsd.port.mk>
