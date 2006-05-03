# New ports collection makefile for:	voipong
# Date created:			20 May 2005
# Whom:				Necati Ersen SISECI <siseci@enderunix.org>
#
# $FreeBSD$
#

PORTNAME=	voipong
PORTVERSION=	1.1
CATEGORIES=	audio
MASTER_SITES=	http://www.enderunix.org/voipong/

MAINTAINER=	siseci@EnderUNIX.org
COMMENT=	Detect Voice Over IP calls and dump them to separate wave files

GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message
PLIST_FILES=	bin/voipong etc/voipong.conf-dist
PORTDOCS=	AUTHORS INSTALL README THANKS

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=""||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|$${prefix}/share/voipong|${DOCSDIR}|; \
		 s|COPYING||; s|LICENSE||' \
		${WRKSRC}/Makefile.in

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
