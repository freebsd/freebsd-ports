# New ports collection makefile for:    tgif-nls
# Date created:         3 May 1999
# Whom:                 one@netlab.is.tsukuba.ac.jp
#
# $FreeBSD$
#

PORTNAME=	tgif
PORTVERSION=	4.1.34
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.cs.umd.edu/pub/tgif/ \
		ftp://ftp.cs.ucla.edu/pub/tgif/
PKGNAMESUFFIX=	-nls

MAINTAINER=	one@netlab.is.tsukuba.ac.jp

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm \
		pnmtopng:${PORTSDIR}/graphics/pnmtopng

USE_IMAKE=	yes
XMKMF=		LOCALBASE=${LOCALBASE} xmkmf -a
MAN1=		tgif.1
TGIFDOC=	${PREFIX}/share/doc/tgif
TGIFDEMO=	${PREFIX}/share/examples/tgif
DEMO_FILES=	an-sr-flip-flop.obj launch-demo-1.obj \
		fonts.obj launch-demo.obj keys.obj slide-demo.obj example.tex
READMES=	Copyright HISTORY README

post-extract:
		${RM} -f ${WRKDIR}/${DISTNAME}/Tgif.tmpl
		${CP} ${WRKDIR}/${DISTNAME}/Tgif.tmpl-freebsd \
		      ${WRKDIR}/${DISTNAME}/Tgif.tmpl

pre-install:
		(cd ${WRKSRC} ;\
		  ${MV} tgif.Xdefaults tgif.Xdefaults.org; \
		  ${SED} -e "s#/usr/local#${PREFIX}#" \
		         -e "s#/usr/share/lib#${PREFIX}/share/locale#" \
		         tgif.Xdefaults.org > tgif.Xdefaults ;\
		)

post-install:
		${MKDIR} ${TGIFDOC}; ${MKDIR} ${TGIFDEMO}
		(cd ${WRKSRC} ;\
		  ${INSTALL_DATA} ${DEMO_FILES} ${TGIFDEMO} ;\
		  ${INSTALL_DATA} ${READMES} ${TGIFDOC} ;\
		)
		${LN} -fs tgif ${PREFIX}/bin/tgif-nls

.include <bsd.port.mk>
