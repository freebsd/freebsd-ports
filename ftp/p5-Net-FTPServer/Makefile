# ex:ts=8
# New ports collection makefile for:	p5-Net-FTPServer
# Date created:			Jul 30, 2001
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	Net-FTPServer
PORTVERSION=	1.122
PORTREVISION=	2
CATEGORIES=	ftp perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A full-featured, secure, extensible and configurable Perl FTP server

RUN_DEPENDS=	p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-Authen-PAM>=0:${PORTSDIR}/security/p5-Authen-PAM \
		p5-BSD-Resource>=0:${PORTSDIR}/devel/p5-BSD-Resource \
		p5-Compress-Zlib>=1.14:${PORTSDIR}/archivers/p5-Compress-Zlib \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-File-Sync>=0:${PORTSDIR}/devel/p5-File-Sync \
		p5-IO-stringy>=1.126:${PORTSDIR}/devel/p5-IO-stringy
BUILD_DEPENDS=	${RUN_DEPENDS}

MAKE_ENV+=	NOCONF=1
PERL_CONFIGURE=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

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
	Net::FTPServer::Proxy::DirHandle.3 \
	Net::FTPServer::Proxy::FileHandle.3 \
	Net::FTPServer::Proxy::Server.3 \
	Net::FTPServer::RO::DirHandle.3 \
	Net::FTPServer::RO::FileHandle.3 \
	Net::FTPServer::RO::Server.3

DOCS=	FAQ README TODO doc/*

PORTDOCS=	*
PORTEXAMPLES=	ftpd.conf

post-patch:
	@${REINPLACE_CMD} -e "s/root,root/root,wheel/" \
		-e "s,/usr/sbin,${PREFIX}/sbin," \
		${WRKSRC}/Net-FTPServer.spec.PL
	@${REINPLACE_CMD} -e "s/-g root/-g wheel/" \
		-e "s,$$.PREFIX./sbin,${PREFIX}/sbin," \
		-e "s,$$.SITEPREFIX./sbin,${PREFIX}/sbin," \
		${WRKSRC}/Makefile.PL

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/ftpd.conf ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${PERL} -p -e 's,PREFIX,${PREFIX},g' ${PKGDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
