# New ports collection makefile for:    linux_rar
# http://www.rarsoft.com/rar_archiver.htm
# Version required:	2.50
# Date created:		30 April 1999
# Whom:			FUJISHIMA Satsuki <k5@respo.or.jp>
#
# $FreeBSD$
#

DISTNAME=       rarlnx25
PKGNAME=        linux-rar-2.50
CATEGORIES=	archivers
MASTER_SITES=	ftp://rarsoft.ti.sk/pub/rar/ \
		ftp://ftp.cdrom.com/pub/cheats/dlh/rar/
EXTRACT_SUFX=   .sfx

MAINTAINER=     k5@respo.or.jp

RUN_DEPENDS=	/compat/linux/lib/ld-linux.so.2:${PORTSDIR}/emulators/linux_base

CAT1=		rar.1

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
NO_PACKAGE=     Only unmodified original package can be distributed

NO_WRKSUBDIR=   yes
EXTRACT_CMD=		# empty
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty
STRIP=			# empty: do not touch linux binary!

post-fetch:
	@${CHMOD} a+x ${DISTDIR}/${DISTFILES}

do-install:
	${MKDIR} ${PREFIX}/share/doc/rar ${PREFIX}/share/rar
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${PREFIX}/bin
	cd ${WRKSRC} && \
	${INSTALL_DATA} rarfiles.lst default.sfx dos.sfx ${PREFIX}/share/rar
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${PREFIX}/man/cat1/rar.1
	cd ${WRKSRC} && \
	${INSTALL_DATA} license.txt rar_faq.txt rar_site.txt readme.txt \
		register.txt technote.txt ${PREFIX}/share/doc/rar
.endif

.include <bsd.port.mk>
