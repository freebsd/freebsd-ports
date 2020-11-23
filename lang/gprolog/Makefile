# Created by: Douglas Anestad <yotta@dougdidit.com>
# $FreeBSD$

PORTNAME=	gprolog
PORTVERSION=	1.4.5
CATEGORIES=	lang
MASTER_SITES=	http://www.gprolog.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free Prolog compiler

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386

USES=		gmake
CFLAGS+=	-DUSE_LOCKS=1 -DUSE_RECURSIVE_LOCKS=1 -DUSE_SPIN_LOCKS=0 \
		-DMMAP_CLEARS=0 -DNO_MACHINE_REG_FOR_REG_BANK

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

post-patch:
	@${REINPLACE_CMD} \
		'/LINKS_DIR/s|$$(INSTALL_DIR)|../${PORTNAME}-${PORTVERSION}|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
