# New ports collection makefile for:    Half Life Admin Mod
# Date created:				Sun Apr 29 15:58:33 EDT 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	admin
PORTVERSION=	2.50.56a
PORTEPOCH=	1
MASTER_SITES=	http://www.adminmod.org/downloads/update/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	halflifeadmin
DISTNAME=	halflife-admin-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

COMMENT=	Popular Half-Life mod server administration tool for Linux

USE_PERL5_BUILD=yes
WRKSRC=		${WRKDIR}/Adminmod

slaveport-post-extract:
	@${PERL} -pi.orig -e \
		's|/usr/local/hlds_l|${PREFIX}${HLDSDIR:S/\/$//}|' \
		${WRKSRC}/install_admin

slaveport-post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/install_admin \
		${PREFIX}${HLDSDIR}/Adminmod

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
