PORTNAME=	z88dk
PORTVERSION=	2.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Complete Z80/Z180 development kit
WWW=		https://z88dk.org/site/

LICENSE=	ClArtistic
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dos2unix:converters/unix2dos \
		p5-CPU-Z80-Assembler>=0:devel/p5-CPU-Z80-Assembler \
		p5-Clone>=0:devel/p5-Clone \
		p5-Modern-Perl>=0:lang/p5-Modern-Perl \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny \
		ragel:devel/ragel re2c:devel/re2c
TEST_DEPENDS=	dos2unix:converters/unix2dos \
		p5-CPU-Z80-Assembler>=0:devel/p5-CPU-Z80-Assembler \
		p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-Capture-Tiny-Extended>=0:devel/p5-Capture-Tiny-Extended \
		p5-Clone>=0:devel/p5-Clone \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-Data-HexDump>=0:devel/p5-Data-HexDump \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-Iterator-Simple-Lookahead>=0:devel/p5-Iterator-Simple-Lookahead \
		p5-List-Uniq>=0:devel/p5-List-Uniq \
		p5-Modern-Perl>=0:lang/p5-Modern-Perl \
		p5-Object-Tiny-RW>=0:devel/p5-Object-Tiny-RW \
		p5-Path-Tiny>=0:devel/p5-Path-Tiny \
		p5-Regexp-Common>=0:textproc/p5-Regexp-Common \
		p5-Template-Plugin-YAML>=0:textproc/p5-Template-Plugin-YAML \
		p5-Test-Differences>=0:devel/p5-Test-Differences \
		p5-Test-HexDifferences>=0:devel/p5-Test-HexDifferences \
		p5-Text-Table>=0:textproc/p5-Text-Table

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
	@${REINPLACE_CMD} -e 's,"make,"${MAKE_CMD},' \
		${WRKSRC}/src/zobjcopy/t/test.t
	@${REINPLACE_CMD} -e '/\/bin\//s,bash,sh,' \
		${WRKSRC}/src/common/t/run_tests.sh

pre-build:
	${LN} -sf z88dk/bin ${BINARY_LINKDIR}

post-install:
	@${RM} -r ${INSTALL_WRKSRC}/include/_DEVELOPMENT
	cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} "include lib" \
		${STAGEDIR}${DATADIR}
	@${RMDIR} ${STAGEDIR}${DATADIR}/src

.include <bsd.port.mk>
