# New ports collection makefile for: StarOffice 5.2
# Date created:		22 August 2000
# Whom:                 Martin Blapp
# Translation:		Eric Masson
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	5.2
CATEGORIES=	french editors linux
MASTER_SITES=	ftp://ftp.unilim.fr/pub/unix/bureautique/ \
		ftp://ftp.math.u-bordeaux.fr/pub/StarOffice/Linux-Intel/ \
		ftp://sunsite.cnlab-switch.ch/mirror/staroffice/francais/ \
		ftp://ftp.be.embnet.org/pub/tools/StarOffice/Linux/ \
		ftp://ftp.medasys-digital-systems.fr/pub1/linux/staroffice/
DISTNAME=	so-5_2-ga-bin-linux-fr.bin
DISTFILES=	so-5_2-ga-bin-linux-fr.bin
.if defined(WITH_ADABAS)
DISTFILES+=	soa-5_2-ga-bin-linux-fr.bin so-5_2-ga-bin-linux-fr.bin
.endif
EXTRACT_ONLY=

MAINTAINER=	mb@imp.ch

FETCH_DEPENDS=	${LINUXBASE}/lib/libc.so.6:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Doit etre telecharge depuis le site web de Sun'
IS_INTERACTIVE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	staroffice52
WRKSRC=		${WRKDIR}/office52
TMPDIR=		${WRKDIR}/tmp
LD_PATH=	${TMPDIR}:${WRKSRC}:${LINUXBASE}/linux/lib:${LINUXBASE}/usr/lib

.include <bsd.port.pre.mk>

pre-fetch:
.if ${OSVERSION} < 410000
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION}
	@${ECHO}
	@${ECHO} Staroffice depend d\'une modification du script
	@${ECHO} /usr/src/sys/i386/linux/linux_sysvec.c Celui-ci
	@${ECHO} Doit etre au moins en revision 1.55.2.1.
	@${ECHO}
	@${ECHO} Veuillez mettre à jour vers FreeBSD 4.1 SVP
	@${ECHO}
	@${FALSE}
.endif
.if defined(WITH_CDROM)
.if !exists(${CD_MOUNTPT}/linux/office52/setup)
	@${ECHO}
	@${ECHO} Montez le CDrom de Staroffice 5.2 dans le repertoire
	@${ECHO} ${CD_MOUNTPT} et relancez l\'installation
	@${ECHO}
	@${FALSE}
.endif
.endif

.if defined(WITH_CDROM)
do-extract:
	@${MKDIR} ${WRKSRC}/office52
	@cd ${WRKSRC}/office52 && ${LN} -s ${CD_MOUNTPT}/linux/office52/* .
.else

do-extract:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Impossible d\'ouvrir le display X:
	@ ${ECHO} Verifiez la variable DISPLAY
	@ ${ECHO}
	@ ${FALSE}
.else
	@${MKDIR} ${WRKSRC}
	@${MKDIR} ${TMPDIR}
	@${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/${DISTNAME}
.if defined(WITH_ADABAS)
	@${CP} ${_DISTDIR}/soa-5_2-ga-bin-linux-fr.bin ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/soa-5_2-ga-bin-linux-fr.bin
.endif
	@cd ${WRKSRC}
	@SAL_IGNOREXERRORS=1 ${WRKSRC}/${DISTNAME} -extract ${WRKSRC}
	@cd ../../
.endif
.endif

post-configure:
	@${PERL} -pi.orig -e 's|DefaultDestPath = "office52";|DefaultDestPath = "${PREFIX}/office52";|' ${WRKSRC}/setup.ins

do-install:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Impossible d\'ouvrir le display X:
	@ ${ECHO} Verifiez la variable DISPLAY
	@ ${ECHO}
	@ ${FALSE}
.else
.if exists(${LINUXBASE}/${PREFIX})
	@${LN} -fs ${LINUXBASE}/${PREFIX}/office52 ${PREFIX}/office52
.endif
	@${CAT} ${PKGDIR}/MESSAGE
	@-SAL_IGNOREXERRORS=1 TEMP=${TMPDIR} LD_LIBRARY_PATH=${LD_PATH} ${LINUXBASE}/bin/sh -c '${WRKSRC}/setup /net'
	@if [ -f ${PREFIX}/office52/program/setup ]; then \
		${ECHO} ; \
		${ECHO} Ignorez le message d\'erreur. StarOffice5.2 a correctement ; \
		${ECHO} ete installe sur votre système. ; \
		${ECHO} ; \
	else \
		${ECHO} ; \
		${ECHO} Une erreur est survenue lors de l\'installation de StarOffice5.2. Envoyez un mail à mb@imp.ch ;\
		${ECHO} avec le debug et quelques informations sur votre environnement FreeBSD SVP. Merci. ; \
		${ECHO} ; \
		${FALSE} ; \
	fi
.endif

post-install:
	@${PATCH} -s ${PREFIX}/office52/program/setup ${FILESDIR}/setup.patch
	@${PATCH} -s ${PREFIX}/office52/program/soffice ${FILESDIR}/soffice.patch

install-user:
	${PREFIX}/office52/program/setup

.include <bsd.port.post.mk>
