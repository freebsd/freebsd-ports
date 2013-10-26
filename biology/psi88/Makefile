# Created by: Ryo MIYAMOTO
# $FreeBSD$

PORTNAME=	psi88
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	biology
MASTER_SITES=	http://www.ccl.net/cca/software/SOURCES/FORTRAN/psi88/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plotting wavefunctions (molecular orbitals) in 3D

PLIST_FILES+=	bin/PSI1 bin/PSICON bin/PSI2CT bin/PSI2HP bin/PSI2PS bin/PSI2 \
		bin/PREPLOT bin/preplot bin/rpsi1 bin/rpsi2 bin/rpsicon
PORTDOCS=	README psi88.doc
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes
.include <bsd.port.pre.mk>

USE_FORTRAN=	yes

pre-patch:
	${MV} ${WRKSRC}/src/makefile ${WRKSRC}/src/Makefile

post-patch:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g' -e 's+%%FFLAGS%%+${FFLAGS}+g' -e 's+%%LOCALBASE%%+${LOCALBASE}+g' -e 's+%%PREFIX%%+${PREFIX}+g' ${WRKSRC}/src/Makefile

pre-build:
	${CP} ${FILESDIR}/Makefile.top ${WRKSRC}/Makefile

post-install:
	${LN} -s ${PREFIX}/bin/PSI2PS ${PREFIX}/bin/PSI2
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/unix/preplot ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/unix/rpsi1 ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/unix/rpsi2 ${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKDIR}/${DISTNAME}/unix/rpsicon ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/psi88.doc ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
