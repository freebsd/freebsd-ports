# New ports collection makefile for:	ftpmirror
# Date created:		10 January 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	ftpmirror
PORTVERSION=	1.96
PORTREVISION=	3
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.intec.co.jp/pub/utils/ftpmirror/beta/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	An utility to mirror directory hierarchy with FTP

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Socket6.pm:${PORTSDIR}/net/p5-Socket6

USE_PERL5=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ENV+=	PERL="${PERL}" INSTALL_PROGRAM="${INSTALL_SCRIPT}"

.if !defined (NOPORTDOCS)
PORTDOCS=	README.jis RELEASE.jis
.endif

post-configure:
	@${PERL} -i.bak -pe 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/Fan/Fan.pm
.for f in ftpmirror rotate
	@${PERL} -i.bak -pe 's,^#!.*$$,#!${PERL}, if $$. == 1' ${WRKSRC}/${f}
.endfor

post-install:
.if !defined (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
