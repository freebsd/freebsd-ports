# New ports collection makefile for:	homard
# Date created:		08 July 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	homard
PORTVERSION=	6.2
PORTREVISION=	1
CATEGORIES=	french cad linux python
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.${ARCH}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A refinement and de-refinement mesh tool

BUILD_DEPENDS=	${LOCALBASE}/aster/${vaster}/asteru.exe:${PORTSDIR}/french/aster
RUN_DEPENDS=	${LOCALBASE}/aster/${vaster}/asteru.exe:${PORTSDIR}/french/aster

RESTRICTED=	"Toute personne chargeant le logiciel HOMARD s'engage à ne\
		l'utiliser qu'en couplage avec le logiciel Code_Aster. Pour\
		tout autre usage, un droit de licence est nécessaire.\
		Contacter les administrateurs de HOMARD à l'adresse :\
		<homard@edf.fr>."

ONLY_FOR_ARCHS=	i386

USE_LINUX=	yes
USE_PYTHON=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME:U}_V${PORTVERSION}.Linux

LHOMARDDIR?=	apps/${PORTNAME}
ASTER_VER=	7.2
vaster=		STA${ASTER_VER}
ASTER_TOOLS=	${LOCALBASE}/aster/${vaster}/outils
HOMARDDIR=	${PREFIX}/${LHOMARDDIR}
AHPY=		aster_homard_py
AHPY5=		aster_homard_V5x_py
HOMARDSCRIPT=	${WRKDIR}/${PORTNAME}_base
# This name is requested to run aster's make test
HOMARDPG=	${PORTNAME:U}_V${PORTVERSION}.out

DOCS=		A_Lire.txt Readme.txt

.include <bsd.port.pre.mk>

unames!=	${UNAME} -s
PLIST_SUB=	HOMARDDIR=${LHOMARDDIR} AHPY=${LHOMARDDIR}/${AHPY}			\
		AHPY5=${LHOMARDDIR}/${AHPY5} UNAMES=${unames} HOMARDPG=${HOMARDPG}	\
		ASTER_TOOLS=${ASTER_TOOLS}

BRANDELF?=	/usr/bin/brandelf

post-patch:
	@${REINPLACE_CMD} -e "s#/home/homard/ASTER_HOMARD#${ASTER_TOOLS}#"	\
		-e "s#/logiciels/HOMARD/HOMARD_PUBLIC#${PREFIX}/bin#"		\
		-e "s#/local/edf-python-2.1.1/bin/python#${PYTHON_CMD}#"	\
		${HOMARDSCRIPT}

do-install:
	@${MKDIR} ${HOMARDDIR}
	@${MKDIR} ${PREFIX}/bin/${unames}
	@${INSTALL_PROGRAM} ${WRKSRC}/${HOMARDPG} ${PREFIX}/bin/${unames}
	@${BRANDELF} -t Linux ${PREFIX}/bin/${unames}/${HOMARDPG}
	@${INSTALL_SCRIPT} ${HOMARDSCRIPT} ${HOMARDDIR}/${PORTNAME}
	@${CP} -R ${WRKSRC}/${AHPY} ${HOMARDDIR}
	@${CP} -R ${WRKSRC}/${AHPY5} ${HOMARDDIR}
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${HOMARDDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${HOMARDDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${HOMARDDIR}
	@${LN} -fs ${HOMARDDIR}/homard ${ASTER_TOOLS}/
	@${LN} -fs ${HOMARDDIR}/aster_homard_py ${ASTER_TOOLS}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKDIR}/${doc} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
