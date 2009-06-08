# Ports collection makefile for:  skytools
# Date created:    27 July 2007
# Whom:            Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	skytools
PORTVERSION=	2.1.7
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/1813/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	PostgreSQL tools from Skype: walshipping, queueing, replication

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

USE_PGSQL=	yes
USE_PYTHON=	2.4+
INSTALLS_EGGINFO=	yes

MAN1=	bulk_loader.1 cube_dispatcher.1 londiste.1 pgqadm.1 queue_mover.1 \
	queue_splitter.1 scriptmgr.1 skytools_upgrade.1 table_dispatcher.1 \
	walmgr.1
MAN5=	londiste.5

CONFIGURE_ARGS=	--with-python=${PYTHON_CMD} \
		--docdir=${EXAMPLESDIR} \
		--with-pgconfig=${LOCALBASE}/bin/pg_config

post-patch:
	@${REINPLACE_CMD} -e 's=share/doc=share/examples=' ${WRKSRC}/setup.py

.include <bsd.port.mk>
