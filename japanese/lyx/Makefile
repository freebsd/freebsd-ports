# New ports collection makefile for:	lyx
# Version required:	1.0.3
# Date created:		27 April 1999
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

DISTNAME=	lyx-1.0.3
PKGNAME=	ja-lyx-1.0.3
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/ \
		ftp://la1ad.uio.no/pub/lyx/ \
		ftp://alpha.tat.physik.uni-tuebingen.de/pub/lyx/stable/ \
		ftp://ftp.sdsc.edu/pub/other/lyx/stable/ \
		http://cgi.din.or.jp/~kawakami/product/LyX/
DISTFILES=	lyx-1.0.3.tar.gz lyx-jp-kit0.10b4for1.0.3.tar.gz

MAINTAINER=	flathill@FreeBSD.ORG

RUN_DEPENDS=	platex:${PORTSDIR}/japanese/platex-euc
.if defined(WITH_ISPELL)
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
.endif
LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms \
		Xpm.4:${PORTSDIR}/graphics/xpm

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LYX_LIBS="-lxpg4" CXXFLAGS="${CFLAGS}"
STRIP=
CONFIGURE_ARGS= --with-extra-lib=${X11BASE}/lib --with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"
MAN1=		lyx.1 reLyX.1

pre-fetch:
.if !defined(WITH_ISPELL)
	@${ECHO_MSG} "if you want this port build with spell checker type"
	@${ECHO_MSG} "make WITH_ISPELL=yes"
.endif

do-patch:
	@cd ${WRKSRC}; ${PATCH} -p1 < ../lyx-jp-patch

post-install:
	@strip ${PREFIX}/bin/lyx
	${INSTALL_DATA} ${WRKDIR}/ChangeLog.jis ${PREFIX}/share/lyx
	${INSTALL_DATA} ${WRKDIR}/README.jis ${PREFIX}/share/lyx
	${INSTALL_DATA} ${WRKSRC}/lib/lyxrc.jp ${PREFIX}/share/lyx

.include <bsd.port.mk>
