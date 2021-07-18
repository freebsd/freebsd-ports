# Created by: Andreas Klemm <andreas@klemm.gtn.com>

PORTNAME=	SpecTcl
PORTVERSION=	1.2.2a
CATEGORIES=	devel tk
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Free drag-and-drop GUI builder for Tk and Java from Sun

LICENSE=	SUN
LICENSE_NAME=	SUN
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	auto-accept

USES=		tk

NO_BUILD=	yes

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
