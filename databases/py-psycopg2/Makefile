# New ports collection makefile for:	py-psycopg2
# Date created:		1 August 2006
# Whom:			Martin Wilke 	<miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	psycopg2
PORTVERSION=	2.3.2
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/psycopg/tarballs/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	The high performance Python adapter for PostgreSQL

USE_PGSQL=	yes
USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes

DOCSDIR=	${PREFIX}/share/doc/py-psycopg2
EXAMPLESDIR=	${PREFIX}/share/examples/py-psycopg2

EXAMPLES=	binary.py copy_from.py copy_to.py cursor.py dialtone.py \
		dict.py dt.py encoding.py fetch.py lastrowid.py lobject.py \
		mogrify.py myfirstrecipe.py notify.py simple.py somehackers.jpg \
		threads.py typecast.py tz.py usercast.py whereareyou.jpg

DOCS=		AUTHORS ChangeLog INSTALL README PKG-INFO

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/examples/${f} ${EXAMPLESDIR}
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
