# New ports collection makefile for:	metis-edf
# Date created:		Thu Jun 26 2003
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	metis-edf
PORTVERSION=	3
CATEGORIES=	cad
MASTER_SITES=	http://www.code-aster.org/FICHIERS/metis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Meshes partionning tool used by Code_Aster

CONFLICTS=	metis-[0-9]*

ALL_TARGET=	default
MAKE_ENV+=	CC="${CC}" AR="${AR}" LD="${LD}" F77="${F77}"
USE_REINPLACE=	yes

F77?=		f77

do-install:
	@${CP} ${WRKSRC}/CONFIG/onmetis.in ${WRKSRC}/onmetis
	@${REINPLACE_CMD} -e "s#HOME_METIS#${PREFIX}/bin#" ${WRKSRC}/onmetis
	${INSTALL_SCRIPT} ${WRKSRC}/onmetis ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/onmetis.exe ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libmetis.a ${PREFIX}/lib

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Doc/manual.ps ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/Test/fort.81 ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Test file installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.mk>
