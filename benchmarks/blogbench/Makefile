# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	blogbench
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	benchmarks
MASTER_SITES=	http://download.pureftpd.org/pub/blogbench/ \
		ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/blogbench/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Performance Test of Filesystem I/O

USES=		tar:bzip2

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/blogbench man/man8/blogbench.8.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -Ee 's|[[:<:]]rand\(|arc4random(|g' \
		"${WRKSRC}"/src/*.[ch]

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
