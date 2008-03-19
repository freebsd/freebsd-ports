# New ports collection makefile for:	tig
# Date created:			18 Mar 2008
# Whom:				Denise H. G. <darcsis@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	tig
PORTVERSION=	0.10
CATEGORIES=	devel
MASTER_SITES=	http://jonas.nitro.dk/tig/releases/

MAINTAINER=	darcsis@gmail.com
COMMENT=	Text-mode interface for git

RUN_DEPENDS=	git:${PORTSDIR}/devel/git

MAN1=		tig.1
MAN5=		tigrc.5
MANCOMPRESSED=	no

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libiconv=${LOCALBASE}

USE_GMAKE=	yes
USE_ICONV=	yes

PLIST_FILES=	bin/tig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}rc.5 ${MANPREFIX}/man/man5

.include <bsd.port.mk>
