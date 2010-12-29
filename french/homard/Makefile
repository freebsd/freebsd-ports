# New ports collection makefile for:	homard
# Date created:		08 July 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	homard
DISTVERSION=	9.8-1
CATEGORIES=	french cad linux

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

LHOMARDDIR?=	apps/${PORTNAME}
vaster=		STA${ASTER_VER:R}
ASTER_TOOLS=	${LOCALBASE}/aster/outils
HOMARDDIR=	${PREFIX}/${LHOMARDDIR}
AHPY=		aster_homard_py
HOMARDSCRIPT=	${PORTNAME}_base
# This name is requested to run aster's make test
HOMARDPG=	${PORTNAME:U}_V${PORTVERSION:R}.out
HOMARDWDIR=	${PORTNAME:U}

DOCS=		A_Lire.txt Readme.txt

PLIST_SUB=	HOMARDDIR=${LHOMARDDIR} AHPY=${LHOMARDDIR}/${AHPY}			\
		UNAMES=${OPSYS} HOMARDPG=${HOMARDPG} ASTER_TOOLS=${ASTER_TOOLS}

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
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/${HOMARDWDIR}/Linux/CAS_TESTS/* ${EXAMPLESDIR}
	${FIND} ${EXAMPLESDIR} -type d -empty -exec ${TOUCH} {}/.keepme \;
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include "${.CURDIR}/../../french/aster/bsd.aster.mk"
.include <bsd.port.mk>
