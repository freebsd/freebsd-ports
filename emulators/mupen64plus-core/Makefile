# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mupen64plus
PORTVERSION?=	2.0
PORTREVISION?=	4
CATEGORIES=	emulators
MASTER_SITES=	GOOGLE_CODE \
		LOCAL/acm/${PORTNAME} \
		GOOGLE_CODE:plugin \
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

MAKE_ENV+=	OPTFLAGS="${OPTFLAGS}"
OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options

.include "${.CURDIR}/../mupen64plus-core/Makefile.common"
.include <bsd.port.mk>
