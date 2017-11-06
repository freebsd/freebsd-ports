# Created by: Douglas Anestad <yotta@dougdidit.com>
# $FreeBSD$

PORTNAME=	gprolog
PORTVERSION=	1.4.4
PORTREVISION=	5
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
PORTDOCS=	*
PORTEXAMPLES=	*
CFLAGS+=	-O3 # gcc5/gcc6 + -O2 = pl2wam hangs
PLIST_SUB=	GPROLOG_VER=${PORTVERSION}
CONFIGURE_ARGS=	--with-c-flags="${CFLAGS}" \
		--with-doc-dir="${DOCSDIR}" \
		--with-examples-dir="${EXAMPLESDIR}"
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=		FD DOCS EXAMPLES
OPTIONS_DEFAULT=	FD
OPTIONS_SUB=		yes

FD_DESC=		Enable finite domain constraint solver
FD_CONFIGURE_OFF=	--disable-fd-solver

# Disable registers on i386. This fixes build with gcc6.
# See: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=852008
.include <bsd.port.pre.mk>
.if ${ARCH} == i386
CONFIGURE_ARGS+=		--disable-regs
.endif

post-configure:
	${REINPLACE_CMD} \
		-E 's|^(INSTALL_PROGRAM *= *install +-s +-m) 555|\1 755|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -E 's|^(INSTALL_DATA *= *install +-m) 444|\1 644|g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} 's|$$(LN_S) $$(INSTALL_DIR)/bin|$$(LN_S) ../${PORTNAME}-${PORTVERSION}/bin|g' \
		${WRKSRC}/Makefile

post-install-EXAMPLES-off:
	${RM} -r ${STAGEDIR}${EXAMPLESDIR}

post-install-DOCS-off:
	${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
