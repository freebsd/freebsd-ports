# New ports collection makefile for:	mytop
# Date created:				28 Augest 2000
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	mytop
PORTVERSION=	0.9
CATEGORIES=	databases
MASTER_SITES=	http://public.yahoo.com/~jzawodn/mytop/

MAINTAINER=	leeym@leeym.com

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql

PERL_CONFIGURE=	yes

MAN1=		mytop.1

post-configure:
	@${PERL} -pi.fbsd -e 's@INSTALLMAN1DIR = /usr/local/man/man1@INSTALLMAN1DIR = ${PREFIX}/man/man1@g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
