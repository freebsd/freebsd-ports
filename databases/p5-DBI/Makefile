# New ports collection makefile for:	p5-DBI
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBI
PORTVERSION=	1.61.1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The perl5 Database Interface.  Required for DBD::* modules

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
BUILD_DEPENDS=	${RUN_DEPENDS}

.if defined(WITH_PROXY)
RUN_DEPENDS+=	${SITE_PERL}/RPC/PlServer.pm:${PORTSDIR}/net/p5-PlRPC
.endif

CONFLICTS=	p5-DBI-1.3*
PERL_CONFIGURE=	yes

MAN1=		dbilogstrip.1 dbiprof.1 dbiproxy.1
MAN3=		Bundle::DBI.3 \
		DBD::DBM.3 \
		DBD::File.3 \
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
		DBI::FAQ.3 \
		DBI::Gofer::Execute.3 \
		DBI::Gofer::Request.3 \
		DBI::Gofer::Response.3 \
		DBI::Gofer::Serializer::DataDumper.3 \
		DBI::Gofer::Serializer::Base.3 \
		DBI::Gofer::Serializer::Storable.3 \
		DBI::Gofer::Transport::Base.3 \
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
		Roadmap.3 \
		TASKS.3 \
		Win32::DBIODBC.3

.if !defined(WITH_PROXY)
pre-everything::
	@${ECHO_CMD} "If you need DBI::Proxy, try to set WITH_PROXY."
	@${ECHO_CMD} ""
	@sleep 1
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>
