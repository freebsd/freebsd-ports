# $FreeBSD$

PORTNAME=	riscv-isa-sim
DISTVERSION=	git
PORTREVISION=	20170810
CATEGORIES=	emulators

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Spike, a RISC-V ISA Simulator

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libfesvr.so:emulators/riscv-fesvr

ONLY_FOR_ARCHS=	amd64

GH_ACCOUNT=	freebsd-riscv
GH_TAGNAME=	54ae820

USES=	compiler:c++11-lang gmake shebangfix

HAS_CONFIGURE=	yes
SHEBANG_FILES=	scripts/vcs-version.sh
USE_GITHUB=	yes
USE_LDCONFIG=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include \
		-DRISCV_ENABLE_DIRTY=1

STRIP_FILES=	bin/spike \
		bin/spike-dasm \
		bin/termios-xspike \
		bin/xspike \
		lib/libdummy_rocc.so \
		lib/libriscv.so \
		lib/libsoftfloat.so \
		lib/libspike_main.so

post-extract:
	@${MV} ${WRKSRC}/riscv/insn_template.h ${WRKSRC}/riscv/insn_template.hpp

post-patch:
	${REINPLACE_CMD} -e \
	's|[(]install_libs_dir[)]/pkgconfig|(INSTALLDIR)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.in

post-install:
.	for f in ${STRIP_FILES}
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/${f}
.	endfor

.include <bsd.port.mk>
