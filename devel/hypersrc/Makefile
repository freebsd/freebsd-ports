# ex:ts=8
# New ports collection makefile for:	hypersrc
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hypersrc
PORTVERSION=	5.3.12
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimbrooks.org/hypersrc/%SUBDIR%/ \
		http://www.home.earthlink.net/~jebrooks1/ftp/hypersrc/%SUBDIR%/
MASTER_SITE_SUBDIR=	latest old

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Source code browser

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PERL5=	yes
USE_GNOME=	gnomelibs
USE_BISON=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

MAN1=		hypersrc.1

post-patch:
	@${PERL} -pi -e 's|"ctags"|"exctags"|g' ${WRKSRC}/Hypersrc.pl
	@${PERL} -pi -e 's|"-i +m -x -u"|"-x"|g' ${WRKSRC}/ctags.pl

post-install:
	${INSTALL_MAN} ${WRKSRC}/hypersrc.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
