# New ports collection makefile for: StarOffice 5.2
# Date created:		22 August 2000
# Whom:                 Martin Blapp
#
# $FreeBSD$
#

PORTNAME=	staroffice
PORTVERSION=	5.2
CATEGORIES=	editors linux
DISTNAME=	so-5_2-ga-bin-linux-en.bin
DISTFILES=	soa-5_2-ga-bin-linux-en.bin so-5_2-ga-bin-linux-en.bin
EXTRACT_ONLY=

MAINTAINER=	mb@imp.ch

RUN_DEPENDS=	/compat/linux/usr/i486-linux-libc5/lib/libc.so.5:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386
NO_CDROM=	'Must be downloaded direct from Sun via www interface'
IS_INTERACTIVE=	yes
NO_BUILD=	yes
DIST_SUBDIR=	staroffice52
WRKSRC=		${WRKDIR}/office52
TMPDIR=		${WRKDIR}/tmp
ADEBAS=		soa-5_2-ga-bin-linux-en.bin

.include <bsd.port.pre.mk>

pre-fetch:
.if ${OSVERSION} < 410000
	@${ECHO}
	@${ECHO} OS-VERSION ${OSVERSION}
	@${ECHO}
	@${ECHO} Staroffice depends on a scripting fix for
	@${ECHO} src/sys/i386/linux/linux_sysvec. It should
	@${ECHO} be revision 1.55.2.1 or higher.
	@${ECHO}
	@${ECHO} Please upgrade to FreeBSD 4.1
	@${ECHO}
	@${FALSE}
.endif
.if defined(WITH_CDROM)
	@${ECHO}
	@${ECHO} Please mount the Sun StarOffice 5.2 CDROM
	@${ECHO} onto /cdrom and run make again.
	@${ECHO}
	@${FALSE}
.else
.if !exists(${_DISTDIR}/${DISTNAME})
	@${ECHO} Please manually download ${DISTFILES}
	@${ECHO} from http://www.sun.com/staroffice.
	@${ECHO}
	@${ECHO} ${ADEBAS} is the database part of Staroffice.
	@${ECHO}
	@${ECHO} Put ${DISTFILES} into the directory
	@${ECHO} ${_DISTDIR} and run make again.
	@${ECHO} Or, if you have the Sun StarOffice 5.2 CDROM,
	@${ECHO} please run 'make USE_CDROM=yes'
	@${ECHO}
	@${FALSE}
.endif
.endif

.if defined(WITH_CDROM)
do-extract:
	@${MKDIR} ${WRKSRC}/office52
	@cd ${WRKSRC}/office52 && ${LN} -s ${CD_MOUNTPT}/linux/office52/* .
.endif

do-extract:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Can\'t open display:
	@ ${ECHO} Please check your DISPLAY variable.
	@ ${ECHO}
	@ ${FALSE}
.else
	@${MKDIR} ${WRKSRC}
	@${MKDIR} ${TMPDIR}
	@${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}
	@${CP} ${_DISTDIR}/soa-5_2-ga-bin-linux-en.bin ${WRKSRC}
	@${CHMOD} 755 ${WRKSRC}/${DISTNAME}
	@${CHMOD} 755 ${WRKSRC}/soa-5_2-ga-bin-linux-en.bin
	@cd ${WRKSRC}
	@SAL_IGNOREXERRORS=1 ${WRKSRC}/${DISTNAME} -extract ${WRKSRC}
	@cd ../../
.endif

post-configure:
	@${PERL} -pi.orig -e 's|DefaultDestPath = "office52";|DefaultDestPath = "${PREFIX}/office52";|' ${WRKSRC}/setup.ins

do-install:
.if !defined(DISPLAY) || ${DISPLAY} == ""
	@ ${ECHO}
	@ ${ECHO} Can\'t open display:
	@ ${ECHO} Please check your DISPLAY variable.
	@ ${ECHO}
	@ ${FALSE}
.else
.if exists(/compat/linux/usr/local)
	@${LN} -fs /compat/linux/usr/local/office52 ${PREFIX}/office52
.endif
	@${CAT} ${PKGDIR}/MESSAGE
	@-SAL_IGNOREXERRORS=1 TEMP=${TMPDIR} /compat/linux/bin/sh -c '${WRKSRC}/setup /net'
	@ ${ECHO}
	@ ${ECHO} Ignore the error-message. StarOffice5.2 has been installed
	@ ${ECHO} successfully on your system.
	@ ${ECHO}
.endif

post-install:
	@${PATCH} -s ${PREFIX}/office52/program/setup ${FILESDIR}/setup.patch
	@${PATCH} -s ${PREFIX}/office52/program/soffice ${FILESDIR}/soffice.patch

install-user:
	${PREFIX}/office52/program/setup

.include <bsd.port.post.mk>
