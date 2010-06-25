# New ports collection makefile for:   gprolog
# Date created:        30 June 2001
# Whom:                Douglas Anestad <yotta@dougdidit.com>
#
# $FreeBSD$
#

PORTNAME=	gprolog
PORTVERSION=	1.3.1
CATEGORIES=	lang
MASTER_SITES=	http://www.gprolog.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free Prolog compiler

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262
CONFIGURE_ARGS=	--with-c-flags="${CFLAGS}" \
		--with-doc-dir="${DOCSDIR}" \
		--with-examples-dir="${EXAMPLESDIR}"
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-freebsd${OSREL}

PLIST_SUB+=	GPROLOG_VER=${PORTVERSION}

PORTDOCS=	*

.include <bsd.port.pre.mk>

.if defined(WITHOUT_FD)
CONFIGURE_ARGS+=--disable-fd-solver
PLIST_SUB+=	FD="@comment "
PKGNAMESUFFIX=	-nofd
.else
PLIST_SUB+=	FD=""
.endif

.include <bsd.port.post.mk>
