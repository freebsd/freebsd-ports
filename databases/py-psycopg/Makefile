# New ports collection makefile for:	py-psycopg
# Date created:		22 March 2002
# Whom:			Alex Rodioukov <simuran@shaw.ca>
#
# $FreeBSD$
#

PORTNAME=	psycopg
PORTVERSION=	1.1.18
CATEGORIES=	databases python
MASTER_SITES=	http://initd.org/pub/software/psycopg/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	psycopg-${PORTVERSION}

MAINTAINER=	simuran@shaw.ca
COMMENT=	The high performance Python adapter for PostgreSQL

RUN_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base
BUILD_DEPENDS=	${DATETIME_DEP}:${PORTSDIR}/lang/py-mx-base

USE_PGSQL=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

ALL_TARGET=	sharedmods

CONFIGURE_ARGS=	--with-python=${PYTHON_CMD} \
		--with-python-version=${PYTHON_VERSION:S/python//} \
		--with-postgres-libraries=${LOCALBASE}/lib \
		--with-postgres-includes=${LOCALBASE}/include \
		--with-mxdatetime-includes=${DATETIME_INC}

.if defined(WITH_ZOPE)
USE_ZOPE=	yes
PLIST_SUB+=	ZOPE=""
.else
PLIST_SUB+=	ZOPE="@comment "
.endif

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

pre-everything::
.if !defined(WITH_ZOPE)
	@${ECHO} ""
	@${ECHO} "* To build with Zope support please specify WITH_ZOPE=YES"
	@${ECHO} ""
.endif

.if defined(WITH_ZOPE)
post-build:
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}/ZPsycopgDA
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/psycopgmodule.so \
		${PYTHON_SITELIBDIR}
.if defined(WITH_ZOPE)
	${MKDIR} ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/ZPsycopgDA
	${CP} -R ${WRKSRC}/ZPsycopgDA ${ZOPEBASEDIR}/${ZOPEPRODUCTDIR}/
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/doc/examples/${f} ${EXAMPLESDIR}
.endfor
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	@${INSTALL_MAN} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
.if !defined(BATCH) && defined(WITH_ZOPE)
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
