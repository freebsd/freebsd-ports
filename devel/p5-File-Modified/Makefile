# New Ports Collection Makefile for:	p5-File-Modified
# Date created:				2004-07-08
# Whom:					Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	File-Modified
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module for checking intelligently if files have changed

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		File::Modified.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README bug.txt
EXAMPLES=	example/1.pl example/Export.cfg example/Import.cfg

post-install:
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
	@${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
	@${ECHO_MSG} "===> Examples installed in ${EXAMPLESDIR}."
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/\r\n/\n/;' -e 's/^use warnings;//' ${WRKSRC}/lib/File/Modified.pm
.endif
.endif

.include <bsd.port.post.mk>
