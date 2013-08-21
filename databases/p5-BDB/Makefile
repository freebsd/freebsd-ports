# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	BDB
PORTVERSION=	1.90
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MLEHMANN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Asynchronous Berkeley DB access

BUILD_DEPENDS=	p5-common-sense>=0:${PORTSDIR}/devel/p5-common-sense
RUN_DEPENDS:=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:1.801

CFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	${PTHREAD_LIBS}
USE_BDB=	43+
USE_PERL5=	configure
USES=		perl5

MAN3=		BDB.3

post-patch:
	@${REINPLACE_CMD} -e '18 s|-lpthread -ldb|-l${BDB_LIB_NAME} ${PTHREAD_LIBS}|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
