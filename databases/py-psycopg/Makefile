# New ports collection makefile for:	py-psycopg
# Date created:		22 March 2002
# Whom:			Alex Rodioukov <simuran@shaw.ca>
#
# $FreeBSD$
#

PORTNAME=	psycopg
PORTVERSION=	1.0.13
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/psycopg/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	psycopg-${PORTVERSION}

MAINTAINER=	simuran@shaw.ca

RUN_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
BUILD_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
LIB_DEPENDS=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}

POSTGRESQL_PORT?=	databases/postgresql7
USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

ALL_TARGET=	sharedmods

CONFIGURE_ARGS=	--with-python=${PYTHON_CMD} \
		--with-postgres-libraries=${LOCALBASE}/lib \
		--with-postgres-includes=${LOCALBASE}/include \
		--with-mxdatetime-includes=${DATETIME_INC}

DATETIME_DEP=	${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py
DATETIME_INC=	${PYTHON_SITELIBDIR}/mx/DateTime/mxDateTime/

DOCSDIR=	${PREFIX}/share/doc/py-psycopg
EXAMPLESDIR=	${PREFIX}/share/examples/py-psycopg

EXAMPLES=	binary.py commit.py dictfetch.py dt.py first.py oid.py \
		somehackers.jpg threads.py usercast.py whereareyou.jpg \
		work.py

DOCS=		AUTHORS COPYING CREDITS ChangeLog FAQ NEWS README \
		RELEASE-1.0 SUCCESS TODO

TEXDOCS=	dbapi20programming.tex dbapiext.tex psycopg-guide.tex

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/psycopgmodule.so \
		${PYTHON_SITELIBDIR}

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/examples/${file} ${EXAMPLESDIR}
.endfor
	${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.for file in ${TEXDOCS}
	${INSTALL_MAN} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.else
PLIST=	${WRKDIR}/PLIST.nodocs
pre-install:
	${RM} -f ${PLIST}
	${GREP} -E -v '^(@dirrm )?(share/examples/)|(share/doc/)' \
		${PKGDIR}/pkg-plist > ${PLIST}
.endif

.include <bsd.port.mk>
