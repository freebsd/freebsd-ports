# New ports collection makefile for:   	gate
# Date created:					15 June 2000
# Whom:                        		James Howard
#
# $FreeBSD$
#

PORTNAME=	gate
PORTVERSION=	2.05a
CATEGORIES=	editors
MASTER_SITES=	http://www.unixpapa.com/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple and unobtrusive line-oriented text editor

BUILD_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-aspell=${LOCALBASE}/bin/aspell
ALL_TARGET=	gate gate.1

MAN1=		gate.1

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${res_datadir}|${DATADIR}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|^char \*malloc();||g' ${WRKSRC}/term.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gate ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gate.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/gate.help ${DATADIR}

.include <bsd.port.mk>
