# Created by: Alex Rodioukov <simuran@shaw.ca>
# $FreeBSD$

PORTNAME=	psycopg
PORTVERSION=	1.1.21
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/psycopg/tarballs/PSYCOPG-1-1/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	psycopg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance Python adapter for PostgreSQL

DEPRECATED=	This port is obsoleted by databases/py-psycopg2. Last consumer of it marked as deprecated
EXPIRATION_DATE=	2016-03-25

RUN_DEPENDS=	${DATETIME_DEP}:lang/py-mx-base
BUILD_DEPENDS=	${DATETIME_DEP}:lang/py-mx-base

USES=		gmake pgsql python
GNU_CONFIGURE=	yes

ALL_TARGET=	sharedmods

CONFIGURE_ARGS=	--with-python=${PYTHON_CMD} \
		--with-python-version=${PYTHON_VERSION:S/python//} \
		--with-postgres-libraries=${LOCALBASE}/lib \
		--with-postgres-includes=${LOCALBASE}/include \
		--with-mxdatetime-includes=${DATETIME_INC}

OPTIONS_DEFINE=	ZOPE DOCS EXAMPLES
OPTIONS_SUB=	yes

ZOPE_USES=	zope

DATETIME_DEP=	${PYTHON_SITELIBDIR}/mx/DateTime/__init__.py
DATETIME_INC=	${PYTHON_SITELIBDIR}/mx/DateTime/mxDateTime/

DOCSDIR=	${PREFIX}/share/doc/py-psycopg
EXAMPLESDIR=	${PREFIX}/share/examples/py-psycopg

EXAMPLES=	binary.py bool.py bounded.py commit.py copy_from.py \
		copy_from2.py copy_to.py dictfetch.py dt.py first.py \
		integrity.py interval.py notify.py oid.py somehackers.jpg \
		threads.py usercast.py whereareyou.jpg work.py

DOCS=		AUTHORS COPYING CREDITS ChangeLog FAQ INSTALL NEWS \
		README RELEASE-1.0 SUCCESS TODO


.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MZOPE}
post-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/ZPsycopgDA
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/psycopgmodule.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}
.if ${PORT_OPTIONS:MZOPE}
	${MKDIR} ${STAGEDIR}${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/ZPsycopgDA
	${CP} -R ${WRKSRC}/ZPsycopgDA ${STAGEDIR}${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/doc/examples/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.if !defined(BATCH) && ${PORT_OPTIONS:MZOPE}
	@${ECHO} ""
	@${ECHO} "To complete the installation of ZPsycopgDA:"
	@${ECHO} ""
	@${ECHO} "    - Restart Zope. This may be done from the Zope Control Panel."
	@${ECHO} ""
	@${ECHO} "    - Verify that the ZPsycopgDA product is loaded properly by"
	@${ECHO} "      examining them in Control_Panel/Products."
	@${ECHO} ""
.endif

.include <bsd.port.mk>
