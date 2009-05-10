# New ports collection makefile for:	py-psycopg2
# Date created:		1 August 2006
# Whom:			Martin Wilke 	<miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	psycopg2
PORTVERSION=	2.0.10
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/psycopg/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	psycopg2-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	The high performance Python adapter for PostgreSQL

USE_PGSQL=	yes
USE_GMAKE=	yes
USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

do-build:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py build)

do-install:
	@(cd ${WRKSRC}; ${PYTHON_CMD} setup.py install)

DOCSDIR=	${PREFIX}/share/doc/py-psycopg2
EXAMPLESDIR=	${PREFIX}/share/examples/py-psycopg2

EXAMPLES=	binary.py cursor.py dt.py lastrowid.py notify.py threads.py \
		whereareyou.jpg copy_from.py dialtone.py encoding.py \
		mogrify.py simple.py tz.py copy_to.py dict.py fetch.py \
		myfirstrecipe.py somehackers.jpg usercast.py

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
