# New ports collection makefile for:	DBD::InterBase
# Date created:		15 Oct 2001
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	DBD-InterBase
PORTVERSION=	0.46
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dbi-interbase
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	DBI driver for InterBase RDBMS server

BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
USE_FIREBIRD=	yes

post-patch:
		@${PERL} -pi -e 's,%%IB_BASE%%,${LOCALBASE},g' \
			${WRKSRC}/Makefile.PL

MAN3=		DBD::InterBase.3

.include <bsd.port.mk>
