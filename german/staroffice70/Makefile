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

.include <bsd.port.pre.mk>

#
# Staroffice depends on a scripting fix for
# src/sys/i386/linux/linux_sysvec. It should
# be revision 1.55.2.1 or higher. Please upgrade
# to FreeBSD 4.1
#
.if ${OSVERSION} < 410000
BROKEN= YES
.endif

.if defined(WITH_CDROM)
IGNORE= "Please mount the Sun StarOffice 5.2 CDROM onto /cdrom and run make again."
.else	# FTP/web download
.if !exists(${_DISTDIR}/${DISTNAME})
IGNORE="Please manually download ${DISTNAME} from http://www.sun.com/staroffice. Put ${DISTNAME} into the directory ${_DISTDIR} and run make again. Or, if you have the Sun StarOffice 5.2 CDROM, please run 'make USE_CDROM=yes'"
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
	@${WRKSRC}/${DISTNAME} -extract ${WRKSRC}
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
	@-TEMP=${TMPDIR} /compat/linux/bin/sh -c '${WRKSRC}/setup /net'
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
