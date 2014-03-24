# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mupen64plus
PORTVERSION?=	2.0
PORTREVISION?=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_LOCAL:S,$,acm/${PORTNAME}/,} \
		${MASTER_SITE_GOOGLE_CODE}:plugin \
		http://cdn.bitbucket.org/wahrhaft/${PORTNAME}${PKGNAMESUFFIX}/downloads/:plugin
PKGNAMESUFFIX?=	-core
DIST_SUBDIR=	${PORTNAME}

MAINTAINER?=	acm@FreeBSD.org
COMMENT?=	A fork of Mupen64 Nintendo 64 emulator

#PROJECTHOST=	bsdistfiles
USES=		gmake pkgconfig
USE_GL?=	yes
USE_SDL?=	yes
USE_LDCONFIG?=	yes
ONLY_FOR_ARCHS=	i386 amd64

OPTFLAGS=	#

MAKE_ENV+=	PTHREAD_LIBS="${PTHREAD_LIBS}" OPTFLAGS="${OPTFLAGS}"
OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}${PKGNAMESUFFIX}/options

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.include "${MASTERDIR}/Makefile.common"

.include <bsd.port.post.mk>
