# New ports collection makefile for:   irssi-xmpp
# Date created:                14 December 2007
# Whom:                        Philippe Audeoud <jadawin@tuxaco.net>
# $FreeBSD$

PORTNAME=	irssi-xmpp
PORTVERSION=	20090602
CATEGORIES=	irc
MASTER_SITES=	http://dindin.ru/download/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-snapshot-${PORTVERSION}

MAINTAINER=	dindin@dindin.ru
COMMENT=	Irssi-xmpp-snapshot is the irssi-xmmp cvs snapshot

BUILD_DEPENDS=	irssi:${PORTSDIR}/irc/irssi
RUN_DEPENDS=	irssi:${PORTSDIR}/irc/irssi
LIB_DEPENDS=	loudmouth:${PORTSDIR}/net-im/loudmouth

WRKSRC=	${WRKDIR}/${DISTNAME}

USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_ENV=	IRSSI_INCLUDE="${LOCALBASE}/include/irssi/"

PLIST_FILES=	lib/irssi/modules/libfe_xmpp.so \
		lib/irssi/modules/libxmpp_core.so \
		lib/irssi/modules/libtext_xmpp.so

PORTDOCS=	README FAQ GENERAL MUC STARTUP XEP

do-install:
.for data in core fe-common fe-text
	${MKDIR} ${PREFIX}/lib/irssi/modules
	${INSTALL_PROGRAM} ${WRKSRC}/src/${data}/*.so \
		${PREFIX}/lib/irssi/modules
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.for i in FAQ GENERAL MUC STARTUP XEP
	${INSTALL_DATA} ${WRKSRC}/docs/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
