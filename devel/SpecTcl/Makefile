# New ports collection makefile for:	SpecTcl1.1
# Date created:		Fri Oct  3 18:50:53 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	SpecTcl
PORTVERSION=	1.2.2a
CATEGORIES=	devel tk
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free drag-and-drop GUI builder for Tk and Java from Sun

NO_BUILD=	yes

USE_TK_WRAPPER=	yes

post-patch:
.for file in specJava specTcl
	@${REINPLACE_CMD} -e \
		's|^DIR=.*|DIR=${DATADIR}/lib|g' ${WRKSRC}/bin/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/specJava ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/specTcl ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/changes ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/license.terms ${DATADIR}
	@${MKDIR} ${DATADIR}/demo
	@(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${DATADIR}/demo)
	@${MKDIR} ${DATADIR}/examples
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${DATADIR}/examples)
	@${MKDIR} ${DATADIR}/lib
	@(cd ${WRKSRC}/SpecTcl && ${COPYTREE_SHARE} . ${DATADIR}/lib)

.include <bsd.port.mk>
