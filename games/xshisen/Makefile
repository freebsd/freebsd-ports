# New ports collection makefile for:   xshisen
# Date created:               9 Oct 1996
# Whom:                 Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xshisen
PORTVERSION=	1.36
CATEGORIES=	games
MASTER_SITES=	http://www.techfirm.co.jp/~masaoki/

MAINTAINER=	nakai@FreeBSD.org

# runs fine on ssh connection
#IS_INTERACTIVE=	YES	# Has to create an app-defaults file
USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-lxpg4"
CONFIGURE_ARGS=	--datadir="${X11BASE}/lib/X11" \
		--enable-japanese=euc	#Japanese char set euc, jis sjis

MANLANG=	"" ja
MAN6=		xshisen.6

post-install:
	@${CHOWN} root:games ${PREFIX}/bin/xshisen
	@${CHMOD} 2555 ${PREFIX}/bin/xshisen
	@${CHOWN} root:games ${PREFIX}/lib/X11/xshisen/xshisen-scores
	@${CHMOD} 0660 ${PREFIX}/lib/X11/xshisen/xshisen-scores
	${INSTALL_MAN} ${WRKSRC}/xshisen.man ${PREFIX}/man/man6/xshisen.6
	@${PREFIX}/bin/xshisen -KCONV jis < ${WRKSRC}/xshisen.jman-jis \
	  > ${WRKSRC}/xshisen.jman
	${INSTALL_MAN} ${WRKSRC}/xshisen.jman ${PREFIX}/man/ja/man6/xshisen.6

.include <bsd.port.mk>
