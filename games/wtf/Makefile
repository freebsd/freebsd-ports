# ex:ts=8
# New ports collection makefile for:   	wtf
# Date created:                        	29 December 2001
# Whom:                                 Maxime Henrion <mux@sneakerz.org>
#
# $FreeBSD$
#

PORTNAME=	wtf
PORTVERSION=	20011229
CATEGORIES=	games
MASTER_SITES=	http://www.sneakerz.org/~mux/wtf/

MAINTAINER=	mux@sneakerz.org

NO_BUILD=	yes

MAN6=		wtf.6

post-patch:
	@${MV} ${WRKSRC}/wtf ${WRKSRC}/wtf.orig
	@${SED} -e s#/usr/local/share/misc#${DATADIR}# \
		${WRKSRC}/wtf.orig > ${WRKSRC}/wtf
	@${MV} ${WRKSRC}/wtf.6 ${WRKSRC}/wtf.6.orig
	@${SED} -e s#/usr/share/misc#${DATADIR}# < \
		${WRKSRC}/wtf.6.orig > ${WRKSRC}/wtf.6

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wtf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wtf.6 ${PREFIX}/man/man6
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/acronyms ${DATADIR}

.include <bsd.port.mk>
