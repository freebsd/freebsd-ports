# New ports collection makefile for:	mytop
# Date created:				28 Augest 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mytop
PORTVERSION=	1.4
CATEGORIES=	databases
MASTER_SITES=	http://jeremy.zawodny.com/mysql/mytop/

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	A top clone for MySQL

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes

PERL_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		mytop.1

post-patch:
	@${REINPLACE_CMD} -e 's, -P , B<-P> ,g' ${WRKSRC}/mytop

.include <bsd.port.mk>
