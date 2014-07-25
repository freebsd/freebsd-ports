# Created by: Mathieu Arnold <mat@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Bucardo
PORTVERSION=	5.1.1
CATEGORIES=	databases perl5
MASTER_SITES=	http://bucardo.org/downloads/ LOCAL/mat/${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Asynchronous PostgreSQL replication system

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-DBI>=1.51:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-Pg>=2.0:${PORTSDIR}/databases/p5-DBD-Pg \
		p5-DBIx-Safe>=1.2.4:${PORTSDIR}/databases/p5-DBIx-Safe
RUN_DEPENDS=	p5-DBI>=1.51:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-Pg>=2.0:${PORTSDIR}/databases/p5-DBD-Pg \
		p5-DBIx-Safe>=1.2.4:${PORTSDIR}/databases/p5-DBIx-Safe

USES=	perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} 's/INSTALL_BASE/DESTDIR/;s/bucardo_ctl.1pm/bucardo_ctl.1/' \
		${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} 's=/usr/local=${PREFIX}=' ${WRKSRC}/Makefile.PL \
		${WRKSRC}/bucardo ${WRKSRC}/dist/bucardo.rc

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dist/bucardo.rc ${STAGEDIR}${PREFIX}/etc/rc.d/bucardo
	${RM} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Bucardo/.packlist
	${RMDIR} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Bucardo

.include <bsd.port.mk>
