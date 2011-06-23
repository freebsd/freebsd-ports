# Ports collection makefile for:	databases/py-sqlkit
# Date created:				2011-05-09
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	sqlkit
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://sqlkit.argolinux.org/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	A standalone program to browse and edit data

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy>=0.5:${PORTSDIR}/databases/py-sqlalchemy06 \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}Babel>=0:${PORTSDIR}/devel/py-babel

LICENSE=	GPLv3

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_GNOME=	pygtk2 desktopfileutils
USE_GETTEXT=	yes

OPTIONS=	FIREBIRD "support FireBird" off
OPTIONS+=	MSSQL "support MS SQL Server" off
OPTIONS+=	MYSQL "support MySql" on
OPTIONS+=	POSTGRE "support PostGreSQL" on
OPTIONS+=	SQLITE "support Sqlite" on
OPTIONS+=	SYBASE "support Sybase" off

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-patch:
	@${SED} -I.bak -e "s:/usr:${PREFIX}:" ${WRKSRC}/sqlkit.desktop

.if !defined(NOPORTDOCS)
ALL_PORTDOCS=	*.html *.js
ALL_PORTDOCS_SUBDIR=	_images _static debug layout misc printing sqlkit
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_FIREBIRD)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/kinterbasdb/__init__.py:${PORTSDIR}/databases/kinterbasdb
.endif

.if defined(WITH_MSSQL)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pymssql.py:${PORTSDIR}/databases/py-mssql
.endif

.if !defined(WITHOUT_MYSQL)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
.endif

.if !defined(WITHOUT_POSTGRE)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.0.8:${PORTSDIR}/databases/py-psycopg2
.endif

.if !defined(WITHOUT_SQLITE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3
.endif

.if !defined(WITHOUT_SYBASE)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/Sybase.py:${PORTSDIR}/databases/py-sybase
.endif

post-install:
	@${MKDIR} ${DESKTOPDIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${DESKTOPDIR}
	@-update-desktop-database > /dev/null

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${ALL_PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/doc/html/${i} ${DOCSDIR}
.endfor
.for i in ${ALL_PORTDOCS_SUBDIR}
	@${MKDIR} ${DOCSDIR}/${i}
	@cd ${WRKSRC}/doc/html/${i} && ${COPYTREE_SHARE} . ${DOCSDIR}/${i}
.endfor
.endif

.include <bsd.port.post.mk>
