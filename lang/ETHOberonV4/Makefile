# New ports collection makefile for:	ETHOberonV4
# Date created:		12 July 1998
# Whom:			Jerry Hicks <jhicks@glenatl.glenayre.com>
#
# $FreeBSD$
#

PORTNAME=	ETHOberonV4
PORTVERSION=	0.9
CATEGORIES=	lang linux
MASTER_SITES=	ftp://ftp.inf.ethz.ch/pub/Oberon/OberonV4/Linux/latest/
DISTNAME=	ETHLinuxOberon
EXTRACT_SUFX=	.tgz

MAINTAINER=	jhicks@glenatl.glenayre.com

BROKEN=		"Does not run"
NO_CDROM=	licensing
NO_PACKAGE=	no version number on distfile

ONLY_FOR_ARCHS=	i386

USE_LINUX=	yes
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
	@${ECHO_MSG} " '${PREFIX}/bin/StartV4' will launch ETH Oberon V4"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
