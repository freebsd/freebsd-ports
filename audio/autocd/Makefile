# New ports collection makefile for:	 autocd
# Date created:		11 Marth 2003
# Whom:			Dmitry Afanasiev <KOT@MATPOCKuH.Ru>
#
# $FreeBSD$
#

PORTNAME=	autocd
PORTVERSION=	3.02.12b
PORTREVISION=	1
CATEGORIES=	audio sysutils
MASTER_SITES=	ftp://kot.spb.ru/pub/src/projects/autocd/

MAINTAINER=	KOT@MATPOCKuH.Ru
COMMENT=	Compact disc control utility

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAN1=		cdctl.1 acdplay.1
MAN8=		autocd.8
MLINKS=		cdctl.1 eject.1 cdctl.1 pause.1
PLIST_FILES=	sbin/autocd bin/acdplay bin/cdctl bin/pause bin/eject
PORTDOCS=	README.rus.html

USE_RC_SUBR=	autocd

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
