# Created by: Pedro Giffuni
# $FreeBSD$

PORTNAME=	NASTRAN-95
PORTVERSION=	20160908
PORTREVISION=	2
CATEGORIES=	cad science

MAINTAINER=	pfg@FreeBSD.org
COMMENT=	NASA Structural Analysis System

LICENSE=	NOSA
LICENSE_NAME=	NASA OPEN SOURCE AGREEMENT VERSION 1.3
LICENSE_FILE=	${FILESDIR}/NASTRAN95-license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	twuerfl
GH_TAGNAME=	a73c57a

USES=		fortran gmake

ALL_TARGET=	# empty
INSTALL_TARGET=	install-strip

NASTHOME=	${PREFIX}/libexec/${PORTNAME}
PLIST_SUB=	NASTHOME=${NASTHOME}

OPTIONS_DEFINE=	DOCS EXAMPLES

pre-build:
	@${REINPLACE_CMD} -e 's+%%FC%%+${FC}+g ; s+%%FFLAGS%%+${FFLAGS}+g;' \
		${WRKSRC}/src/Makefile \
		${WRKSRC}/um/Makefile
# Version string limited to 7 characters
	@${REINPLACE_CMD} -e 's+LINUX  +FREEBSD+g;' \
		${WRKSRC}/src/btstrp.f

do-build:
	@(cd ${WRKSRC}/src; ${MAKE_CMD} ${ALL_TARGET})
	@(cd ${WRKSRC}/um; ${MAKE_CMD} ${ALL_TARGET})
	@(cd ${WRKSRC}/utility; ${FC} -o chkfil.exe ${FFLAGS} chkfil.f ${LDFLAGS})

do-install:
	@${REINPLACE_CMD} -e 's+%%NASTHOME%%+${NASTHOME}+g' \
		${WRKSRC}/bin/nastran
	${INSTALL_SCRIPT} ${WRKSRC}/bin/nastran ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${NASTHOME}/bin
	${INSTALL} ${WRKSRC}/src/nastran.exe ${STAGEDIR}${NASTHOME}/bin/nastrn.exe
	${INSTALL} ${WRKSRC}/utility/chkfil.exe ${STAGEDIR}${NASTHOME}/bin/
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "rf" ${STAGEDIR}${NASTHOME})
	@${MKDIR} ${STAGEDIR}${NASTHOME}/um/
	${INSTALL} ${WRKSRC}/um/nasthelp.exe ${STAGEDIR}${NASTHOME}/um/
	${INSTALL_DATA} ${WRKSRC}/um/*.TXT ${STAGEDIR}${NASTHOME}/um/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf	${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "demoout inp test" ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
