# New ports collection makefile for:	py-psycopg
# Date created:		22 March 2002
# Whom:			Alex Rodioukov <simuran@shaw.ca>
#
# $FreeBSD$
#

PORTNAME=	psycopg
PORTVERSION=	1.1.9
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/psycopg/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	psycopg-${PORTVERSION}

MAINTAINER=	simuran@shaw.ca
COMMENT=	The high performance Python adapter for PostgreSQL

RUN_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
BUILD_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

POSTGRESQL_PORT?=	databases/postgresql7

ALL_TARGET=	sharedmods

CONFIGURE_ARGS=	--with-python=${PYTHON_CMD} \
		--with-postgres-libraries=${LOCALBASE}/lib \
		--with-postgres-includes=${LOCALBASE}/include \
		--with-mxdatetime-includes=${DATETIME_INC}

DATETIME_DEP=	${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py
DATETIME_INC=	${PYTHON_SITELIBDIR}/mx/DateTime/mxDateTime/

DOCSDIR=	${PREFIX}/share/doc/py-psycopg
EXAMPLESDIR=	${PREFIX}/share/examples/py-psycopg

EXAMPLES=	binary.py bool.py commit.py copy_from.py copy_from2.py \
		copy_to.py dictfetch.py dt.py first.py integrity.py \
		oid.py notify.py somehackers.jpg threads.py usercast.py \
		whereareyou.jpg work.py

DOCS=		AUTHORS COPYING CREDITS ChangeLog FAQ INSTALL NEWS \
		README RELEASE-1.0 SUCCESS TODO

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/psycopgmodule.so \
		${PYTHON_SITELIBDIR}

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/${f} ${EXAMPLESDIR}
.endfor
	${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.else
PLIST=	${WRKDIR}/PLIST.nodocs
pre-install:
	${RM} -f ${PLIST}
	${GREP} -E -v '^(@dirrm )?(share/examples/)|(share/doc/)' \
		${PKGDIR}/pkg-plist > ${PLIST}
.endif

.include <bsd.port.mk>
