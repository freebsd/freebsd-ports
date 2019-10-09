# Created by: nbm
# $FreeBSD$

PORTNAME=	phppgadmin
DISTVERSIONPREFIX=	REL_
DISTVERSION=	7-12-0
PORTREVISION=	1
CATEGORIES=	databases www
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Web Based Postgres Administration

LICENSE=	GPLv2

NO_ARCH=	yes
NO_BUILD=	yes
USES=		cpe tar:bzip2 php:web,flavors shebangfix
USE_GITHUB=	yes

.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	pgsql pcre session
.endif

CPE_VENDOR=	phppgadmin_project
SHEBANG_FILES=	lang/synch
PGADMDIR?=	www/phpPgAdmin
PLIST_SUB+=	PGADMDIR=${PGADMDIR}

pre-everything::
	@${ECHO_CMD} "# you can customize the installation directory"
	@${ECHO_CMD} "# by setting PGADMDIR in /etc/make.conf"

do-configure:
	${REINPLACE_CMD} -e "s|/usr/bin/pg|${LOCALBASE}/bin/pg|" \
		${WRKSRC}/conf/config.inc.php-dist
	${RM} ${WRKSRC}/conf/config.inc.php \
		${WRKSRC}/conf/config.inc.php-dist.bak

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PGADMDIR}
	${CP} -Rp ${WRKSRC}/ ${STAGEDIR}${PREFIX}/${PGADMDIR}/

.include <bsd.port.mk>
