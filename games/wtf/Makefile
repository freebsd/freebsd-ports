# ex:ts=8
# New ports collection makefile for:   	wtf
# Date created:                        	29 December 2001
# Whom:                                 Maxime Henrion <mux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wtf
PORTVERSION=	20040124
CATEGORIES=	games
MASTER_SITES=	http://www.mu.org/~mux/wtf/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	petef

MAINTAINER=	mux@FreeBSD.org
COMMENT=	Translates common Internet acronyms

NO_BUILD=	yes

MAN6=		wtf.6

post-patch:
	@${MV} ${WRKSRC}/wtf ${WRKSRC}/wtf.orig
	@${SED} -e s#/usr/share/misc#${DATADIR}# \
		${WRKSRC}/wtf.orig > ${WRKSRC}/wtf
	@${MV} ${WRKSRC}/wtf.6 ${WRKSRC}/wtf.6.orig
	@${SED} -e s#/usr/share/misc#${DATADIR}# \
		${WRKSRC}/wtf.6.orig > ${WRKSRC}/wtf.6

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wtf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wtf.6 ${PREFIX}/man/man6
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/acronyms ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/acronyms.comp ${DATADIR}

.include <bsd.port.mk>
