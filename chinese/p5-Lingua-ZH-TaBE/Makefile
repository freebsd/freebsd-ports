# ex:ts=8
# Ports collection makefile for:	p5-Lingua-ZH-TaBE
# Date Created:			Jan 22, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Lingua-ZH-TaBE
PORTVERSION=	0.07
CATEGORIES=	chinese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Chinese processing via libtabe

LIB_DEPENDS=	tabe.2:${PORTSDIR}/chinese/libtabe

PERL_CONFIGURE=	yes

USE_BDB=	yes
OBSOLETE_BDB_VAR=	WITH_DB

CONFIGURE_ARGS=	DB="${BDB_LIB_NAME}"

MAN3=		Lingua::ZH::TaBE.3

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may specify db version to use:"
	@${ECHO} ""
	@${ECHO} "	WITH_DB_VER=version	(Default 41)"
	@${ECHO} ""

.include <bsd.port.mk>
