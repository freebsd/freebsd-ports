# Created by: Douglas Anestad <yotta@dougdidit.com>
# $FreeBSD$

PORTNAME=	gprolog
PORTVERSION=	1.4.4
PORTREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	http://www.gprolog.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Prolog compiler

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386 amd64

USES=		gmake
USE_GCC=	any
CFLAGS+=	-O3 # gcc5/gcc6 + -O2 = pl2wam hangs
PLIST_SUB=	GPROLOG_VER=${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-c-flags="${CFLAGS}" \
		--with-doc-dir="${DOCSDIR}" \
		--with-examples-dir="${EXAMPLESDIR}"
CONFIGURE_TARGET=	${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
MAKE_JOBS_UNSAFE=	yes
WRKSRC_SUBDIR=	src

OPTIONS_DEFINE=		FD DOCS EXAMPLES
OPTIONS_DEFAULT=	FD
OPTIONS_SUB=		yes

FD_DESC=		Enable finite domain constraint solver
FD_CONFIGURE_OFF=	--disable-fd-solver

.include <bsd.port.options.mk>

# Disable registers on i386. This fixes build with gcc6.
# See: https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=852008
.if ${ARCH} == i386
CONFIGURE_ARGS+=		--disable-regs
.endif

post-patch:
	@${REINPLACE_CMD} \
		'/LINKS_DIR/s|$$(INSTALL_DIR)|../${PORTNAME}-${PORTVERSION}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
