PORTNAME=	blogbench
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	benchmarks
MASTER_SITES=	http://download.pureftpd.org/pub/blogbench/ \
		ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/blogbench/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Performance Test of Filesystem I/O
WWW=		https://github.com/jedisct1/Blogbench

USES=		tar:bzip2

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/blogbench share/man/man8/blogbench.8.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -Ee 's|[[:<:]]rand\(|arc4random(|g' \
		"${WRKSRC}"/src/*.[ch]

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
