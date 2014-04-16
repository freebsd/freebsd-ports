# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smake
PORTVERSION=	1.2.3
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.berlios.de/pub/smake/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Portable make program with automake features

DEPRECATED=	Abandonware, broken with modern com
EXPIRATION_DATE=	2014-05-12

BROKEN=	Does not build with modern compilers

LICENSE=	CDDL GPLv2
LICENSE_COMB=	multi
LICENSE_FILE_CDDL=	${WRKSRC}/CDDL.Schily.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:C/.a.*//g}

USES=		gmake tar:bzip2
MAKE_ENV=	CCOM="${CC}"
MAKE_ARGS=	INS_BASE=${PREFIX} DEFMANBASE=. CC="${CC}" CCOM="${CC}"

RULEUSED=	"`${WRKSRC}/conf/oarch.sh`"
PLIST_SUB=	RULESUSED="${RULEUSED}"

#BROKEN_i386=	fails to find correct configuration file

.include <bsd.port.mk>
