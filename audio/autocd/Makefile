# New ports collection makefile for:	 autocd
# Date created:		11 Marth 2003
# Whom:			Dmitry Afanasiev <KOT@MATPOCKuH.Ru>
#
# $FreeBSD$
#

PORTNAME=	autocd
PORTVERSION=	3.02.04a
CATEGORIES=	audio sysutils
MASTER_SITES=	ftp://kot.spb.ru/pub/src/projects/autocd/

MAINTAINER=	KOT@MATPOCKuH.Ru
COMMENT=	Compact disc control utility

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAN1=		cdctl.1 acdplay.1
MAN8=		autocd.8
MLINKS=		cdctl.1 eject.1 cdctl.1 pause.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400010
LIB_DEPENDS=	ncurses.5:${PORTSDIR}/devel/ncurses
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rus.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
