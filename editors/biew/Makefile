# Created by: Michael Vasilenko <acid@stu.cn.ua>
# $FreeBSD$

PORTNAME=	biew
PORTVERSION=	6.1.0
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	SF/beye/biew/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Binary file viewer and editor

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	amd64 i386 ia64
ONLY_FOR_ARCHS_REASON=	no targets defined in Makefile

USES=		dos2unix gmake iconv ncurses tar:bzip2
DOS2UNIX_FILES=	${PORTDOCS:S,^,doc/,}
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc="${CC}" --with-extraincdir="${LOCALBASE}/include" \
		--ld="${CC}" --with-extralibdir="${LOCALBASE}/lib" \
		--prefix="${PREFIX}" --datadir="${DATADIR}"
MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}

PORTDOCS=	biew_en.txt biew_ru.txt develop.en develop.ru file_ini.en \
		file_ini.ru release.txt unix.txt

OPTIONS_DEFINE=	SLANG DOCS
OPTIONS_DEFAULT=	SLANG

SLANG_DESC=	Use S-Lang based display renderer

BROKEN_powerpc=		Does not compile
BROKEN_sparc64=		Does not compile

SLANG_LIB_DEPENDS=	libslang.so:devel/libslang2
SLANG_CONFIGURE_ON=	--enable-slang
SLANG_CONFIGURE_OFF=	--enable-curses

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' ${WRKSRC}/configure
# Allow it to find definition of `uintmax_t' (required at least for ia64)
	@${REINPLACE_CMD} -e 's,<sys/types,<stdint,' \
		${WRKSRC}/biewlib/sysdep/generic/__config.h
# Fix BTx group of x86 opcodes disasm bug (upstream ticket #44, closed)
	@${REINPLACE_CMD} -e 's,DisP->codelen++),++DisP->codelen),' \
		${WRKSRC}/plugins/disasm/ix86/ix86_fun.c
# Fix inline assembly to make Clang happy (upstream ticket #49)
	@${REINPLACE_CMD} -e '/srcptr/s,::"g",::"r",' \
		${WRKSRC}/biewlib/sysdep/ia32/aclib_template.c \
		${WRKSRC}/biewlib/sysdep/x86_64/aclib_template.c
	@${REINPLACE_CMD} -E 's,fild|fistp,&s,' \
		${WRKSRC}/biewlib/sysdep/ia32/cpu_info.c \
		${WRKSRC}/biewlib/sysdep/x86_64/cpu_info.c

post-build:
# Convert Russian text files to UTF-8 encoding (doing it in post-build
# ensures we have iconv(1) installed, and seems more logical since these
# files could theoretically also be [re]built)
	@${SH} -c '${FIND} ${WRKSRC}/doc/*ru* -type f | while read f ; \
		do ${ICONV_CMD} -f cp866 -t utf-8 "$${f}" > "$${f}.tmp" && \
		${MV} "$${f}.tmp" "$${f}" ; done'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biew ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}/skn ${STAGEDIR}${DATADIR}/syntax \
		${STAGEDIR}${DATADIR}/xlt
	${INSTALL_DATA} ${WRKSRC}/bin_rc/biew.hlp ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin_rc/skn/* ${STAGEDIR}${DATADIR}/skn
	${INSTALL_DATA} ${WRKSRC}/bin_rc/syntax/* ${STAGEDIR}${DATADIR}/syntax
	${INSTALL_DATA} ${WRKSRC}/bin_rc/xlt/russian/* \
		${STAGEDIR}${DATADIR}/xlt
	${INSTALL_MAN} ${WRKSRC}/doc/biew.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
