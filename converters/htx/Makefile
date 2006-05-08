# New ports collection makefile for:	htx
# Date created:		2005-07-19
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	htx
DISTVERSION=	0.7.7a
CATEGORIES=	converters www
MASTER_SITES=	http://stuff.myrealm.co.uk/htx/ \
		http://bsd.csme.ru/myports/ \
		http://bsd2.csme.ru/myports/ \
		http://bsd3.csme.ru/myports/

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	HTML to XHTML converter

USE_PERL5=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/htx

post-patch:
	@${PERL5} -pi.orig -e 's,/usr/bin/perl,${PERL5},' ${WRKSRC}/htx

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/htx ${PREFIX}/bin

.include <bsd.port.mk>
