# New ports collection makefile for:	radare2
# Date created:				15 August 2011
# Whom:					Karsten Pedersen <kpedersen@opencde.org>
#
# $FreeBSD$
#

PORTNAME=	radare2
PORTVERSION=	0.8.1
CATEGORIES=	devel
MASTER_SITES=	http://radare.org/get/

MAINTAINER=	kpedersen@opencde.org
COMMENT=	Tools to disasm, debug, analyze, and manipulate binary files

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=--without-ewf --without-gmp
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAKE_JOBS_SAFE=	yes

.if ${CC} == "clang" || ${CXX} == "clang++"
BROKEN=		does not build when compiled with clang
.endif

MAN1=	r2.1 rabin2.1 radiff2.1 rafind2.1 ranal2.1 rarc2-tool.1 \
	rarc2.1 rasc2.1 rasm2.1 rax2.1 rsc2.1 radare2.1 rahash2.1

post-patch:
	@${REINPLACE_CMD} -e 's|..LIBDIR./pkgconfig|libdata/pkgconfig|g' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|..LFX./pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		${WRKSRC}/libr/Makefile
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's| install-doc install-man||g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
