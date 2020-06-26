# Created by: ijliao
# $FreeBSD$

PORTNAME=	Net-FTPServer
PORTVERSION=	1.125
PORTREVISION=	2
CATEGORIES=	ftp perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Full-featured, secure, extensible, and configurable Perl FTP server

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Archive-Zip>=0:archivers/p5-Archive-Zip \
		p5-Authen-PAM>=0:security/p5-Authen-PAM \
		p5-BSD-Resource>=0:devel/p5-BSD-Resource \
		p5-DBI>=0:databases/p5-DBI \
		p5-File-Sync>=0:devel/p5-File-Sync \
		p5-IO-Stringy>=1.126:devel/p5-IO-Stringy

MAKE_ENV+=	NOCONF=1
USES=		perl5
USE_PERL5=	configure

SUB_FILES=	pkg-message

DOCS=	README TODO doc/*

PORTDOCS=	*
PORTEXAMPLES=	ftpd.conf

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e "s/root,root/root,wheel/" \
		-e "s,/usr/sbin,${PREFIX}/sbin," \
		${WRKSRC}/package/Net-FTPServer.spec.PL
	@${REINPLACE_CMD} -e "s/-g root/-g wheel/" \
		-e "s,$$.PREFIX./sbin,${PREFIX}/sbin," \
		-e "s,$$.SITEPREFIX./sbin,${PREFIX}/sbin," \
		${WRKSRC}/Makefile.PL

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/ftpd.conf ${STAGEDIR}${EXAMPLESDIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
