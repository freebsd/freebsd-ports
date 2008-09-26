# ex:ts=8
# New ports collection makefile for:   	wtf
# Date created:                        	29 December 2001
# Whom:                                 Maxime Henrion <mux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wtf
PORTVERSION=	20080926
CATEGORIES=	games
MASTER_SITES=	http://jadawin.tuxaco.net/freebsd/ \
		LOCAL
MASTER_SITE_SUBDIR=	jadawin

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Translates common Internet acronyms

NO_BUILD=	yes

MAN6=		wtf.6

PLIST_FILES=	bin/wtf %%DATADIR%%/acronyms %%DATADIR%%/acronyms.comp
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/misc|${DATADIR}|g' ${WRKSRC}/wtf*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wtf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wtf.6 ${PREFIX}/man/man6
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/acronyms ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/acronyms.comp ${DATADIR}

.include <bsd.port.mk>
