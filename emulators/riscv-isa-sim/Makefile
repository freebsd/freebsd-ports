PORTNAME=	riscv-isa-sim
DISTVERSION=	1.1.0-20240531
CATEGORIES=	emulators

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Spike, a RISC-V ISA Simulator
WWW=		https://github.com/riscv/riscv-isa-sim

LICENSE=	BSD3CLAUSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON=	Does not build

USES=	compiler:c++11-lang gmake shebangfix

GH_ACCOUNT=	riscv
GH_TAGNAME=	00dfa28

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-boost
SHEBANG_FILES=	scripts/vcs-version.sh

USE_GITHUB=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-DRISCV_ENABLE_DIRTY=1

STRIP_FILES=	bin/elf2hex \
		bin/spike \
		bin/spike-dasm \
		bin/spike-log-parser \
		bin/termios-xspike \
		bin/xspike \
		lib/libcustomext.so \
		lib/libriscv.so \
		lib/libsoftfloat.so

post-patch:
	${REINPLACE_CMD} -e \
	's|[(]install_libs_dir[)]/pkgconfig|(INSTALLDIR)/libdata/pkgconfig|g' \
	${WRKSRC}/Makefile.in

post-install:
.	for f in ${STRIP_FILES}
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/${f}
.	endfor

.include <bsd.port.mk>
