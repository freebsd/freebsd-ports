# New ports collection makefile for:   xshisen
# Date created:               9 Oct 1996
# Whom:                 Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xshisen
PORTVERSION=	1.51
CATEGORIES=	games
MASTER_SITES=	http://www.techfirm.co.jp/~masaoki/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shisen-sho puzzle game for X11

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sharedstatedir="${DATADIR}"
INSTALL_TARGET=	install-prog

MANLANG=	"" ja
MAN6=		xshisen.6

.if !defined(WITHOUT_MOTIF)
USE_MOTIF=	yes
CONFIGURE_ARGS+=	--with-motif
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|XSHISEN_VERSION|${PORTVERSION}|g' ${WRKSRC}/lang/XShisen.ad*

post-install:
	@${CHOWN} root:games ${PREFIX}/bin/xshisen
	@${CHMOD} 2555 ${PREFIX}/bin/xshisen
	@${CHOWN} root:games ${DATADIR}/xshisen.scores
	@${CHMOD} 0660 ${DATADIR}/xshisen.scores
	${INSTALL_MAN} ${WRKSRC}/man/xshisen.6 \
		${MAN6PREFIX}/man/man6/xshisen.6
	${INSTALL_MAN} ${WRKSRC}/man/xshisen.6.ja_JP.eucJP \
		${MAN6PREFIX}/man/ja/man6/xshisen.6
	@${MKDIR} ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/lang/XShisen.ad \
		${PREFIX}/lib/X11/app-defaults/XShisen
	@${MKDIR} ${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults
	${INSTALL_DATA} ${WRKSRC}/lang/XShisen.ad.ja_JP.eucJP \
		${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults/XShisen
	-${TEST} -d ${PREFIX}/lib/X11/ja_JP.EUC/ -a \
	      -d ${PREFIX}/lib/X11/ja_JP.EUC/app-defaults && \
		${LN} -s ${PREFIX}/lib/X11/ja_JP.eucJP/app-defaults/XShisen \
			${PREFIX}/lib/X11/ja_JP.EUC/app-defaults || ${TRUE}

.include <bsd.port.mk>
