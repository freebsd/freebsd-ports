# ex:ts=8
# New ports collection makefile for:	p5-Net-FTPServer
# Date created:			Jul 30, 2001
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Net-FTPServer
PORTVERSION=	1.0.23
CATEGORIES=	ftp perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Authen/PAM.pm:${PORTSDIR}/security/p5-Authen-PAM \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/BSD/Resource.pm:${PORTSDIR}/devel/p5-BSD-Resource \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	Net::FTPServer.3 \
	Net::FTPServer::DBeg1::DirHandle.3 \
	Net::FTPServer::DBeg1::FileHandle.3 \
	Net::FTPServer::DBeg1::IOBlob.3 \
	Net::FTPServer::DBeg1::Server.3 \
	Net::FTPServer::DirHandle.3 \
	Net::FTPServer::FileHandle.3 \
	Net::FTPServer::Full::DirHandle.3 \
	Net::FTPServer::Full::FileHandle.3 \
	Net::FTPServer::Full::Server.3 \
	Net::FTPServer::Handle.3 \
	Net::FTPServer::InMem::DirHandle.3 \
	Net::FTPServer::InMem::FileHandle.3 \
	Net::FTPServer::InMem::Server.3 \
	Net::FTPServer::RO::DirHandle.3 \
	Net::FTPServer::RO::FileHandle.3 \
	Net::FTPServer::RO::Server.3

.include <bsd.port.mk>
