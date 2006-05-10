# New ports collection makefile for:	p5-DBI
# Date created:				October 17th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBI
PORTVERSION=	1.37
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	The perl5 Database Interface.  Required for DBD::* modules

.if defined(WITH_PROXY)
BUILD_DEPENDS=	${SITE_PERL}/RPC/PlServer.pm:${PORTSDIR}/net/p5-PlRPC
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

CONFLICTS=	p5-DBI-1.[!3]*
PERL_CONFIGURE=	yes
LATEST_LINK=	p5-DBI-137

MAN1=		dbiprof.1 \
		dbiproxy.1
MAN3=		Bundle::DBI.3 \
		DBD::Proxy.3 \
		DBI.3 \
		DBI::Const::GetInfo::ANSI.3 \
		DBI::Const::GetInfo::ODBC.3 \
		DBI::Const::GetInfoReturn.3 \
		DBI::Const::GetInfoType.3 \
		DBI::DBD.3 \
		DBI::DBD::Metadata.3 \
		DBI::FAQ.3 \
		DBI::Profile.3 \
		DBI::ProfileData.3 \
		DBI::ProfileDumper.3 \
		DBI::ProfileDumper::Apache.3 \
		DBI::ProxyServer.3 \
		DBI::PurePerl.3 \
		DBI::W32ODBC.3 \
		Win32::DBIODBC.3

.if !defined(WITH_PROXY)
pre-everything::
	@${ECHO_CMD} "If you need DBI::Proxy, try to set WITH_PROXY."
	@${ECHO_CMD} ""
	@sleep 1
.endif

post-patch:
	@${RM} -f ${WRKSRC}/lib/DBI/ProxyServer.pm.orig

.include <bsd.port.mk>
