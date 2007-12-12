# Ports collection makefile for:  pgbouncer
# Date created:			  19 July 2007
# Whom:				  Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	pgbouncer
PORTVERSION=	1.1.2
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1532/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Lightweight connection pooler for PostgreSQL

LIB_DEPENDS=	event-1.3d:${PORTSDIR}/devel/libevent

USE_RC_SUBR=	pgbouncer.sh
SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if ! defined(NO_INSTALL_MANPAGES)
MAN1=		pgbouncer.1
MAN5=		pgbouncer.5
.endif

CONFIGURE_ARGS=	--with-libevent=${LOCALBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgbouncer ${PREFIX}/bin/
.if ! defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${WRKSRC}/doc/pgbouncer.1 ${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/pgbouncer.5 ${PREFIX}/man/man5/
.endif
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/pgbouncer.ini ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
