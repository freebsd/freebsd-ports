# Created by: Mathieu Arnold <mat@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Bucardo
PORTVERSION=	4.5.0
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	http://bucardo.org/downloads/ ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mat/
PKGNAMEPREFIX=	p5-

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Asynchronous PostgreSQL replication system

LICENSE=	BSD
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
		${WRKSRC}/bucardo_ctl ${WRKSRC}/scripts/bucardo_ctl.rc

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/bucardo_ctl.rc ${STAGEDIR}${PREFIX}/etc/rc.d/bucardo

.include <bsd.port.mk>
