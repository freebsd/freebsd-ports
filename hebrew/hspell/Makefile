# Ports collection makefile for:  hspell
# Date created:			  03 Feb 2003
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hspell
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	hebrew
MASTER_SITES=	http://www.ivrix.org.il/projects/spell-checker/

MAINTAINER=	onatan@gmail.com
COMMENT=	Hebrew spellchecker and morphology engine

USE_PERL5_BUILD=	yes
USE_GMAKE=	yes

MAN1=		hspell.1

post-install:
	@${SED} -e "s:%%PORTSDIR%%:${PORTSDIR}:g" ${PKGMESSAGE}

.include <bsd.port.mk>
