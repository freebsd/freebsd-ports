# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	psycopg2
PORTVERSION=	2.5.3
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/psycopg/tarballs/PSYCOPG-2-5/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	High performance Python adapter for PostgreSQL

USES=		pgsql python
USE_PYTHON=	autoplist concurrent distutils

PORTEXAMPLES=	binary.py copy_from.py copy_to.py cursor.py dialtone.py \
		dict.py dt.py encoding.py fetch.py lastrowid.py lobject.py \
		mogrify.py myfirstrecipe.py notify.py simple.py somehackers.jpg \
		threads.py typecast.py tz.py usercast.py whereareyou.jpg

PORTDOCS=	AUTHORS INSTALL README NEWS PKG-INFO

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/examples/,} ${STAGEDIR}${EXAMPLESDIR}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
