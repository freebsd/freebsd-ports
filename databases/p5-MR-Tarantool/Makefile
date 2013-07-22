# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MR-Tarantool
PORTVERSION=	0.0.24
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Driver for an efficient Tarantool/Box NoSQL in-memory storage

BUILD_DEPENDS=	p5-AnyEvent>=7.04:${PORTSDIR}/devel/p5-AnyEvent \
		p5-Class-Singleton>=1.4:${PORTSDIR}/devel/p5-Class-Singleton \
		p5-Mouse>=1.1:${PORTSDIR}/devel/p5-Mouse \
		p5-String-CRC32>=1.4:${PORTSDIR}/devel/p5-String-CRC32
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	MR::IProto.3 \
	MR::IProto::Cluster.3 \
	MR::IProto::Cluster::Server.3 \
	MR::IProto::Connection.3 \
	MR::IProto::Connection::Async.3 \
	MR::IProto::Connection::Sync.3 \
	MR::IProto::Error.3 \
	MR::IProto::Message.3 \
	MR::IProto::NoResponse.3 \
	MR::IProto::Request.3 \
	MR::IProto::Response.3 \
	MR::IProto::Role::Debuggable.3 \
	MR::IProto::Server.3 \
	MR::IProto::Server::Connection.3 \
	MR::SilverBox.3 \
	MR::Tarantool::Box.3 \
	MR::Tarantool::Box::Singleton.3

.include <bsd.port.mk>
