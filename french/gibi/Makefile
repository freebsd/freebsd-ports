# New ports collection makefile for:	gibi
# Date created:		06 September 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	gibi
DISTVERSION=	2003-2
DISTVERSIONSUFFIX=	.i386
PORTREVISION=	11
CATEGORIES=	french cad linux
MASTER_SITES=	http://www.code-aster.org/V2/UPLOAD/DOC/Telechargement/
EXTRACT_SUFX=	.tar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GIBI est la partie mailleur et post de CASTEM

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITH_ZSH or WITH_BASH or WITH_KSH: select a shell among
#			zsh (default), bash or ksh.
#-----------------------------------------------------------------------

BUILD_DEPENDS+=	${LOCALBASE}/aster/${vaster}/asteru:${PORTSDIR}/french/aster
RUN_DEPENDS+=	${LOCALBASE}/aster/${vaster}/asteru:${PORTSDIR}/french/aster	\
		${SHELL_RUN_GIBI}:${PORTSDIR}/shells/${SHRGDEP}

RESTRICTED=	Toute personne chargeant le logiciel GIBI s'engage à ne\
		l'utiliser qu'en couplage avec le logiciel Code_Aster. Pour\
		tout autre usage, un droit de licence est nécessaire.

ONLY_FOR_ARCHS=	i386 amd64

USE_LINUX=	yes
USE_LINUX_APPS=	libg2c
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

.if defined(WITH_ZSH)
SHRG=		zsh
.elif defined(WITH_BASH)
SHRG=		bash
.elif defined(WITH_KSH)
SHRG=		ksh93
.elif exists(${LOCALBASE}/bin/zsh)
SHRG=		zsh
.elif exists(${LOCALBASE}/bin/bash)
SHRG=		bash
.elif exists(${LOCALBASE}/bin/ksh93)
SHRG=		ksh93
.else
SHRG=		zsh
.endif
SHRGDEP=	${SHRG}
SHELL_RUN_GIBI=	${LOCALBASE}/bin/${SHRG}

LGIBIDIR?=	apps/${PORTNAME}
GIBIDIR=	${PREFIX}/${LGIBIDIR}
ASTER_VER=	10.0
vaster=		STA${ASTER_VER}
ASTER_TOOLS=	${LOCALBASE}/aster/${vaster}/outils
KERVER=		2.4.1
ARCHIVER=	PCLinuxK${KERVER:R}_${PORTVERSION:R}
KINSTALL=	kinstall_PC_Linux_${PORTVERSION:R}
GIBIBIN=	${PORTNAME}${PORTVERSION:R}

INST_ENV=	LD_ASSUME_KERNEL=${KERVER} CASTEM="${GIBIDIR}"			\
		ESOPE_PARAM='ESOPE=30000000,NTRK=50000,LTRK=1048576'		\
		MIF_PATH=${GIBIDIR}/header CASTEM_ERREUR=${GIBIDIR}/GIBI.ERREUR	\
		CASTEM_NOTICE=${GIBIDIR}/GIBI.MASTER CPU=16 ESOPE_TEMP='/tmp'	\
		CASTEM_PROC=${GIBIDIR}/GIBI.PROC

PLIST_SUB=	GIBIDIR=${LGIBIDIR} ASTER_TOOLS=${ASTER_TOOLS}		\
		GIBIVER=${PORTVERSION:R} KERVER=${KERVER:R}

pre-configure:
	${REINPLACE_CMD} -e "s|/usr/local/apps/gibi|${GIBIDIR}|"	\
		-e "s|/bin/bash|${SHELL_RUN_GIBI}|"			\
		${WRKSRC}/${GIBIBIN}
	${REINPLACE_CMD} -e "s|?PYTHON_EXE?|/usr/bin/env python|"	\
		-e "s|?HOME_GIBI?|${GIBIDIR}|"				\
		${WRKSRC}/gibi_aster.py

do-install:
	${MKDIR} ${GIBIDIR}
.for FICH in GIBI.ERREUR GIBI.MASTER GIBI.PROC USRDAT header
	${CP} -Rp ${WRKSRC}/${FICH} ${GIBIDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKSRC}/${GIBIBIN} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}${ARCHIVER} ${GIBIDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/${KINSTALL} ${GIBIDIR}
	${BRANDELF} -t Linux ${GIBIDIR}/${PORTNAME}${ARCHIVER}
	${BRANDELF} -t Linux ${GIBIDIR}/${KINSTALL}
	(cd ${GIBIDIR}						\
	&& ${INST_ENV} ./${KINSTALL} < ${FILESDIR}/clef \
	&& ${CHMOD} 666 USRDAT)
	${RM} ${GIBIDIR}/${KINSTALL}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${GIBIDIR}
	${LN} -fs ${PREFIX}/bin/${GIBIBIN} ${ASTER_TOOLS}/${PORTNAME}
	${LN} -fs ${PREFIX}/bin/${GIBIBIN} ${ASTER_TOOLS}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 800079
IGNORE=		the port can't be used with the default linux base port (linux_base-f10)
.endif

.include <bsd.port.post.mk>
