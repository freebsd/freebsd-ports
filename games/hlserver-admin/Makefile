# New ports collection makefile for:    Half Life Admin Mod
# Date created:				Sun Apr 29 15:58:33 EDT 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	admin
PORTVERSION=	2.50.11
PORTEPOCH=	1
MASTER_SITES=	http://www.adminmod.org/downloads/ \
		http://www.adminmod.org/downloads/beta/ \
		http://www.metamod.org/dl/dlls/
DISTFILES=	halflife-admin-2.50.09.tgz \
		halflifeadmin-beta-${PORTVERSION:S/.//g}.tgz \
		metamod_i386.so
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTFILES:S/metamod_i386.so//}

WRKSRC=		${WRKDIR}/Admin

slaveport-post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/metamod_i386.so \
		${WRKSRC}/dlls
	@${CP} ${WRKDIR}/admin_MM_i386.so ${WRKSRC}/dlls
	@${PERL} -pi.orig -e 's|2.50.07|${PORTVERSION}|; \
		s|/usr/local/games/hlds_l|${PREFIX}${HLDSDIR:S/\/$//}|' \
		${WRKSRC}/install_admin

slaveport-post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/install_admin \
		${PREFIX}${HLDSDIR}/Admin

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
