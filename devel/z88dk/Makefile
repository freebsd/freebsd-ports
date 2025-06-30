PORTNAME=	z88dk
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Complete Z80/Z180 development kit
WWW=		https://z88dk.org/site/

PATCH_SITES=	https://github.com/z88dk/z88dk/commit/
PATCHFILES=	56b25e7d8d3b16a5fbc8aa41c7d8ac86087d718b.patch:-p1

LICENSE=	ClArtistic
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dos2unix:converters/unix2dos \
		p5-CPU-Z80-Assembler>=0:devel/p5-CPU-Z80-Assembler \
		p5-Clone>=0:devel/p5-Clone \
		p5-Modern-Perl>=0:lang/p5-Modern-Perl \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny \
		ragel:devel/ragel re2c:devel/re2c
TEST_DEPENDS=	dos2unix:converters/unix2dos gm4:devel/m4 \
		p5-CPU-Z80-Assembler>=0:devel/p5-CPU-Z80-Assembler \
		p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Data-HexDump>=0:devel/p5-Data-HexDump \
		p5-Iterator-Simple-Lookahead>=0:devel/p5-Iterator-Simple-Lookahead \
		p5-Modern-Perl>=0:lang/p5-Modern-Perl \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Text-Diff>=0:textproc/p5-Text-Diff \
		p5-Text-Table>=0:textproc/p5-Text-Table \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny
RUN_DEPENDS=	gm4:devel/m4

USES=		gmake gnome perl5 shebangfix tar:tgz
USE_GNOME=	libxml2
USE_PERL5=	run
MAKE_ENV=	ZCCCFG=${WRKSRC}/lib/config Q= MALLOC_CONF=junk:false
SHEBANG_FILES=	src/z80asm/asmpp.pl src/z80asm/asmstyle.pl
TEST_TARGET=	testsuite test
WRKSRC=		${WRKDIR}/${PORTNAME}

MAKE_JOBS_UNSAFE=	../../z80asm: No such file or directory

post-patch:
	@${REINPLACE_CMD} -e 's,"gcc,"${CC},' \
		${WRKSRC}/src/z80asm/parse_ragel.pl
	@${REINPLACE_CMD} -e 's,dos2unix -q,dos2unix,' \
		${WRKSRC}/src/z80asm/Makefile
	@${REINPLACE_CMD} -e 's/process(".m4", ext, "/&g/' \
		${WRKSRC}/src/zcc/zcc.c
	@${REINPLACE_CMD} -e 's,"make,"${MAKE_CMD},' \
		${WRKSRC}/src/zobjcopy/t/test.t
	@${REINPLACE_CMD} -e '179s/$$(CFLAGS)/$$(filter -O%,&)/' \
		${WRKSRC}/support/multitarget_build/Makefile
	@${REINPLACE_CMD} -e '/^CFLAGS =/s,$$, -I../../../include,' \
		${WRKSRC}/test/suites/make.config
# Fix the build against Clang 15
	@${REINPLACE_CMD} -e '/, ifs/s,move,std::&,' \
		${WRKSRC}/src/z80asm/src/cpp/preproc.cpp

pre-build:
	${LN} -sf z88dk/bin ${BINARY_LINKDIR}

post-install:
	@${RM} -r ${INSTALL_WRKSRC}/include/_DEVELOPMENT
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} "include lib" \
		${STAGEDIR}${DATADIR}
	@${RMDIR} ${STAGEDIR}${DATADIR}/src

.include <bsd.port.mk>
