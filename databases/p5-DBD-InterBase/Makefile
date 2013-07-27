# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	DBD-InterBase
PORTVERSION=	0.48
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	DBI driver for InterBase RDBMS server

BUILD_DEPENDS=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
USE_FIREBIRD=	yes

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|%%IB_BASE%%|${LOCALBASE}|' \
		${WRKSRC}/Makefile.PL

MAN3=		DBD::InterBase.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} > 501400
BROKEN=	does not compile, project moved or dead, no releases since 2003
.endif
.include <bsd.port.post.mk>
