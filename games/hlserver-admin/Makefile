# New ports collection makefile for:    Half Life Admin Mod
# Date created:				Sun Apr 29 15:58:33 EDT 2001
# Whom:					pat@databits.net et al
#
# $FreeBSD$
#

PORTNAME=	admin
PORTVERSION=	2.50.07
PORTEPOCH=	1
MASTER_SITES=	http://www.adminmod.org/downloads/ \
		http://metamod.org/files/other/
DISTFILES=	halflife-${PORTNAME}-${PORTVERSION}.tgz \
		metamod_i386.so
DIST_SUBDIR=	${PORTNAME}

EXTRACT_ONLY=	halflife-${PORTNAME}-${PORTVERSION}.tgz
WRKSRC=		${WRKDIR}/Admin

post-patch:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/metamod_i386.so \
		${WRKSRC}/dlls

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
