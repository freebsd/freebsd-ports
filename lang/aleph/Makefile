# ex:ts=8
# New ports collection makefile for:	aleph
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aleph
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.aleph-lang.org/ftp/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION:S,.,-,g}
DISTNAME=	${PORTNAME}-src-${PORTVERSION:S,.,-,g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A multi-threaded functional programming language

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CXX}" LD="${CXX}" LK="${CXX}" OPTCCFLAGS="${CXXFLAGS}" \
		DYNCCFLAGS="-fPIC -DPIC" DEBUGFLAGS="" DBGDEFINES="" \
		STDDEFINES="${PTHREAD_CFLAGS}" EXELDFLAGS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes

PLIST_SUB=	PORTVER=${PORTVERSION:R}

MAN1=	aleph.1 axc.1 axl.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
BROKEN=		"Does not compile on amd64 or ia64 (missing -fPIC)"
.endif

do-configure:
	@(cd ${WRKSRC}; ./cnf/bin/aleph-setup -o)

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/aleph

.include <bsd.port.post.mk>
