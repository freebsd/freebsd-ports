# New ports collection makefile for:	homard
# Date created:		08 July 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	homard
PORTVERSION=	5.5
CATEGORIES=	french cad linux python
MASTER_SITES=	http://www.code-aster.org/FICHIERS/homard/
DISTNAME=	${PORTNAME}_linux_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A refinement and de-refinement mesh tool

RESTRICTED=	"Toute personne chargeant le logiciel HOMARD s'engage à ne\
		l'utiliser qu'en couplage avec le logiciel Code_ASTER. Pour\
		tout autre usage, un droit de licence est nécessaire.\
		Contacter les administrateurs de HOMARD à l'adresse :\
		<homard@edf.fr>."

WRKSRC=		${WRKDIR}/ASTER_HOMARD

ONLY_FOR_ARCHS=	i386

USE_LINUX=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes

LHOMARDDIR?=	apps/${PORTNAME}
ASTER_VER=	7.1
vaster=		STA${ASTER_VER}
ASTER_TOOLS=	${LOCALBASE}/aster/${vaster}/outils
HOMARDDIR=	${PREFIX}/${LHOMARDDIR}
unames!=	${UNAME} -s
AHPY=		aster_homard_py
# This name is requested to run aster's make test
HOMARDPG=	${PORTNAME:U}_V${PORTVERSION}.out
PLIST_SUB=	HOMARDDIR=${LHOMARDDIR} AHPY=${LHOMARDDIR}/${AHPY} UNAMES=${unames}	\
		HOMARDPG=${HOMARDPG}

BRANDELF?=	/usr/bin/brandelf

post-patch:
	@${REINPLACE_CMD} -e "s#HOMARD_REP_PRO=/??????/homard#HOMARD_REP_PRO=${ASTER_TOOLS}#"	\
		-e "s#HOMARD_REP_EXE=/??????/homard#HOMARD_REP_EXE=${PREFIX}/bin#"		\
		-e "s#/??????/python#${PYTHON_CMD}#"		\
		${WRKSRC}/${PORTNAME}
	@${CHMOD} u+w ${WRKSRC}/${AHPY}

do-install:
	${MKDIR} ${HOMARDDIR}
	${MKDIR} ${PREFIX}/bin/${unames}
	${INSTALL_PROGRAM} ${WRKDIR}/${HOMARDPG}	\
		${PREFIX}/bin/${unames}/${HOMARDPG}
	${BRANDELF} -t Linux ${PREFIX}/bin/${unames}/${HOMARDPG}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${HOMARDDIR}
	${CP} -R ${WRKSRC}/${AHPY} ${HOMARDDIR}
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${HOMARDDIR}
	${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${HOMARDDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${HOMARDDIR}

post-install:
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.mk>
