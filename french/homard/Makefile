# New ports collection makefile for:	homard
# Date created:		08 July 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	homard
DISTVERSION=	8.7-1
DISTVERSIONSUFFIX=	.${ARCH}
CATEGORIES=	french cad linux python
MASTER_SITES=	http://www.code-aster.org/FICHIERS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A refinement and de-refinement mesh tool

BUILD_DEPENDS=	${LOCALBASE}/aster/${vaster}/asteru:${PORTSDIR}/french/aster
RUN_DEPENDS=	${LOCALBASE}/aster/${vaster}/asteru:${PORTSDIR}/french/aster

RESTRICTED=	The free downloading of HOMARD software is only allowed for coupling\
		with Code_Aster. For any other use, a license agreement is requested.\
		Please contact HOMARD project: <homard@edf.fr>.

ONLY_FOR_ARCHS=	i386

USE_LINUX=	yes
USE_PYTHON=	yes
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

LHOMARDDIR?=	apps/${PORTNAME}
ASTER_VER=	9.1
vaster=		STA${ASTER_VER}
ASTER_TOOLS=	${LOCALBASE}/aster/${vaster}/outils
HOMARDDIR=	${PREFIX}/${LHOMARDDIR}
AHPY=		aster_homard_py
AHPY5=		aster_homard_v5x_py
AHPY6=		aster_homard_v6x_py
HOMARDSCRIPT=	${PORTNAME}_base
# This name is requested to run aster's make test
HOMARDPG=	${PORTNAME:U}_V${PORTVERSION:R}.out
HOMARDWDIR=	${PORTNAME:U}

DIR2RM=		sfr_mix_2d_zzzz121d_d1 qua_2d_24x36_d2 mix_qua_tri_d1_equ		\
		med_3d_tet_tri_d2_man med_3d_cube_d2 med_2d_carre_d1 med_2d_6xtri_d2	\
		sfr_2d_rugby_d2 hex_d2

DOCS=		A_Lire.txt Readme.txt

PLIST_SUB=	HOMARDDIR=${LHOMARDDIR} AHPY=${LHOMARDDIR}/${AHPY}			\
		AHPY5=${LHOMARDDIR}/${AHPY5} AHPY6=${LHOMARDDIR}/${AHPY6}		\
		UNAMES=${OPSYS} HOMARDPG=${HOMARDPG} ASTER_TOOLS=${ASTER_TOOLS}

pre-configure:
	@${REINPLACE_CMD} -e "s#/logiciels/HOMARD/HOMARD_PUBLIC#${PREFIX}/bin#"		\
		${WRKSRC}/${HOMARDWDIR}/${HOMARDSCRIPT}

do-install:
	@${MKDIR} ${HOMARDDIR}
	@${MKDIR} ${PREFIX}/bin/${OPSYS}
	@${INSTALL_PROGRAM} ${WRKSRC}/${HOMARDWDIR}/${HOMARDPG} ${PREFIX}/bin/${OPSYS}
	@${BRANDELF} -t Linux ${PREFIX}/bin/${OPSYS}/${HOMARDPG}
	@${INSTALL_SCRIPT} ${WRKSRC}/${HOMARDWDIR}/${HOMARDSCRIPT} ${HOMARDDIR}/${PORTNAME}
	@${CP} -R ${WRKSRC}/${HOMARDWDIR}/ASTER_HOMARD/${AHPY} ${HOMARDDIR}
	@${CP} -R ${WRKSRC}/${HOMARDWDIR}/ASTER_HOMARD/${AHPY5} ${HOMARDDIR}
	@${CP} -R ${WRKSRC}/${HOMARDWDIR}/ASTER_HOMARD/${AHPY6} ${HOMARDDIR}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${HOMARDDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${HOMARDDIR}
	@${LN} -fs ${HOMARDDIR}/homard ${ASTER_TOOLS}/
	@${LN} -fs ${HOMARDDIR}/aster_homard_py ${ASTER_TOOLS}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
	@${CP} -R ${WRKSRC}/${HOMARDWDIR}/Intranet ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${CP} -R ${WRKSRC}/${HOMARDWDIR}/CAS_TESTS/* ${EXAMPLESDIR}
	@${TOUCH} ${DIR2RM:S|^|${EXAMPLESDIR}/|:S|$|/resultats/.keepme|}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
