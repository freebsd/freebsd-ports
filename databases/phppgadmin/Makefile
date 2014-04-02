# Created by: nbm
# $FreeBSD$

PORTNAME=	phppgadmin
PORTVERSION=	5.1
CATEGORIES=	databases www
MASTER_SITES=	SF/${PORTNAME}/phpPgAdmin%20%5Bstable%5D/phpPgAdmin-5.1
DISTNAME=	phpPgAdmin-${PORTVERSION}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Web Based Postgres Administration

LICENSE=	GPLv2

USES=		tar:bzip2
.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	pgsql pcre session
.endif
NO_BUILD=	YES
PGADMDIR?=	www/phpPgAdmin
PLIST_SUB+=	PGADMDIR=${PGADMDIR}
PGADMOLDDIR?=	www/data-dist/phpPgAdmin
PLIST_SUB+=	PGADMOLDDIR=${PGADMOLDDIR}

pre-everything::
	@${ECHO_CMD} "# you can customize the installation directory"
	@${ECHO_CMD} "# by setting PGADMDIR in /etc/make.conf"

do-configure:
	${REINPLACE_CMD} -e "s|/usr/bin/pg|${LOCALBASE}/bin/pg|" \
		${WRKSRC}/conf/config.inc.php-dist
	${RM} -f ${WRKSRC}/conf/config.inc.php \
		${WRKSRC}/conf/config.inc.php-dist.bak

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${PGADMDIR}
	${CP} -Rp ${WRKSRC}/ ${STAGEDIR}${PREFIX}/${PGADMDIR}/

.include <bsd.port.mk>
