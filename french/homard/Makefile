# New ports collection makefile for:	homard
# Date created:		08 July 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	homard
PORTVERSION=	7.1
PORTREVISION=	1
CATEGORIES=	french cad linux python
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.${ARCH}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A refinement and de-refinement mesh tool

BUILD_DEPENDS=	${LOCALBASE}/aster/${vaster}/asteru:${PORTSDIR}/french/aster
RUN_DEPENDS=	${LOCALBASE}/aster/${vaster}/asteru:${PORTSDIR}/french/aster

RESTRICTED=	"Toute personne chargeant le logiciel HOMARD s'engage à ne\
		l'utiliser qu'en couplage avec le logiciel Code_Aster. Pour\
		tout autre usage, un droit de licence est nécessaire.\
		Contacter les administrateurs de HOMARD à l'adresse :\
		<homard@edf.fr>."

ONLY_FOR_ARCHS=	i386

USE_LINUX?=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:U}

LHOMARDDIR?=	apps/${PORTNAME}
ASTER_VER=	7.4
vaster=		STA${ASTER_VER}
ASTER_TOOLS=	${LOCALBASE}/aster/outils
HOMARDDIR=	${PREFIX}/${LHOMARDDIR}
AHPY=		aster_homard_py
AHPY5=		aster_homard_V5x_py
AHPY6=		aster_homard_V6x_py
HOMARDSCRIPT=	${WRKSRC}/${PORTNAME}_base
# This name is requested to run aster's make test
HOMARDPG=	${PORTNAME:U}_V${PORTVERSION}.out
HOMARDWDIR=	${PORTNAME:U}_V${PORTVERSION}.Linux

DOCS=		A_Lire.txt Readme.txt

.include <bsd.port.pre.mk>

PLIST_SUB=	HOMARDDIR=${LHOMARDDIR} AHPY=${LHOMARDDIR}/${AHPY}			\
		AHPY5=${LHOMARDDIR}/${AHPY5} AHPY6=${LHOMARDDIR}/${AHPY6}		\
		UNAMES=${OPSYS} HOMARDPG=${HOMARDPG} ASTER_TOOLS=${ASTER_TOOLS}

pre-configure:
	@${REINPLACE_CMD} -e "s#/logiciels/HOMARD/HOMARD_PUBLIC#${PREFIX}/bin#"		\
		-e "s#/local/edf-python-2.1.1/bin/python#${PYTHON_CMD}#"		\
		${HOMARDSCRIPT}

do-install:
	@${MKDIR} ${HOMARDDIR}
	@${MKDIR} ${PREFIX}/bin/${OPSYS}
	@${INSTALL_PROGRAM} ${WRKSRC}/${HOMARDWDIR}/${HOMARDPG} ${PREFIX}/bin/${OPSYS}
	@${BRANDELF} -t Linux ${PREFIX}/bin/${OPSYS}/${HOMARDPG}
	@${INSTALL_SCRIPT} ${HOMARDSCRIPT} ${HOMARDDIR}/${PORTNAME}
	@${CP} -R ${WRKSRC}/${HOMARDWDIR}/${AHPY} ${HOMARDDIR}
	@${CP} -R ${WRKSRC}/${HOMARDWDIR}/${AHPY5} ${HOMARDDIR}
	@${CP} -R ${WRKSRC}/${HOMARDWDIR}/${AHPY6} ${HOMARDDIR}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${HOMARDDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${HOMARDDIR}
	@${LN} -fs ${HOMARDDIR}/homard ${ASTER_TOOLS}/
	@${LN} -fs ${HOMARDDIR}/aster_homard_py ${ASTER_TOOLS}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
