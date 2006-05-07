# New ports collection makefile for:    tgif
# Date created:         30 Jan 1999
# Whom:                 bmc@WillsCreek.COM
#
# $FreeBSD$
#

PORTNAME=	tgif
PORTVERSION=	4.1.44
CATEGORIES=	graphics
MASTER_SITES=	ftp://bourbon.usc.edu/pub/tgif/ \
		http://groups.yahoo.com/group/tgif4-announce/files/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=tgif
DISTNAME=	${PORTNAME}-QPL-${PORTVERSION}

MAINTAINER=	bmc@clapper.org
COMMENT=	An Xlib-based two-dimensional drawing tool and hyper-object browser

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
post-patch:
		@${REINPLACE_CMD} -e 's|.TH tgif n|.TH tgif 1L|' \
			${WRKSRC}/tgif.man
post-install:
		${MKDIR} ${TGIFDOC}
		(cd ${WRKSRC} ;\
		  ${INSTALL_DATA} ${DEMO_FILES} ${TGIFDOC} ;\
		  ${INSTALL_DATA} ${READMES} ${TGIFDOC} ;\
		)

.include <bsd.port.mk>
