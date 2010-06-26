# New ports collection makefile for:   gprolog
# Date created:        30 June 2001
# Whom:                Douglas Anestad <yotta@dougdidit.com>
#
# $FreeBSD$
#

PORTNAME=	gprolog
PORTVERSION=	1.3.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.gprolog.org/

MAINTAINER=	n.smoot@gmail.com
COMMENT=	A free Prolog compiler

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262
CONFIGURE_ARGS=	--with-c-flags="${CFLAGS}"
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-freebsd${OSREL}

PLIST_SUB+=	GPROLOG_VER=${PORTVERSION}

.include <bsd.port.pre.mk>

.if !defined(NOPORTDOCS)
PORTDOCS=	*
CONFIGURE_ARGS+=--with-doc-dir="${DOCSDIR}"
.else
CONFIGURE_ARGS+=--with-doc-dir="${WRKDIR}/docs"
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
CONFIGURE_ARGS+=--with-examples-dir="${EXAMPLESDIR}"
.else
CONFIGURE_ARGS+=--with-examples-dir="${WRKDIR}/examples"
.endif

.if defined(WITHOUT_FD)
CONFIGURE_ARGS+=--disable-fd-solver
PLIST_SUB+=	FD="@comment "
PKGNAMESUFFIX=	-nofd
.else
PLIST_SUB+=	FD=""
.endif

.include <bsd.port.post.mk>
