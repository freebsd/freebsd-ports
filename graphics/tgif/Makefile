# New ports collection makefile for:    tgif
# Date created:         30 Jan 1999
# Whom:                 bmc@WillsCreek.COM
#
# $FreeBSD$
#

PORTNAME=	tgif
PORTVERSION=	4.1.37
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.cs.umd.edu/pub/tgif/ \
		ftp://ftp.cs.ucla.edu/pub/tgif/

MAINTAINER=	bmc@WillsCreek.COM

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
MAN1=		tgif.1
TGIFDOC=	${PREFIX}/share/doc/tgif
DEMO_FILES=	an-sr-flip-flop.obj launch-demo-1.obj \
		fonts.obj launch-demo.obj keys.obj slide-demo.obj example.tex
READMES=	Copyright HISTORY README

post-extract:
		${RM} -f ${WRKDIR}/${DISTNAME}/Tgif.tmpl
		${CP} ${WRKDIR}/${DISTNAME}/Tgif.tmpl-freebsd \
		      ${WRKDIR}/${DISTNAME}/Tgif.tmpl
post-install:
		${MKDIR} ${TGIFDOC}
		(cd ${WRKSRC} ;\
		  ${INSTALL_DATA} ${DEMO_FILES} ${TGIFDOC} ;\
		  ${INSTALL_DATA} ${READMES} ${TGIFDOC} ;\
		)

.include <bsd.port.mk>
