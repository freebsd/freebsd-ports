# New ports collection makefile for:   linux-j
# Date created:        29 September 2001
# Whom:                js@jeannot.org
#
# $FreeBSD$
#

PORTNAME=	linux-j
PORTVERSION=	405a
CATEGORIES=	lang linux
MASTER_SITES=	http://www.jsoftware.com/download/
DISTFILES=	jconsole405a-Linux.tgz jlib405.tgz jhelp.tgz
DIST_SUBDIR=    ${PORTNAME}/${PORTVERSION}

MAINTAINER=	js@jeannot.org

RUN_DEPENDS=    /compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base

USE_LINUX_LIB=  yes

ONLY_FOR_ARCHS= i386

NO_WRKSUBDIR=	yes

MAN1=           jconsole.1

do-build:
	@sed "s:PREFIX:$(PREFIX):" < ${FILESDIR}/jconsole > ${WRKSRC}/jconsole

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/jconsole405a-Linux/jconsole_files/jconsole ${PREFIX}/bin/jconsole.bin
	@brandelf -t Linux ${PREFIX}/bin/jconsole.bin
	@${INSTALL_SCRIPT} ${WRKSRC}/jconsole ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/jconsole405a-Linux/jconsole_files/${MAN1} ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/lib/j
	@cd ${WRKSRC}/jlib405/jlib_files && tar -cf - * | tar -xf - -C ${PREFIX}/lib/j
	@${MKDIR} ${PREFIX}/lib/j/system/extras/help
	@cd ${WRKSRC}/jhelp/jhelp_files && tar -cf - * | tar -xf - -C ${PREFIX}/lib/j/system/extras/help

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
