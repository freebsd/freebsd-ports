# New ports collection makefile for:	p5-DBI
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBI
PORTVERSION=	1.617
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The perl5 Database Interface.  Required for DBD::* modules

LICENSE=	ART20 GPLv1
LICENSE_COMB=	dual

OPTIONS=	PROXY "Build DBI::Proxy" off

CONFLICTS=	p5-DBI-1.3*

PERL_CONFIGURE=	yes

MAN1=		dbilogstrip.1 dbiprof.1 dbiproxy.1
MAN3=		Bundle::DBI.3 \
		DBD::DBM.3 \
		DBD::File.3 \
		DBD::File::Developers.3 \
		DBD::File::HowTo.3 \
		DBD::File::Roadmap.3 \
		DBD::Gofer.3 \
		DBD::Gofer::Policy::Base.3 \
		DBD::Gofer::Policy::classic.3 \
		DBD::Gofer::Policy::pedantic.3 \
		DBD::Gofer::Policy::rush.3 \
		DBD::Gofer::Transport::Base.3 \
		DBD::Gofer::Transport::null.3 \
		DBD::Gofer::Transport::pipeone.3 \
		DBD::Gofer::Transport::stream.3 \
		DBD::Proxy.3 \
		DBD::Sponge.3 \
		DBI.3 \
		DBI::Const::GetInfo::ANSI.3 \
		DBI::Const::GetInfo::ODBC.3 \
		DBI::Const::GetInfoReturn.3 \
		DBI::Const::GetInfoType.3 \
		DBI::DBD.3 \
		DBI::DBD::Metadata.3 \
		DBI::DBD::SqlEngine.3 \
		DBI::DBD::SqlEngine::HowTo.3 \
		DBI::DBD::SqlEngine::Developers.3 \
		DBI::FAQ.3 \
		DBI::Gofer::Execute.3 \
		DBI::Gofer::Request.3 \
		DBI::Gofer::Response.3 \
		DBI::Gofer::Serializer::DataDumper.3 \
		DBI::Gofer::Serializer::Base.3 \
		DBI::Gofer::Serializer::Storable.3 \
		DBI::Gofer::Transport::Base.3 \
		DBD::Gofer::Transport::corostream.3 \
		DBI::Gofer::Transport::pipeone.3 \
		DBI::Gofer::Transport::stream.3 \
		DBI::Profile.3 \
		DBI::ProfileData.3 \
		DBI::ProfileDumper.3 \
		DBI::ProfileDumper::Apache.3 \
		DBI::ProfileSubs.3 \
		DBI::ProxyServer.3 \
		DBI::PurePerl.3 \
		DBI::SQL::Nano.3 \
		DBI::Util::CacheMemory.3 \
		DBI::W32ODBC.3 \
		Win32::DBIODBC.3

.include <bsd.port.options.mk>

.if defined(WITH_PROXY)
BUILD_DEPENDS+=	p5-PlRPC>=0.2001:${PORTSDIR}/net/p5-PlRPC
RUN_DEPENDS+=	p5-PlRPC>=0.2001:${PORTSDIR}/net/p5-PlRPC
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
