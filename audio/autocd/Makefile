# Created by: Dmitry Afanasiev <KOT@MATPOCKuH.Ru>
# $FreeBSD$

PORTNAME=	autocd
PORTVERSION=	3.02.12b
PORTREVISION=	1
CATEGORIES=	audio sysutils
MASTER_SITES=	ftp://kot.spb.ru/pub/src/projects/autocd/

MAINTAINER=	KOT@MATPOCKuH.Ru
COMMENT=	Compact disc control utility

NO_STAGE=	yes
GNU_CONFIGURE=	yes
MAN1=		cdctl.1 acdplay.1
MAN8=		autocd.8
MLINKS=		cdctl.1 eject.1 cdctl.1 pause.1
PLIST_FILES=	sbin/autocd bin/acdplay bin/cdctl bin/pause bin/eject
PORTDOCS=	README.rus.html

USE_RC_SUBR=	autocd

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
