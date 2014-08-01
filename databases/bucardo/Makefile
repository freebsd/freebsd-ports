# Created by: Michelle Sullivan <michelle@sorbs.net>
# $FreeBSD$

PORTNAME=	bucardo
PORTVERSION=	5.1.1
CATEGORIES=	databases perl5
MASTER_SITES=	http://bucardo.org/downloads/
DISTNAME=	Bucardo-${PORTVERSION}

MAINTAINER=	michelle@sorbs.net
COMMENT=	Multi-Master Async Postgres Replication system

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	p5-DBD-Pg>=1.49:${PORTSDIR}/databases/p5-DBD-Pg \
		p5-DBI>=1.490:${PORTSDIR}/databases/p5-DBI \
		p5-DBIx-Safe>=1.2.5:${PORTSDIR}/databases/p5-DBIx-Safe \
		p5-boolean>=0:${PORTSDIR}/devel/p5-boolean \
		p5-Encode-Locale>=0:${PORTSDIR}/converters/p5-Encode-Locale \
		p5-ExtUtils-MakeMaker>=6.32:${PORTSDIR}/devel/p5-ExtUtils-MakeMaker \
		p5-Scalar-List-Utils>=1.0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
		p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-Net>=1.0:${PORTSDIR}/net/p5-Net \
		p5-Pod-Parser>=0:${PORTSDIR}/textproc/p5-Pod-Parser \
		p5-Sys-Syslog>=0.13:${PORTSDIR}/sysutils/p5-Sys-Syslog \
		p5-Test-Harness>=2.03:${PORTSDIR}/devel/p5-Test-Harness \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	configure
USES=		perl5

post-patch:
		@${REINPLACE_CMD} -e 's|INSTALL_BASE|DESTDIR|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
