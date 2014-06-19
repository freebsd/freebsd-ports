# Created by: janos.mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	blogbench
PORTVERSION=	1.1
CATEGORIES=	benchmarks
MASTER_SITES=	http://download.pureftpd.org/pub/blogbench/ \
		ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/blogbench/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Performance Test of Filesystem I/O

GNU_CONFIGURE=	yes
USES=		tar:bzip2

PLIST_FILES=	bin/blogbench man/man8/blogbench.8.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
