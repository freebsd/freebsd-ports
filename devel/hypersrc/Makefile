# ex:ts=8
# New ports collection makefile for:	hypersrc
# Date created:			Apr 9, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hypersrc
PORTVERSION=	5.3.2
PORTCOMMENT=	Source code browser
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.jimbrooks.org/hypersrc/%SUBDIR%/
MASTER_SITE_SUBDIR=	latest old

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_PERL5=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomelibs
USE_BISON=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile

post-patch:
	@${REINPLACE_CMD} -e 's|"ctags"|"exctags"|g' ${WRKSRC}/Hypersrc.pl
	@${REINPLACE_CMD} -e 's|"-i +m -x -u"|"-x"|g' ${WRKSRC}/ctags.pl

.include <bsd.port.mk>
