# ex:ts=8
# Ports collection makefile for:	p5-Lingua-ZH-TaBE
# Date Created:			Jan 22, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Lingua-ZH-TaBE
PORTVERSION=	0.06
CATEGORIES=	chinese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Chinese processing via libtabe

LIB_DEPENDS=	tabe.2:${PORTSDIR}/chinese/libtabe

PERL_CONFIGURE=	yes
WITH_DB?=	db3
CONFIGURE_ARGS=	DB="${WITH_DB}"

.if ${WITH_DB} == "db2"
LIB_DEPENDS+=	db2.0:${PORTSDIR}/databases/db2
.elif ${WITH_DB} == "db4"
LIB_DEPENDS+=	db4.0:${PORTSDIR}/databases/db4
.else
LIB_DEPENDS+=	db3.3:${PORTSDIR}/databases/db3
.endif

MAN3=		Lingua::ZH::TaBE.3

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may specify db version to use:"
	@${ECHO} ""
	@${ECHO} "      WITH_DB=db_version          (Default db3)."
	@${ECHO} ""

.include <bsd.port.mk>
