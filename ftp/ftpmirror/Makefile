# Created by: Yasuhiro Fukuma <yasuf@big.or.jp>
# $FreeBSD$

PORTNAME=	ftpmirror
PORTVERSION=	1.96
PORTREVISION=	4
CATEGORIES=	ftp ipv6
MASTER_SITES=	ftp://ftp.sai.msu.su/pub/unix/FTP/mirror/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Utility to mirror directory hierarchy with FTP

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	p5-Socket6>=0:${PORTSDIR}/net/p5-Socket6

OPTIONS_DEFINE=	DOCS

GNU_CONFIGURE=	yes

USES=		shebangfix perl5
SHEBANG_FILES=	ftpmirror rotate

CONFIGURE_ENV+=	PERL="${PERL}" INSTALL_PROGRAM="${INSTALL_SCRIPT}"

PORTDOCS=	README.jis RELEASE.jis

post-configure:
	@${REINPLACE_CMD} -i '' -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/Fan/Fan.pm

post-install:
	-@[ -d ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto ] && ${FIND} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto -name .packlist -exec ${SED} -i '' 's|^${STAGEDIR}||' '{}' \;
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
