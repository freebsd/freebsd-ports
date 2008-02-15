# New ports collection makefile for:	memcachedb
# Date created:		2007-09-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	memcachedb
DISTVERSION=	1.0.0-beta
CATEGORIES=	databases
MASTER_SITES=	http://memcachedb.googlecode.com/files/	\
		http://freebsd.csie.nctu.edu.tw/~gslin/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Distributed storage system designed for persistent

LIB_DEPENDS=	event-1.3e:${PORTSDIR}/devel/libevent

CFLAGS=		-I"${BDB_INCLUDE_DIR}"
CONFIUGRE_ARGS=	--enable-threads --with-bdb="${LOCALBASE}" \
		--with-libevent="${LOCALBASE}"
CONFIGURE_ENV=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
GNU_CONFIGURE=	yes
LDFLAGS=	-l"${BDB_LIB_NAME}" -L"${LOCALBASE}/lib"
MCDBDIR?=	/var/db/memcachedb
USE_BDB=	46+
USE_RC_SUBR=	${PORTNAME}

post-patch:
	${CHMOD} a+x ${WRKSRC}/install-sh

post-install:
	${MKDIR} ${MCDBDIR} || ${TRUE}
	${CHOWN} nobody:nobody ${MCDBDIR}

.include <bsd.port.mk>
