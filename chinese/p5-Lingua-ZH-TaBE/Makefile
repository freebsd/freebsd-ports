# Created by: ijliao
# $FreeBSD$

PORTNAME=	Lingua-ZH-TaBE
PORTVERSION=	0.07
PORTREVISION=	5
CATEGORIES=	chinese perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Chinese processing via libtabe

LIB_DEPENDS=	libtabe.so:chinese/libtabe

USES=		perl5
USE_PERL5=	configure

USE_BDB=	yes
OBSOLETE_BDB_VAR=	WITH_DB

CONFIGURE_ARGS=	DB="${BDB_LIB_NAME}"

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "You may specify db version to use:"
	@${ECHO_CMD} ""
	@${ECHO_CMD} "	WITH_BDB_VER=version	(Default 41)"
.if defined(WITH_BDB_VER)
	@${ECHO_CMD} ""
	@${ECHO_CMD} "WARNING:"
	@${ECHO_CMD} "	You have defined WITH_BDB_VER. Make sure you use the same"
	@${ECHO_CMD} "	db version that libtabe uses. Otherwise, this port may"
	@${ECHO_CMD} "	not work correctly."
.endif
	@${ECHO_CMD} ""

.include <bsd.port.mk>
