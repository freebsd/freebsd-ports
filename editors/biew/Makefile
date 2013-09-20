# Created by: Michael Vasilenko <acid@stu.cn.ua>
# $FreeBSD$

PORTNAME=	biew
PORTVERSION=	6.1.0
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	SF/beye/biew/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Binary file viewer and editor

LICENSE=	GPLv2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc="${CC}" --with-extraincdir="${LOCALBASE}/include" \
		--ld="${CC}" --with-extralibdir="${LOCALBASE}/lib" \
		--prefix="${PREFIX}" --datadir="${DATADIR}"
USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		iconv
USE_DOS2UNIX=	${PORTDOCS}
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}

MAN1=		biew.1
PORTDOCS=	biew_en.txt biew_ru.txt develop.en develop.ru file_ini.en \
		file_ini.ru release.txt unix.txt

OPTIONS_DEFINE=	SLANG DOCS
OPTIONS_DEFAULT=	SLANG

SLANG_DESC=	Use S-Lang based display renderer

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

.if ${PORT_OPTIONS:MSLANG}
LIB_DEPENDS=	slang:${PORTSDIR}/devel/libslang2
CONFIGURE_ARGS+=	--enable-slang
.else
CONFIGURE_ARGS+=	--enable-curses
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' ${WRKSRC}/configure
# Allow it to find definition of `uintmax_t' (required at least for ia64)
	@${REINPLACE_CMD} -e 's,<sys/types,<stdint,' \
		${WRKSRC}/biewlib/sysdep/generic/__config.h
# Fix BTx group of x86 opcodes disasm bug (upstream ticket #44, closed)
	@${REINPLACE_CMD} -e 's,DisP->codelen++),++DisP->codelen),' \
		${WRKSRC}/plugins/disasm/ix86/ix86_fun.c
# Fix inline assembly to make Clang happy (ticket #49)
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
		do iconv -f cp866 -t utf-8 "$${f}" > "$${f}.tmp" && \
		${MV} "$${f}.tmp" "$${f}" ; done'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biew ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/skn ${DATADIR}/syntax ${DATADIR}/xlt
	${INSTALL_DATA} ${WRKSRC}/bin_rc/biew.hlp ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin_rc/skn/* ${DATADIR}/skn
	${INSTALL_DATA} ${WRKSRC}/bin_rc/syntax/* ${DATADIR}/syntax
	${INSTALL_DATA} ${WRKSRC}/bin_rc/xlt/russian/* ${DATADIR}/xlt
	${INSTALL_MAN} ${WRKSRC}/doc/biew.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
