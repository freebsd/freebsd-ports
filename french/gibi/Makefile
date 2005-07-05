# New ports collection makefile for:	gibi
# Date created:		06 September 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	gibi
PORTVERSION=	2000
PORTREVISION=	7
CATEGORIES=	french cad linux
MASTER_SITES=	http://www.code-aster.org/FICHIERS/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1.${ARCH}
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
RUN_DEPENDS+=	${LOCALBASE}/aster/${vaster}/asteru:${PORTSDIR}/french/aster \
		${SHELL_RUN_GIBI}:${PORTSDIR}/shells/${SHRGDEP}

RESTRICTED=	"Toute personne chargeant le logiciel GIBI s'engage à ne\
		l'utiliser qu'en couplage avec le logiciel Code_Aster. Pour\
		tout autre usage, un droit de licence est nécessaire."

ONLY_FOR_ARCHS=	i386

USE_REINPLACE=	yes
USE_LINUX=	yes
USE_X_PREFIX=	yes
REINPLACE_ARGS=	-i ""
NO_BUILD=	yes

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
.if ${SHRG} == "bash"
SHRGDEP=	bash2
.else
SHRGDEP=	${SHRG}
.endif
SHELL_RUN_GIBI=	${LOCALBASE}/bin/${SHRG}

LGIBIDIR?=	apps/${PORTNAME}
GIBIDIR=	${PREFIX}/${LGIBIDIR}
ASTER_VER=	8.1
vaster=		STA${ASTER_VER}
ASTER_TOOLS=	${LOCALBASE}/aster/${vaster}/outils
ARCHI=		PC_Linux_
ARCHIVER=	${ARCHI}${PORTVERSION}
GIBIBIN=	${PORTNAME}${PORTVERSION}

DOCS=		DOC/HTML DOC/index.html DOC/pdf DOC/postscript README

PLIST_SUB=	GIBIDIR=${LGIBIDIR} ASTER_TOOLS=${ASTER_TOOLS}

post-extract:
	@(cd ${WRKDIR} && \
		${TAR} xfz ${WRKDIR}/CASTEM_${PORTNAME}PC_Linux_${PORTVERSION}.tar.gz)

post-patch:
	@${REINPLACE_CMD} -e "s|DIR='repertoire_install'|DIR='${GIBIDIR}'|"	\
		-e "s|/bin/ksh|${SHELL_RUN_GIBI}|"				\
		-e "s|castem|${PORTNAME}|"					\
		${WRKDIR}/bin/${GIBIBIN}

do-install:
	@${MKDIR} ${GIBIDIR}/bin
.for FICH in DATA DGIBI
	@${CP} -Rp ${WRKDIR}/${FICH} ${GIBIDIR}
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/bin/${GIBIBIN}				\
		${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME}${ARCHIVER}			\
		${GIBIDIR}/bin
	@${BRANDELF} -t Linux ${GIBIDIR}/bin/${PORTNAME}${ARCHIVER}
	@${BRANDELF} -t Linux ${GIBIDIR}/DATA/kinstall_${ARCHIVER}
	@(cd ${GIBIDIR}/DATA							\
	&& ./kinstall_${ARCHIVER} < ${FILESDIR}/clef >/dev/null 2>&1		\
	&& ${CHMOD} 666 USRDAT)
	@${RM} ${GIBIDIR}/DATA/kinstall_${ARCHIVER}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${GIBIDIR}
	@${LN} -fs ${PREFIX}/bin/${GIBIBIN} ${ASTER_TOOLS}/${PORTNAME}
	@${LN} -fs ${PREFIX}/bin/${GIBIBIN} ${ASTER_TOOLS}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${CP} -Rp ${WRKDIR}/${FILE} ${DOCSDIR}
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
