# ex:ts=8
# New ports collection makefile for:	p5-Net-FTPServer
# Date created:			Jul 30, 2001
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Net-FTPServer
PORTVERSION=	1.111
CATEGORIES=	ftp perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Authen/PAM.pm:${PORTSDIR}/security/p5-Authen-PAM \
		${SITE_PERL}/${PERL_ARCH}/BSD/Resource.pm:${PORTSDIR}/devel/p5-BSD-Resource \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/File/Sync.pm:${PORTSDIR}/devel/p5-File-Sync \
		${SITE_PERL}/${PERL_ARCH}/IO/Dir.pm:${PORTSDIR}/devel/p5-IO \
		${SITE_PERL}/IO/Scalar.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/Archive/Zip.pm:${PORTSDIR}/archivers/p5-Archive-Zip \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes
MAKE_ENV+=	NOCONF=1
SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
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

post-patch:
	@${REINPLACE_CMD} -e "s/root,root/root,wheel/" \
		-e "s,/usr/sbin,${PREFIX}/sbin," \
		${WRKSRC}/Net-FTPServer.spec.PL
	@${REINPLACE_CMD} -e "s/-g root/-g wheel/" \
		-e "s,/usr/sbin,${PREFIX}/sbin," \
		${WRKSRC}/Makefile.PL

post-install:
	@${MKDIR} ${PREFIX}/share/examples/Net-FTPServer
	${INSTALL_DATA} ${WRKSRC}/ftpd.conf \
		${PREFIX}/share/examples/Net-FTPServer
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in FAQ README TODO doc/*
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif
	@${PERL} -pi -e 's,PREFIX,${PREFIX},g' ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
