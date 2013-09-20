# Created by: Douglas Anestad <yotta@dougdidit.com>
# $FreeBSD$

PORTNAME=	gprolog
PORTVERSION=	1.4.1
CATEGORIES=	lang
# MASTER_SITES=	http://www.gprolog.org/
MASTER_SITES=	http://gprolog.univ-paris1.fr/old_versions/

MAINTAINER=	nsmoot@make.sh
COMMENT=	Free Prolog compiler

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_GMAKE=	yes
USE_GCC=	any
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--with-c-flags="${CFLAGS}"
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-freebsd${OSREL}

PLIST_SUB+=	GPROLOG_VER=${PORTVERSION}

OPTIONS_DEFINE=	FD
OPTIONS_DEFAULT=FD
FD_DESC=	Enable finite domain constraint solver

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
CONFIGURE_ARGS+=--with-doc-dir="${DOCSDIR}"
.else
CONFIGURE_ARGS+=--with-doc-dir="${WRKDIR}/docs"
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
PORTEXAMPLES=	*
CONFIGURE_ARGS+=--with-examples-dir="${EXAMPLESDIR}"
.else
CONFIGURE_ARGS+=--with-examples-dir="${WRKDIR}/examples"
.endif

.if empty(PORT_OPTIONS:MFD)
CONFIGURE_ARGS+=--disable-fd-solver
PLIST_SUB+=	FD="@comment "
PKGNAMESUFFIX=	-nofd
.else
PLIST_SUB+=	FD=""
.endif

.include <bsd.port.mk>
