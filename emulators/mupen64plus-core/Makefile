# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mupen64plus
PORTVERSION?=	2.0
PORTREVISION?=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_LOCAL:S,$,acm/${PORTNAME}/,} \
		${MASTER_SITE_GOOGLE_CODE}:plugin \
		http://cdn.bitbucket.org/wahrhaft/${PORTNAME}${PKGNAMESUFFIX}/downloads/:plugin
PKGNAMESUFFIX?=	-core
DIST_SUBDIR=	${PORTNAME}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Fork of Mupen64 Nintendo 64 emulator

#PROJECTHOST=	bsdistfiles
USES=		gmake pkgconfig
USE_GL?=	yes
USE_SDL?=	yes
USE_LDCONFIG?=	yes
ONLY_FOR_ARCHS=	i386 amd64

OPTFLAGS=	#

MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}" OPTFLAGS="${OPTFLAGS}"
OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options

.include "${.CURDIR}/../mupen64plus-core/Makefile.common"
.include <bsd.port.mk>
