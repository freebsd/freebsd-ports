# New ports collection makefile for:    Half Life Admin Mod
# Date created:				Sun Apr 29 15:58:33 EDT 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	admin
PORTVERSION=	2.50.51
PORTEPOCH=	1
MASTER_SITES=	http://www.adminmod.org/downloads/update/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	halflifeadmin
DISTFILES=	halflife-admin-2.50.50.tgz \
		halflifeadmin-update-2_50_51.tgz
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	${PORTNAME}

WRKSRC=		${WRKDIR}/Adminmod

slaveport-post-extract:
	@${CP} ${WRKSRC}/../metamod_i386.so \
		${WRKSRC}/dlls
	@${CP} ${WRKSRC}/../admin_MM_i386.so \
		${WRKSRC}/dlls
	@${PERL} -pi.orig -e \
		's|/usr/local/hlds_l|${PREFIX}${HLDSDIR:S/\/$//}|' \
		${WRKSRC}/install_admin

slaveport-post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/install_admin \
		${PREFIX}${HLDSDIR}/Adminmod

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
