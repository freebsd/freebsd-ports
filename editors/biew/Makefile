# New ports collection makefile for:	biew
# Date created:		04 February 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	biew
PORTVERSION=    5.1.0
CATEGORIES=	editors
MASTER_SITES=	ftp://biew.sourceforge.net/pub/biew/5.x/src/ \
		http://download.sourceforge.net/biew/
DISTNAME=       ${PORTNAME}-510

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

HOST_CFLAGS=    ${CFLAGS}
HOST_LD=        ${CC}
MAKEFILE=       makefile

.if ${OSVERSION} < 400010
LIB_DEPENDS=    ncurses.4:${PORTSDIR}/devel/ncurses
HOST_CFLAGS+=   -D__FreeBSD_version=${OSVERSION} -I${LOCALBASE}/include
HOST_LD+=       -L${LOCALBASE}/lib
.endif

MAKE_ARGS+=     HOST_CFLAGS="${HOST_CFLAGS}" LD="${HOST_LD}" \
		TARGET_OS=unix TARGET_SCREEN_LIB=curses \
		USE_MOUSE=y

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/lib/sysdep/generic/unix/os_dep.c

post-build:
	@ ${LN} -sf ../../lib ${WRKSRC}/tools/biewhlp/lib
	cd ${WRKSRC}/tools/biewhlp; ${GMAKE} ${MAKE_ARGS}
	@ ${LN} -sf ../../lib ${WRKSRC}/tools/lzss/lib
	cd ${WRKSRC}/tools/lzss; ${GMAKE} ${MAKE_ARGS}
	@ (cd ${WRKSRC}/hlp;${LN} -sf ../tools/biewhlp/biewhlp ./;\
	${LN} -sf ../tools/lzss/lzss ./;./biewhlp biewhlp.prj)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biew ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/biew
	${INSTALL_DATA} ${WRKSRC}/hlp/biew.hlp ${WRKSRC}/bin_rc/standard.skn \
		${PREFIX}/share/biew

.include <bsd.port.post.mk>
