# Created by: Douglas Anestad <yotta@dougdidit.com>
# $FreeBSD$

PORTNAME=	gprolog
PORTVERSION=	1.4.4
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.gprolog.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Prolog compiler

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386 amd64

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USES=		gmake
USE_GCC=	any
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS=	--with-c-flags="${CFLAGS}"
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-freebsd${OSREL}
MAKE_JOBS_UNSAFE=	yes

PLIST_SUB+=	GPROLOG_VER=${PORTVERSION}

OPTIONS_DEFINE=	FD DOCS EXAMPLES
OPTIONS_DEFAULT=FD
FD_DESC=	Enable finite domain constraint solver

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

post-configure:
	${REINPLACE_CMD} -E 's|^(INSTALL_PROGRAM *= *install +-s +-m) 555|\1 755|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -E 's|^(INSTALL_DATA *= *install +-m) 444|\1 644|g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} 's|$$(LN_S) $$(INSTALL_DIR)/bin|$$(LN_S) ../${PORTNAME}-${PORTVERSION}/bin|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
