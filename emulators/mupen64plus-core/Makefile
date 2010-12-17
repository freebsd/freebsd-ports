# New ports collection makefile for:	mupen64plus-core
# Date created:		2008-05-16
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mupen64plus
PORTVERSION?=	1.99.4
PORTREVISION?=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX?=	-core
DIST_SUBDIR=	${PORTNAME}

MAINTAINER?=	acm@FreeBSD.org
COMMENT?=	A fork of Mupen64 Nintendo 64 emulator

USE_GL?=	yes
USE_SDL?=	yes
USE_GMAKE=	yes
USE_LDCONFIG?=	yes
ONLY_FOR_ARCHS=	i386 amd64

MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}"
OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options

.include <bsd.port.pre.mk>

.include "${MASTERDIR}/Makefile.common"

.include <bsd.port.post.mk>
