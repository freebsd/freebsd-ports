# New ports collection makefile for:	biew
# Date created:		04 February 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	biew
PORTVERSION=	5.6.2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ryan@sasknow.com
COMMENT=	Binary vIEWer + editor for binary, hexadecimal and dis-asm modes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:S/.//g}

USE_BZIP2=	yes
USE_GMAKE=	yes

PORTDOCS=	biew_en.txt biew_ru.txt develop.en develop.ru file_ini.en \
		file_ini.ru licence.en licence.ru release.txt unix.txt

PLIST_FILES=	bin/biew \
		share/biew/assembly.skn \
		share/biew/biew.hlp \
		share/biew/golded.skn \
		share/biew/insight.skn \
		share/biew/standard.skn \

PLIST_DIRS=	share/biew

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS=	ncurses.5:${PORTSDIR}/devel/ncurses
HOST_CFLAGS+=	-D__FreeBSD_version=${OSVERSION} -I${LOCALBASE}/include
HOST_LD+=	-L${LOCALBASE}/lib
.endif

OST_CFLAGS=	${CFLAGS} -DPREFIX="\'\"${PREFIX}\"\'"
MAKEFILE=	makefile

MAKE_ARGS+=	HOST_CFLAGS="${HOST_CFLAGS}" CC="${CC}" LD="${CC}" \
		TARGET_OS=unix TARGET_SCREEN_LIB=curses \
		USE_MOUSE=y

.if ${ARCH} != "i386"
MAKE_ARGS+=	TARGET_PLATFORM=generic
.endif

post-build:
	@ ${LN} -sf ../../biewlib ${WRKSRC}/tools/biewhlp/biewlib
	cd ${WRKSRC}/tools/biewhlp; ${GMAKE} ${MAKE_ARGS}
	@ ${LN} -sf ../../biewlib ${WRKSRC}/tools/lzss/biewlib
	cd ${WRKSRC}/tools/lzss; ${GMAKE} ${MAKE_ARGS}
	@ (cd ${WRKSRC}/hlp;${LN} -sf ../tools/biewhlp/biewhlp ./;\
	${LN} -sf ../tools/lzss/lzss ./;./biewhlp biewhlp.prj)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biew ${PREFIX}/bin
	@ ${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/bin_rc/skn/*.skn ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/hlp/biew.hlp ${DATADIR}
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
