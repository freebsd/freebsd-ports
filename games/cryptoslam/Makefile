# ex:ts=8
# New ports collection makefile for:	cryptoslam
# Date created:			Nov 25, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cryptoslam
PORTVERSION=	1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A curses-based tool for creating and solving the cryptograms

PLIST_FILES=	bin/cryptoslam
USE_REINPLACE=  yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS+=	ncurses.5:${PORTSDIR}/devel/ncurses
CFLAGS+=	-nostdinc -I${LOCALBASE}/include/ncurses \
		-I${LOCALBASE}/include -I/usr/include
.endif

post-patch:
	@${REINPLACE_CMD} -e "s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptoslam ${PREFIX}/bin

.include <bsd.port.post.mk>
