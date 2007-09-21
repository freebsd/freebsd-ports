# Ports collection makefile for:  pgbouncer
# Date created:			  19 July 2007
# Whom:				  Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	pgbouncer
PORTVERSION=	1.0.8
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1399/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Lightweight connection pooler for PostgreSQL

LIB_DEPENDS=	event-1.3d:${PORTSDIR}/devel/libevent

USE_RC_SUBR=	pgbouncer.sh
SUB_FILES=	pkg-message

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-libevent=${LOCALBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pgbouncer ${PREFIX}/bin/
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/pgbouncer.ini ${EXAMPLESDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
