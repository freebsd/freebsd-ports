# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	psycopg2
PORTVERSION=	2.5.2
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/psycopg/tarballs/PSYCOPG-2-5/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	High performance Python adapter for PostgreSQL

USE_PGSQL=		yes
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

DOCSDIR=	${PREFIX}/share/doc/py-psycopg2
EXAMPLESDIR=	${PREFIX}/share/examples/py-psycopg2

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
