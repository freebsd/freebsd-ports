# New ports collection makefile for:	acs
# Date created:		01 January 1995
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	acs
PORTVERSION=	0.28
CATEGORIES=	cad
MASTER_SITES=	http://www.geda.seul.org/dist/ \
		http://www.geda.coelacanth.com/dist/ \
		ftp://ftp.geda.seul.org/pub/geda/dist/

MAINTAINER=	tg@FreeBSD.org

USE_NEWGCC=	yes
MAKE_ENV=	CCC="${CXX}"

post-extract:
	${CP} ${FILESDIR}/acs.rc ${FILESDIR}/Makefile ${WRKSRC}

post-patch:
	${PERL} -pi -e "s;%%PREFIX%%;${PREFIX};g" ${WRKSRC}/src/md.h

.include <bsd.port.mk>
