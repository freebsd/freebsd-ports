# ex:ts=8
# New ports collection makefile for:	aleph
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aleph
PORTVERSION=	0.7.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.aleph-lang.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION:S,.,-,g}
DISTNAME=	${PORTNAME}-src-${PORTVERSION:S,.,-,g}

MAINTAINER=	ijliao@FreeBSD.org

USE_NEWGCC=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CXX}" LD="${CXX}" LK="${CXX}" OPTCCFLAGS="${CXXFLAGS}" \
		DYNCCFLAGS="-fPIC -DPIC" DEBUGFLAGS="" DBGDEFINES="" \
		STDDEFINES="${PTHREAD_CFLAGS}" EXELDFLAGS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

PLIST_SUB=	PORTVER=${PORTVERSION:R}

MAN1=	aleph.1

do-configure:
	@(cd ${WRKSRC}; ./cnf/bin/aleph-setup -o)

post-install:
	@strip ${PREFIX}/bin/aleph

.include <bsd.port.mk>
