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
MASTER_SITES=	ftp://ftp.sai.msu.su/pub/unix/FTP/mirror/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	An utility to mirror directory hierarchy with FTP

RUN_DEPENDS=	p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

USE_PERL5=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ENV+=	PERL="${PERL}" INSTALL_PROGRAM="${INSTALL_SCRIPT}"

PORTDOCS=	README.jis RELEASE.jis

post-configure:
	@${PERL} -i.bak -pe 's,%%PREFIX%%,${PREFIX},g' ${WRKSRC}/Fan/Fan.pm
.for f in ftpmirror rotate
	@${PERL} -i.bak -pe 's,^#!.*$$,#!${PERL}, if $$. == 1' ${WRKSRC}/${f}
.endfor

.include <bsd.port.pre.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
