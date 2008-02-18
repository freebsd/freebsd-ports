# New ports collection makefile for:	mysqltcl
# Date created:				Thu Sep 28 16:07:00 CET 2006
# Whom:					Martin Matuska <martin@matuska.org>
#
# $FreeBSD$
#

PORTNAME=	mysqltcl
PORTVERSION=	3.04
CATEGORIES=	databases tcl83 tcl84
MASTER_SITES=	http://www.xdobry.de/mysqltcl/

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	TCL module for accessing MySQL databases based on msqltcl

USE_LDCONFIG=	yes
USE_MYSQL=	yes
USE_TCL=	yes
USE_TCL_BUILD=	yes

MANN=		mysqltcl.n

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ARGS+=	--with-tcl=${TCL_LIBDIR} \
			--with-mysql-include=${LOCALBASE}/include/mysql \
			--with-mysql-lib=${LOCALBASE}/lib/mysql \
			--exec-prefix=${PREFIX}

PLIST_SUB+=		LIB_DIR=${PORTNAME}-${PORTVERSION} \
			LIB_NAME=libmysqltcl${PORTVERSION}.so

pre-patch:
	@${REINPLACE_CMD} -e 's, *,,' ${WRKSRC}/generic/*.[ch]

post-install:
	@${TEST} ! -f ${PKGMESSAGE} || ${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

.if ${MYSQL_VER} == 323 || ${MYSQL_VER} == 40
PKGMESSAGE=	${PKGDIR}/pkg-message-legacy
.endif
