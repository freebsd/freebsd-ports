# New ports collection makefile for: cbrowser
# Date created:		20 April 2000
# Whom:			jkoshy
#
# $FreeBSD$
#

PORTNAME=	cbrowser
PORTVERSION=	0.8
PORTREVISION=	4
CATEGORIES=	devel tk
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Graphical front end for cscope and cscope clones

RUN_DEPENDS=	cscope:${PORTSDIR}/devel/cscope

USE_TK=		84+
USE_TK_RUN=	yes
NO_BUILD=	yes

post-patch:
	${REINPLACE_CMD} -i "" -e '3s|wish|${WISH}|' ${WRKSRC}/cbrowser

do-install:
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \*.tcl ${DATADIR})
	${INSTALL_DATA} ${WRKSRC}/tclIndex ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cbrowser ${DATADIR}
	${LN} -s ${DATADIR}/cbrowser ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
