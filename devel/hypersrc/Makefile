# ex:ts=8
# New ports collection makefile for:	hypersrc
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hypersrc
PORTVERSION=	4.4.21
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimbrooks.org/hypersrc/%SUBDIR%/
MASTER_SITE_SUBDIR=	latest old

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_BISON=	yes
USE_GNOME=	yes
USE_GMAKE=	yes

post-patch:
	@${PERL} -pi -e 's|/usr/bin/ctags|${LOCALBASE}/bin/exctags|g' ${WRKSRC}/Hypersrc.pl
	@${PERL} -pi -e 's|"-i +m -x -u"|"-x"|g' ${WRKSRC}/ctags.pl

.include <bsd.port.mk>
