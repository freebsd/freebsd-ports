PORTNAME=	mysql++
DISTVERSION=	3.3.0
CATEGORIES=	databases devel
MASTER_SITES=	https://tangentsoft.com/mysqlpp/releases/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ wrapper for the MySQL and MariaDB C APIs
WWW=		https://tangentsoft.com/mysqlpp

LICENSE=	LGPL21

USES=		gmake mysql
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

TEST_TARGET=	tests # unclear how to run tests

post-configure:
	@${RM} ${WRKSRC}/version

.include <bsd.port.mk>
