# New ports collection makefile for:    Half Life Admin Mod
# Date created:				Sun Apr 29 15:58:33 EDT 2001
# Whom:					pat et al
#
# $FreeBSD$
#

PORTNAME=	admin
PORTVERSION=	2.50.60
PORTEPOCH=	1
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	halflifeadmin
DISTNAME=	halflife-admin-2.50.60-linux
DIST_SUBDIR=	${PORTNAME}

COMMENT=	Popular Half-Life mod server administration tool for Linux

WRKSRC=		${WRKDIR}/Adminmod

slaveport-post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/install_admin \
		${PREFIX}${HLDSDIR}/Adminmod

HALFLIFE_PORT_MASTER=	${.CURDIR}/../hlserver-flf

.include "${HALFLIFE_PORT_MASTER}/Makefile"
