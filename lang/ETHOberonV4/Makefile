# New ports collection makefile for:	ETHOberonV4
# Version required:	ETH Oberon V4-0.9 (for Linux)
# Date created:		12 July 1998
# Whom:			Jerry Hicks <jhicks@glenatl.glenayre.com>
#
# $Id: Makefile,v 1.1.1.1 1998/07/20 03:51:44 steve Exp $
#

DISTNAME=	ETHLinuxOberon
PKGNAME=	ETHOberonV4-0.9
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.inf.ethz.ch/pub/Oberon/OberonV4/Linux/latest/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jhicks@glenatl.glenayre.com

# XXX - how to fix the following?
RUN_DEPENDS=	/compat/linux/lib/libc.so.5.4.23:${PORTSDIR}/emulators/linux_lib

ONLY_FOR_ARCHS=	i386
NO_CDROM=	licensing
NO_PACKAGE=	no version number on distfile
WRKSRC=		${WRKDIR}/${UNTAR_DIR}
UNTAR_DIR=	usr/local/ETHOberon

do-build:
	@${RM} -fr ${WRKSRC}/.Fonts
	@${ECHO_MSG} "Do a \`make install' as root."

do-install:
	@(if [ ! -d ${PREFIX}/lib ] ; then \
		${MKDIR} ${PREFIX}/lib ; \
	fi)
	@(if [ -e ${PREFIX}/lib/ETHOberonV4 ] ; then \
		${ECHO_MSG} "error: ${PREFIX}/lib/ETHOberonV4 already exists" 1>&2 ; \
		exit 1 ; \
	fi)
	@${MV} ${WRKSRC} ${PREFIX}/lib/ETHOberonV4
	@${SCRIPTDIR}/MakeStartV4 ${PREFIX}
	@${ECHO_MSG} ""
	@${ECHO_MSG} " '${PREFIX}/bin/StartV4' will launch ETH Oberon V4
	@${ECHO_MSG} ""

.include <bsd.port.mk>
