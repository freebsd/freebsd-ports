# New ports collection makefile for:	ldmud
# Date created:		13 August 2003
# Whom:			glewis@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ldmud
PORTVERSION=	3.3.720
PORTEPOCH=	1
CATEGORIES=	games net
MASTER_SITES=	http://www.bearnip.com/ftp/mud/ \
		ftp://mud.stack.nl/pub/ldmud/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A modern version of the LPMud game driver

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_ICONV=	yes
CONFIGURE_ARGS+=--libdir=${DATADIR} \
		--bindir=${PREFIX}/sbin \
		--enable-use-pcre \
		--enable-use-tls=ssl
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
ALL_TARGET=	ldmud
MAN1=		ldmud.1
USE_RC_SUBR=	ldmud
SUB_LIST+=	LDUSER=${USERS}
MAKE_JOBS_UNSAFE=	yes

USERS=		mud
GROUPS=		mud

OPTIONS=	MYSQL "Enable MySQL database support" On \
		PGSQL "Enable PostgreSQL database support" On \
		SQLITE "Enable SQLite database support" On \
		IPV6  "Enable IPv6 support" On \
		LPMUD "Install default mudlib (LP-245)" On

PORTSCOUT=	skipv:3.4

.include <bsd.port.options.mk>

.ifdef	WITH_IPV6
CONFIGURE_ARGS+=--enable-use-ipv6
.else
CONFIGURE_ARGS+=--disable-use-ipv6
.endif

.ifdef	WITH_MYSQL
USE_MYSQL=	yes
LDFLAGS+=	-L${LOCALBASE}/lib/mysql
CONFIGURE_ARGS+=--enable-use-mysql
.else
CONFIGURE_ARGS+=--disable-use-mysql
.endif

.ifdef	WITH_PGSQL
USE_PGSQL=	yes
CONFIGURE_ARGS+=--enable-use-pgsql
.else
CONFIGURE_ARGS+=--disable-use-pgsql
.endif

.ifdef	WITH_SQLITE
USE_SQLITE=	yes
CONFIGURE_ARGS+=--enable-use-sqlite
.else
CONFIGURE_ARGS+=--disable-use-sqlite
.endif

.ifdef	WITH_LPMUD
PLIST_SUB+=	LPMUD="" DEMOLIB="@comment "
.else
PLIST_SUB+=	LPMUD="@comment " DEMOLIB=""
.endif

.include <bsd.port.pre.mk>

post-install:
#	# Install mudlib and other directories
	@${MKDIR} ${DATADIR} /var/log/${PORTNAME} /var/run/${PORTNAME}
	@${CHOWN} ${USERS}:${GROUPS} /var/log/${PORTNAME} /var/run/${PORTNAME}
.ifdef WITH_LPMUD
	@cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mud/lp-245 && ${FIND} . \
		| ${CPIO} -pdmu -R ${USERS}:${GROUPS} ${DATADIR}
.else
	@cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/mudlib && ${FIND} . \
		| ${CPIO} -pdmu -R ${USERS}:${GROUPS} ${DATADIR}
.endif
.ifndef	NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/${PORTNAME}-${PORTVERSION}/doc && ${FIND} . \
		| ${CPIO} -pdmu -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	@${RM} -f ${DOCSDIR}/Makefile
.endif

.include <bsd.port.post.mk>
