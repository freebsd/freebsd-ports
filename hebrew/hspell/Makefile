# Ports collection makefile for:  hspell
# Date created:			  03 Feb 2003
# Whom:				  Yonatan <onatan@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hspell
PORTVERSION=	0.8
CATEGORIES=	hebrew
MASTER_SITES=	http://www.ivrix.org.il/projects/spell-checker/

MAINTAINER=	onatan@gmail.com
COMMENT=	Hebrew spellchecker and morphology engine

USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=

MAN1=		hspell.1
MAN3=		hspell.3

post-install:
	@${SED} -e "s:%%PORTSDIR%%:${PORTSDIR}:g" ${PKGMESSAGE}

.include <bsd.port.mk>
