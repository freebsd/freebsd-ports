# New ports collection makefile for:	homard
# Date created:		08 July 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	homard
DISTVERSIONPREFIX=	full-src-
DISTVERSION=	9.5-1
DISTVERSIONSUFFIX=	.all
PORTREVISION=	3
CATEGORIES=	french cad linux
MASTER_SITES=	http://www.code-aster.org/V2/UPLOAD/DOC/Telechargement/
DISTNAME=	aster-${DISTVERSIONPREFIX}${ASTER_DISTVERSION}${ASTER_DISTVERSIONSUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A refinement and de-refinement mesh tool

BUILD_DEPENDS=	${LOCALBASE}/aster/${vaster}/asteru:${PORTSDIR}/french/aster
RUN_DEPENDS=	${LOCALBASE}/aster/${vaster}/asteru:${PORTSDIR}/french/aster

RESTRICTED=	The free downloading of HOMARD software is only allowed for coupling\
		with Code_Aster. For any other use, a license agreement is requested.\
		Please contact HOMARD project: <homard@edf.fr>.

ONLY_FOR_ARCHS=	i386 amd64

USE_LINUX=	yes
USE_PYTHON=	yes
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}
EXTRACT_WRKSRC=	${WRKDIR}/aster-${DISTVERSIONPREFIX}${ASTER_VER}/SRC

LHOMARDDIR?=	apps/${PORTNAME}
ASTER_VER=	10.0.3
ASTER_DISTVERSION=	${ASTER_VER}-2
ASTER_DISTVERSIONSUFFIX=	.noarch
vaster=		STA${ASTER_VER:R}
ASTER_TOOLS=	${LOCALBASE}/aster/${vaster}/outils
HOMARDDIR=	${PREFIX}/${LHOMARDDIR}
AHPY=		aster_homard_py
HOMARDSCRIPT=	${PORTNAME}_base
# This name is requested to run aster's make test
HOMARDPG=	${PORTNAME:U}_V${PORTVERSION:R}.out
HOMARDWDIR=	${PORTNAME:U}

DIR2RM=		hex_3x3_d1 hex_d2 med_2d_6xtri_d2 med_2d_carre_d1	\
		med_3d_cube_d2_fig med_3d_tet_tri_d2_man mix_3d_d2	\
		mix_qua_tri_d1_equ pen_d1 qua_2d_24x36_d2 sau_qua_tri_d1\
		sfr_2d_att_rugby_qua sfr_mix_2d_zzzz121d_d1

DOCS=		A_Lire.txt Readme.txt

PLIST_SUB=	HOMARDDIR=${LHOMARDDIR} AHPY=${LHOMARDDIR}/${AHPY}			\
		UNAMES=${OPSYS} HOMARDPG=${HOMARDPG} ASTER_TOOLS=${ASTER_TOOLS}

post-extract:
	(cd ${WRKDIR} &&	\
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${EXTRACT_WRKSRC}/${PORTNAME}-${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX} ${EXTRACT_AFTER_ARGS})

pre-configure:
	${REINPLACE_CMD} -e "s#/logiciels/HOMARD/HOMARD_PUBLIC#${PREFIX}/bin#"		\
		${WRKSRC}/${HOMARDWDIR}/${HOMARDSCRIPT}

do-install:
	${MKDIR} ${HOMARDDIR}
	${MKDIR} ${PREFIX}/bin/${OPSYS}
	${INSTALL_PROGRAM} ${WRKSRC}/${HOMARDWDIR}/Linux/${HOMARDPG} ${PREFIX}/bin/${OPSYS}
	${BRANDELF} -t Linux ${PREFIX}/bin/${OPSYS}/${HOMARDPG}
	${INSTALL_SCRIPT} ${WRKSRC}/${HOMARDWDIR}/${HOMARDSCRIPT} ${HOMARDDIR}/${PORTNAME}
	${CP} -R ${WRKSRC}/${HOMARDWDIR}/ASTER_HOMARD/${AHPY} ${HOMARDDIR}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${HOMARDDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${HOMARDDIR}
	${LN} -fs ${HOMARDDIR}/homard ${ASTER_TOOLS}/
	${LN} -fs ${HOMARDDIR}/aster_homard_py ${ASTER_TOOLS}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/HOMARD/${doc} ${DOCSDIR}
.endfor
	${CP} -R ${WRKSRC}/${HOMARDWDIR}/Intranet ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/${HOMARDWDIR}/Linux/CAS_TESTS/* ${EXAMPLESDIR}
	${TOUCH} ${DIR2RM:S|^|${EXAMPLESDIR}/|:S|$|/resultats/.keepme|}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
