# Created by: Brooks Davis
# $FreeBSD$

PKGNAMESUFFIX=	-cheri128m

COMMENT=	QEMU emulator with CHERI CPU support (128-bit, magic compression)

RUN_DEPENDS=	qemu-system-cheri:emulators/qemu-cheri

MASTERDIR=	${.CURDIR}/../qemu-cheri

EXTRA_CFLAGS=	-DCHERI_MAGIC128
PLIST=		/dev/null
PLIST_FILES=	bin/qemu-system-cheri128m

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cheri-softmmu/qemu-system-cheri \
	    ${STAGEDIR}${PREFIX}/bin/qemu-system-cheri128m

.include <${MASTERDIR}/Makefile>
