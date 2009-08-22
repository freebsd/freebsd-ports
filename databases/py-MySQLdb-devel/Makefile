# New ports collection makefile for:	py-MySQLdb
# Date created:				04 April 2000
# Whom:                 		Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MySQLdb
DISTVERSION=	1.2.3c1
CATEGORIES=	databases python
MASTER_SITES=	SF/mysql-python/mysql-python-test/1.2.3c1
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	-devel
DISTNAME=	MySQL-python-${DISTVERSION}

MAINTAINER=	mnag@FreeBSD.org
COMMENT=	Access a MySQL database through Python

USE_PYTHON=		2.3+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_PKGNAME=	MySQL_python
PYDISTUTILS_PKGVERSION=	${DISTVERSION}
USE_MYSQL=		yes

CONFLICTS=	py*-MySQLdb-[0-9]*

PORTDOCS=	*

OPTIONSFILE=	${PORT_DBDIR}/${PORTNAME}/options
OPTIONS=	MYSQLCLIENT_R "Use libmysqlclient_r (thread safe)" on

.include <bsd.port.pre.mk>

post-patch:
.if defined(WITHOUT_MYSQLCLIENT_R)
	@${REINPLACE_CMD} -E -e "s|(threadsafe.*)True|\1 False|" \
		${WRKSRC}/site.cfg
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
