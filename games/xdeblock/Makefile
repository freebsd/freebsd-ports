# New ports collection makefile for:	xdeblock
# Date created:		28 December 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xdeblock
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.vector.co.jp/pack/unix/game/action/block/
DISTFILES=	${PORTNAME}.tgz

MAINTAINER=	nakai@FreeBSD.org
COMMENT=	Block action game

WRKSRC=		${WRKDIR}/xdeblo_v1.0
USE_IMAKE=	yes
USE_XPM=	yes
NO_INSTALL_MANPAGES=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile"
.endif

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdeblo ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/X11/xdeblock/mapf
	${CHMOD} 777 ${PREFIX}/lib/X11/xdeblock/mapf
	${INSTALL_DATA} ${WRKSRC}/mapf/*.txt ${PREFIX}/lib/X11/xdeblock/mapf

.include <bsd.port.post.mk>
