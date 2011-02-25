# Ports collection makefile for:  skytools
# Date created:    27 July 2007
# Whom:            Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	skytools
PORTVERSION=	2.1.12
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/2872/

MAINTAINER=	kheechin@gmail.com
COMMENT=	PostgreSQL tools from Skype: walshipping, queueing, replication

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

USE_PGSQL=	yes
USE_PYTHON=	2.5+
INSTALLS_EGGINFO=	yes

MAN1=	bulk_loader.1 cube_dispatcher.1 londiste.1 pgqadm.1 queue_mover.1 \
	queue_splitter.1 scriptmgr.1 skytools_upgrade.1 table_dispatcher.1 \
	walmgr.1
MAN5=	londiste.5

CONFIGURE_ARGS=	--with-python=${PYTHON_CMD} \
		--docdir=${EXAMPLESDIR} \
		--with-pgconfig=${LOCALBASE}/bin/pg_config

.include <bsd.port.pre.mk>

# Setting/finding PostgreSQL version we want.
.if exists(${LOCALBASE}/bin/postmaster)
PGSQL_VER!=	${LOCALBASE}/bin/postmaster -V | \
		${SED} -En 's/.*PostgreSQL[^0-9]*([0-9]+)\.([0-9]+)\..*/\1\2/p'
.elif exists(${LOCALBASE}/bin/pg_config)
PGSQL_VER!=	${LOCALBASE}/bin/pg_config --version | \
		${SED} -En 's/PostgreSQL[^0-9]*([0-9]*)\.([0-9]+)\..*/\1\2/p'
.else
PGSQL_VER=	${DEFAULT_PGSQL_VER}
.endif

.if ${PGSQL_VER} > 82
PLIST_SUB+=	TXID="@comment "
.else
PLIST_SUB+=	TXID=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's=share/doc=share/examples=' ${WRKSRC}/setup.py

.include <bsd.port.post.mk>
