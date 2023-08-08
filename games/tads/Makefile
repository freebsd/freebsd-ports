PORTNAME=	tads
PORTVERSION=	2.5.9
CATEGORIES=	games lang
MASTER_SITES=	LOCAL/kris
DISTNAME=	tads23-unix

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	TADS compiler/interpreter for interactive fiction
WWW=		https://www.tads.org/

LICENSE=	TADS
LICENSE_NAME=	TADS FREEWARE SOURCE CODE LICENSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

USES=		ncurses

CONFLICTS=	frobtads-1.*

DATADIR=	${PREFIX}/share/tads2

WRKSRC=		${WRKDIR}/tads-3.0.8/tads2

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/tads2
.for i in tadsc tadsr tdb
	${INSTALL_PROGRAM} ${WRKSRC}/$i ${STAGEDIR}${PREFIX}/bin
.endfor
.for i in adv.t std.t gameinfo.t
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${PREFIX}/share/tads2
.endfor

.include <bsd.port.post.mk>
