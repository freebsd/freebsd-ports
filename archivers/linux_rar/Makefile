# New ports collection makefile for:    linux_rar
# http://www.rarsoft.com/rar_archiver.htm
# Version required:	2.60
# Date created:		30 April 1999
# Whom:			FUJISHIMA Satsuki <k5@respo.or.jp>
#
# $FreeBSD$
#

DISTNAME=       rarlnx26
PKGNAME=        linux_rar-2.60
CATEGORIES=	archivers
MASTER_SITES=	ftp://rarsoft.ti.sk/pub/rar/ \
		ftp://ftp.cdrom.com/pub/cheats/dlh/rar/
EXTRACT_SUFX=   .sfx

MAINTAINER=     k5@cheerful.com

BUILD_DEPENDS=	/compat/linux/lib/ld-linux.so.2:${PORTSDIR}/emulators/linux_base
RUN_DEPENDS=	/compat/linux/lib/ld-linux.so.2:${PORTSDIR}/emulators/linux_base

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
NO_CDROM=	NOFEE: Can not charge for distribution
NO_PACKAGE=     Only unmodified original package can be distributed

EXTRACT_CMD=		# empty
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty
STRIP=			# empty: do not touch linux binary!
WRKSRC=		${WRKDIR}/rar
PLIST=		${WRKSRC}/PLIST

RARDOCS=	license.txt rar_faq.txt rar_site.txt readme.txt register.frm \
		register.txt rereg.txt technote.txt whatsnew.txt
RARFILES=	rarfiles.lst default.sfx dos.sfx

post-fetch:
	@${CHMOD} a+x ${DISTDIR}/${DISTFILES}

pre-configure:
	@${ECHO_MSG} "To install unrar bundled with this package,"
	@${ECHO_MSG} "set variable WITH_UNRAR=YES."

do-install:
	@${MKDIR} ${PREFIX}/share/doc/rar ${PREFIX}/share/rar
	@${INSTALL_PROGRAM} ${WRKSRC}/rar ${PREFIX}/bin
.for i in ${RARDOCS}
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/rar
.endfor
.for i in ${RARFILES}
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/rar
.endfor
	@${INSTALL_MAN} ${WRKSRC}/rar.txt ${PREFIX}/man/cat1/rar.1

	@${CP} ${PKGDIR}/PLIST ${WRKSRC}
.if !defined(NOMANCOMPRESS)
	@${GZIP_CMD} ${PREFIX}/man/cat1/rar.1
	@${ECHO} man/cat1/rar.1.gz >> ${WRKSRC}/PLIST
.else
	@${ECHO} man/cat1/rar.1 >> ${WRKSRC}/PLIST
.endif
.if defined(WITH_UNRAR)
	@${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin
	@${ECHO} bin/unrar >> ${WRKSRC}/PLIST
.endif

post-install:
	@/usr/bin/brandelf -t Linux ${PREFIX}/bin/rar
	@${ECHO_MSG} "This is 40 days trial version of commercial software."
	@${ECHO_MSG} "Read texts in ${PREFIX}/share/doc/rar before use."
.if defined(WITH_UNRAR)
	@/usr/bin/brandelf -t Linux ${PREFIX}/bin/unrar
	@${ECHO_MSG} "However, unrar can be used for free."
.endif

.include <bsd.port.mk>
