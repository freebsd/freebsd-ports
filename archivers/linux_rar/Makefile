# New ports collection makefile for:    linux_rar
# http://www.rarsoft.com/rar_archiver.htm
# Version required:	2.50
# Date created:
# Whom:			FUJISHIMA Satsuki <k5@respo.or.jp>
#
# $Id: Makefile,v 1.1.1.1 1999/04/30 04:41:20 taoka Exp $
#

DISTNAME=       rarlnx25
PKGNAME=        linux-rar-2.50
CATEGORIES=	archivers
MASTER_SITES=	ftp://rarsoft.ti.sk/pub/rar/ \
		ftp://ftp.cdrom.com/pub/cheats/dlh/rar/
EXTRACT_SUFX=   .sfx

MAINTAINER=     k5@respo.or.jp

ONLY_FOR_ARCHS=	i386
NO_PACKAGE=     Only unmodified original package can be distributed

NO_WRKSUBDIR=   yes
EXTRACT_CMD=		# empty
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty
STRIP=			# empty: do not touch linux binary!

post-fetch:
	@chmod a+x ${DISTDIR}/${DISTFILES}

do-build:
do-install:
	${INSTALL} -d -m 755 -o ${SHAREOWN} -g ${SHAREGRP} \
		${PREFIX}/share/doc/rar ${PREFIX}/share/rar
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} rar ${PREFIX}/bin && \
	${INSTALL_DATA} rarfiles.lst default.sfx dos.sfx ${PREFIX}/share/rar
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${PREFIX}/man/cat1/rar.1
	cd ${WRKSRC} && \
	${INSTALL_DATA} license.txt rar_faq.txt rar_site.txt readme.txt \
		register.txt technote.txt ${PREFIX}/share/doc/rar
.endif

.include <bsd.port.mk>
