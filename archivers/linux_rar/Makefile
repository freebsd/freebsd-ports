# New ports collection makefile for:    linux_rar
# http://www.rarsoft.com/rar_archiver.htm
# Date created:		30 April 1999
# Whom:			FUJISHIMA Satsuki <k5@respo.or.jp>
#
# $FreeBSD$
#

PORTNAME=	linux_rar
PORTVERSION=	2.80
CATEGORIES=	archivers linux
MASTER_SITES=	ftp://ftp.download.com/pub/linux/utilities/ \
		ftp://ftp.rarsoft.com/rar/
#		ftp://ftp.netlab.sk/public/rarsoft/rar/ \
#		ftp://rarsoft.ti.sk/pub/rar/
DISTNAME=	rarlnx${PORTVERSION:S/0//S/.//}
EXTRACT_SUFX=	.sfx

MAINTAINER=	sf@FreeBSD.org

USE_LINUX=	yes

NO_BUILD=	yes
ONLY_FOR_ARCHS=	i386
NO_CDROM=	NOFEE: Can not charge for distribution
NO_PACKAGE=	Only unmodified original package can be distributed

EXTRACT_CMD=		# empty
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	# empty
STRIP=			# empty: do not strip linux binary during INSTALL_PROGRAM
WRKSRC=		${WRKDIR}/rar

RARDOCS=	license.txt rar.txt rar_faq.txt rar_site.txt readme.txt \
		register.frm register.txt rereg.txt technote.txt whatsnew.txt
RARFILES=	rarfiles.lst default.sfx dos.sfx

.if defined(WITH_UNRAR)
PLIST_SUB=	UNRAR=""
.else
PLIST_SUB=	UNRAR="@comment "
.endif

post-fetch:
	@${CHMOD} a+x ${DISTDIR}/${DISTFILES}

pre-configure:
	@${ECHO_MSG} "To install unrar bundled with this package,"
	@${ECHO_MSG} "set variable WITH_UNRAR=yes."

do-install:
	@${MKDIR} ${PREFIX}/share/doc/rar ${PREFIX}/share/rar
	@${INSTALL_PROGRAM} ${WRKSRC}/rar ${PREFIX}/bin
	brandelf -t Linux ${PREFIX}/bin/rar
.if defined(WITH_UNRAR)
	@${INSTALL_PROGRAM} ${WRKSRC}/unrar ${PREFIX}/bin
	brandelf -t Linux ${PREFIX}/bin/unrar
.endif
.for i in ${RARDOCS}
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/rar
.endfor
.for i in ${RARFILES}
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/rar
.endfor

post-install:
	@${ECHO_MSG} "This is 40 days trial version of commercial software."
	@${ECHO_MSG} "Read texts in ${PREFIX}/share/doc/rar before use."
.if defined(WITH_UNRAR)
	@${ECHO_MSG} "However, unrar can be used for free."
.endif

.include <bsd.port.mk>
