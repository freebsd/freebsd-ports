# $FreeBSD$

PORTNAME=	riscv-isa-sim
DISTVERSION=	git
PORTREVISION=	20201102
CATEGORIES=	emulators

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Spike, a RISC-V ISA Simulator

LICENSE=	BSD3CLAUSE

ONLY_FOR_ARCHS=	amd64

USES=	compiler:c++11-lang gmake shebangfix

GH_ACCOUNT=	riscv
GH_TAGNAME=	641d7d0

HAS_CONFIGURE=	yes
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
