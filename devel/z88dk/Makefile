# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	z88dk
PORTVERSION=	2.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Complete Z80/Z180 development kit

LICENSE=	ClArtistic
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake gnome shebangfix tar:tgz
USE_GNOME=	libxml2
MAKE_ENV=	ZCCCFG=${WRKSRC}/lib/config
SHEBANG_FILES=	src/z80asm/asmpp.pl
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_JOBS_UNSAFE=	../../z80asm: No such file or directory

post-patch:
	@${REINPLACE_CMD} -e 's,"gcc,"${CC},' \
		${WRKSRC}/src/z80asm/lib/t/array.t \
		${WRKSRC}/src/z80asm/lib/t/class.t \
		${WRKSRC}/src/z80asm/lib/t/classhash.t \
		${WRKSRC}/src/z80asm/lib/t/classlist.t \
		${WRKSRC}/src/z80asm/lib/t/list.t \
		${WRKSRC}/src/z80asm/lib/t/srcfile.t \
		${WRKSRC}/src/z80asm/lib/t/strhash.t \
		${WRKSRC}/src/z80asm/t/test_utils.pl
	@${REINPLACE_CMD} -e 's,"make,"${MAKE_CMD},' \
		${WRKSRC}/src/z80asm/t/TestZ80asm.pm \
		${WRKSRC}/src/z80asm/t/objfile.t \
		${WRKSRC}/src/z80asm/t/test_enigma.t \
		${WRKSRC}/src/z80asm/t/test_utils.pl \
		${WRKSRC}/src/z80asm/t/testlib.pl \
		${WRKSRC}/src/zobjcopy/t/test.t
	@${REINPLACE_CMD} -e '/\/bin\//s,bash,sh,' \
		${WRKSRC}/src/common/t/run_tests.sh

pre-build:
	${LN} -sf z88dk/bin ${BINARY_LINKDIR}

post-install:
	@${RM} -r ${INSTALL_WRKSRC}/include/_DEVELOPMENT
	@${RM} -r ${INSTALL_WRKSRC}/libsrc/_DEVELOPMENT
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} "lib include" \
		${STAGEDIR}${DATADIR}
	@${RMDIR} ${STAGEDIR}${DATADIR}/src

.include <bsd.port.mk>
