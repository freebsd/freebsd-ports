# New ports collection makefile for:	biew
# Version required:	5.0.1
# Date created:		04 February 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

DISTNAME=	biew-501
PKGNAME=	biew-5.01
CATEGORIES=	editors
MASTER_SITES=	ftp://biew.sourceforge.net/pub/biew/5.x/src/ \
		http://download.sourceforge.net/biew/

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
USE_GMAKE=	yes
MAKE_ARGS=	"USE_NCURSES_PSEUDO=y"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS=   ncurses.4:${PORTSDIR}/devel/ncurses
MAKE_ARGS+=	"CSYSFLAGS=-D__FreeBSD_version=${OSVERSION} -I${LOCALBASE}/include"
MAKE_ARGS+=	"OSLDEF=-L${LOCALBASE}/lib"
.endif

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" \
		${WRKSRC}/lib/sysdep/generic/unix/os_dep.c

pre-build:
	 ${LN} -sf ${WRKSRC}/makefile ${WRKSRC}/Makefile

post-build:
	@ ${LN} -sf ${WRKSRC}/tools/biewhlp/makefile ${WRKSRC}/tools/biewhlp/Makefile
	@ ${LN} -sf ${WRKSRC}/tools/lzss/makefile ${WRKSRC}/tools/lzss/Makefile
	@ ${LN} -sf ${WRKSRC}/lib ${WRKSRC}/tools/biewhlp/lib
	@ ${LN} -sf ${WRKSRC}/lib ${WRKSRC}/tools/lzss/lib
	@ (cd ${WRKSRC}/tools/biewhlp;${GMAKE})
	@ (cd ${WRKSRC}/tools/lzss;${GMAKE})
	@ (cd ${WRKSRC}/hlp;${LN} -sf ../tools/biewhlp/biewhlp ./;\
	${LN} -sf ../tools/lzss/lzss ./;./biewhlp biewhlp.prj)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/biew ${PREFIX}/bin
	@ ${MKDIR} ${PREFIX}/share/biew
	${INSTALL_DATA} ${WRKSRC}/hlp/biew.hlp ${PREFIX}/share/biew

.include <bsd.port.post.mk>
