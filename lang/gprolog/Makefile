# New ports collection makefile for:   gprolog
# Date created:        30 June 2001
# Whom:                Douglas Anestad <yotta@dougdidit.com>
#
# $FreeBSD$
#

PORTNAME=	gprolog
PORTVERSION=	1.3.0
CATEGORIES=	lang
MASTER_SITES=	http://www.gprolog.org/

MAINTAINER=	vs@FreeBSD.org
COMMENT=	A free Prolog compiler

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:261
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-c-flags="${CFLAGS}" \
		--with-doc-dir="${DOCSDIR}" \
		--with-examples-dir="${EXAMPLESDIR}"

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
