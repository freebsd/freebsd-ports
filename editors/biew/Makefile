# New ports collection makefile for:	biew
# Date created:		04 February 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	biew
PORTVERSION=	5.2.0
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
USE_GMAKE=	yes

PORTDOCS=	biew_en.txt biew_ru.txt develop.en develop.ru file_ini.en \
		file_ini.ru licence.en licence.ru release.txt unix.txt

.include <bsd.port.pre.mk>

HOST_CFLAGS=	${CFLAGS} -DLIBDIR="\'\"${PREFIX}/share\"\'"
MAKEFILE=	makefile

.if ${OSVERSION} < 400010
LIB_DEPENDS=	ncurses.5:${PORTSDIR}/devel/ncurses
HOST_CFLAGS+=	-D__FreeBSD_version=${OSVERSION} -I${LOCALBASE}/include
HOST_LD+=	-L${LOCALBASE}/lib
.endif

MAKE_ARGS+=	HOST_CFLAGS="${HOST_CFLAGS}" CC="${CC}" LD="${CC}" \
		TARGET_OS=unix TARGET_SCREEN_LIB=curses \
		USE_MOUSE=y

post-build:
	@ ${LN} -sf ../../biewlib ${WRKSRC}/tools/biewhlp/biewlib
	cd ${WRKSRC}/tools/biewhlp; ${GMAKE} ${MAKE_ARGS}
	@ ${LN} -sf ../../biewlib ${WRKSRC}/tools/lzss/biewlib
	cd ${WRKSRC}/tools/lzss; ${GMAKE} ${MAKE_ARGS}
	@ (cd ${WRKSRC}/hlp;${LN} -sf ../tools/biewhlp/biewhlp ./;\
	${LN} -sf ../tools/lzss/lzss ./;./biewhlp biewhlp.prj)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biew ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/biew
.for file in bin_rc/assembly.skn bin_rc/standard.skn hlp/biew.hlp
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/biew
.endfor
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/biew
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${PREFIX}/share/doc/biew
.endfor
.endif

.include <bsd.port.post.mk>
