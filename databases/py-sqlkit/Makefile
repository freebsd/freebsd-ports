# Created by: bsam
# $FreeBSD$

PORTNAME=	sqlkit
PORTVERSION=	0.9.6.1
PORTREVISION=	1
CATEGORIES=	databases python
MASTER_SITES=	http://sqlkit.argolinux.org/download/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Standalone program to browse and edit data

LICENSE=	GPLv3

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlalchemy06>=0.5:${PORTSDIR}/databases/py-sqlalchemy06 \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}Babel>=0:${PORTSDIR}/devel/py-babel

USE_PYTHON=	distutils
USE_GNOME=	pygtk2
USES=		gettext python:2

OPTIONS_DEFINE=	MSSQL MYSQL PGSQL SQLITE SYBASE DOCS
OPTIONS_DEFAULT=MYSQL PGSQL SQLITE

SYBASE_DESC=	Sybase support

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}

post-patch:
	@${SED} -I.bak -e "s:/usr:${PREFIX}:" ${WRKSRC}/sqlkit.desktop

ALL_PORTDOCS=	*.html *.js
ALL_PORTDOCS_SUBDIR=	_images _static debug layout misc printing sqlkit

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMSSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}mssql>0:${PORTSDIR}/databases/py-mssql
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.2:${PORTSDIR}/databases/py-MySQLdb
.endif

.if ${PORT_OPTIONS:MPGSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.0.8:${PORTSDIR}/databases/py-psycopg2
.endif

.if ${PORT_OPTIONS:MSQLITE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3
.endif

.if ${PORT_OPTIONS:MSYBASE}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sybase>0:${PORTSDIR}/databases/py-sybase
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop ${STAGEDIR}${DESKTOPDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${ALL_PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/html/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in ${ALL_PORTDOCS_SUBDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/${i}
	cd ${WRKSRC}/doc/html/${i} && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/${i}
.endfor

.include <bsd.port.mk>
