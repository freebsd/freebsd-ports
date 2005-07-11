# New ports collection makefile for:	memcached
# Date created:		July 21, 2003
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	memcached
PORTVERSION=	1.1.12
CATEGORIES=	databases
MASTER_SITES=	http://www.danga.com/memcached/dist/

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	High-performance distributed memory object cache system

BUILD_DEPENDS+=	${LOCALBASE}/lib/libevent.a:${PORTSDIR}/devel/libevent

USE_REINPLACE=	YES
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--with-libevent=${LOCALBASE} --program-prefix=

MAN1=		memcached.1

DOCS_LIST=	memory_management.txt protocol.txt

USE_RC_SUBR=	yes

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g'	\
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

post-configure:
	@${REINPLACE_CMD} -e 's#doc/memcached.1##' ${WRKSRC}/Makefile

post-build:
	@${SED} ${SED_SCRIPT} ${FILESDIR}/memcached.sh >  ${WRKDIR}/memcached.sh

post-install:
	${INSTALL_MAN} ${MAN1:S!^!${WRKSRC}/doc/!} ${MAN1PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKDIR}/memcached.sh ${PREFIX}/etc/rc.d/memcached.sh
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS_LIST:S!^!${WRKSRC}/doc/!} ${DOCSDIR}
.endif

.include <bsd.port.mk>
