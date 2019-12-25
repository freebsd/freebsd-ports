# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	homard
DISTVERSION=	11.12-aster2
PORTREVISION=	1
CATEGORIES=	french cad linux

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Refinement and de-refinement mesh tool

ONLY_FOR_ARCHS=	amd64 i386

BUILD_DEPENDS=	${LOCALBASE}/aster/${VER}/bin/aster:french/aster
RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash		\
		${LOCALBASE}/aster/${VER}/bin/aster:french/aster

USES=		linux python:3.6+ shebangfix

RESTRICTED=	The free downloading of HOMARD software is only allowed for coupling\
		with Code_Aster. For any other use, a license agreement is requested.\
		Please contact HOMARD project: <homard@edf.fr>.
SHEBANG_FILES=	${WRKSRC}/ASTER_HOMARD/homard	\
		${WRKSRC}/homard_base ${WRKSRC}/setup_homard.py
REINPLACE_ARGS=	-i ""

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

LHOMARDDIR?=	apps/${PORTNAME}
VER=		${ASTER_VER:R}
ASTER_TOOLS=	${LOCALBASE}/aster/outils
HOMARDDIR=	${PREFIX}/${LHOMARDDIR}
AHPY=		aster_homard_py
HOMARDSCRIPT=	${PORTNAME}_base
# This name is requested to run aster's make test
#HOMARDPG=	${PORTNAME:tu}_V${PORTVERSION:R}.out
HOMARDPG=	${PORTNAME:tu}_V11.10.out

DOCS=		A_Lire.txt Readme.txt

PLIST_SUB=	HOMARDDIR=${LHOMARDDIR} AHPY=${LHOMARDDIR}/${AHPY}			\
		UNAMES=${OPSYS} HOMARDPG=${HOMARDPG} ASTER_TOOLS=${ASTER_TOOLS}

OPTIONS_DEFINE=	DOCS

pre-configure:
.for sc in ${HOMARDSCRIPT}
	${REINPLACE_CMD} -e "s|%%HOMARDDIR%%|${PREFIX}/apps/${OPSYS}|"	\
		${WRKSRC}/${sc}
.endfor

do-build:
	${BRANDELF} -t Linux ${WRKSRC}/Linux/${HOMARDPG}

do-install:
	${MKDIR} ${STAGEDIR}${HOMARDDIR} ${STAGEDIR}${PREFIX}/apps/${OPSYS}
	${INSTALL_PROGRAM} ${WRKSRC}/Linux/${HOMARDPG}	\
		${STAGEDIR}${PREFIX}/apps/${OPSYS}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}_base	\
		${STAGEDIR}${HOMARDDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/ASTER_HOMARD/${AHPY} ${STAGEDIR}${HOMARDDIR}
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py	\
		-d ${PREFIX} -f ${HOMARDDIR:S|${PREFIX}/||})
	(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py	\
		-d ${PREFIX} -f ${HOMARDDIR:S|${PREFIX}/||})
	${MKDIR} ${STAGEDIR}${ASTER_TOOLS}/
	${LN} -fs ${HOMARDDIR}/homard ${STAGEDIR}${ASTER_TOOLS}/
	${LN} -fs ${HOMARDDIR}/aster_homard_py ${STAGEDIR}${ASTER_TOOLS}/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
