# Created by: Maxime Henrion <mux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wtf
PORTVERSION=	20130629
CATEGORIES=	games
MASTER_SITES=	SF/bsdwtf

MAINTAINER=	lifanov@mail.lifanov.com
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
