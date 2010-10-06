# New ports collection makefile for:	BIEW
# Date created:				04 February 2000
# Whom:					Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	biew
PORTVERSION=	6.1.0
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/beye/biew/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Binary file viewer and editor

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--cc="${CC}" --with-extraincdir="${LOCALBASE}/include" \
		--ld="${CC}" --with-extralibdir="${LOCALBASE}/lib" \
		--prefix="${PREFIX}" --datadir="${DATADIR}"
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_DOS2UNIX=	${PORTDOCS}
MAKEFILE=	makefile
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}

MAN1=		biew.1
PORTDOCS=	biew_en.txt biew_ru.txt develop.en develop.ru file_ini.en \
		file_ini.ru licence.en licence.ru release.txt unix.txt

OPTIONS=	SLANG	"Use S-Lang based display renderer"	on

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

.if defined(WITH_SLANG)
LIB_DEPENDS=	slang.2:${PORTSDIR}/devel/libslang2
CONFIGURE_ARGS+=	--enable-slang
.else
CONFIGURE_ARGS+=	--enable-curses
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},' ${WRKSRC}/configure
# Allow it to find definition of `uintmax_t' (required at least for ia64)
	@${REINPLACE_CMD} -e 's,<sys/types,<stdint,' \
		${WRKSRC}/biewlib/sysdep/generic/__config.h

# Rebuilding of help file does not work at least on ia64; use precompiled
# file provided by original vendor (MD5 sums of both match)
#post-build:
#	${LN} -sf ../../biewlib ${WRKSRC}/tools/biewhlp/biewlib
#	cd ${WRKSRC}/tools/biewhlp && ${GMAKE} ${MAKE_ARGS}
#	${LN} -sf ../../biewlib ${WRKSRC}/tools/lzss/biewlib
#	cd ${WRKSRC}/tools/lzss && ${GMAKE} ${MAKE_ARGS}
#	(cd ${WRKSRC}/hlp; ${LN} -sf ../tools/biewhlp/biewhlp; \
#	${LN} -sf ../tools/lzss/lzss; ./biewhlp biewhlp.prj)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biew ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/skn ${DATADIR}/syntax ${DATADIR}/xlt
	${INSTALL_DATA} ${WRKSRC}/bin_rc/biew.hlp ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin_rc/skn/* ${DATADIR}/skn
	${INSTALL_DATA} ${WRKSRC}/bin_rc/syntax/* ${DATADIR}/syntax
	${INSTALL_DATA} ${WRKSRC}/bin_rc/xlt/russian/* ${DATADIR}/xlt
	${INSTALL_MAN} ${WRKSRC}/doc/biew.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
