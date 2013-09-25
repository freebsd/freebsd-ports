# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	SpecTcl
PORTVERSION=	1.2.2a
CATEGORIES=	devel tk
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free drag-and-drop GUI builder for Tk and Java from Sun

NO_BUILD=	yes

USES+=		tk:85

post-patch:
.for file in specJava specTcl
	@${REINPLACE_CMD} -e \
		's|^DIR=.*|DIR=${DATADIR}/lib|g; s|wish|${WISH}|g' ${WRKSRC}/bin/${file}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/specJava ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/specTcl ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/changes ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/license.terms ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/demo
	@(cd ${WRKSRC}/demo && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/demo)
	@${MKDIR} ${STAGEDIR}${DATADIR}/examples
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/examples)
	@${MKDIR} ${STAGEDIR}${DATADIR}/lib
	@(cd ${WRKSRC}/SpecTcl && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/lib)

.include <bsd.port.mk>
