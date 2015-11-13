# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	skytools
PORTVERSION=	3.2
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3622/

MAINTAINER=	sam@cassiba.com
COMMENT=	PostgreSQL tools from Skype: walshipping, queueing, replication

GNU_CONFIGURE=	yes
USES=		gmake python:2 shebangfix pgsql

SHEBANG_FILES=	setup_pkgloader.py setup_skytools.py \
		scripts/catsql.py scripts/data_maintainer.py \
		scripts/find_sql_functions.py scripts/grantfu.py \
		scripts/queue_loader.py scripts/queue_splitter.py \
		scripts/queue_mover.py scripts/scriptmgr.py \
		scripts/simple_consumer.py scripts/simple_local_consumer.py \
		scripts/skytools_upgrade.py

CONFIGURE_ARGS=	--with-python=${PYTHON_CMD} \
		--docdir=${EXAMPLESDIR} \
		--with-pgconfig=${LOCALBASE}/bin/pg_config

post-patch:
	@${REINPLACE_CMD} -e 's=share/doc=share/examples=' ${WRKSRC}/setup_skytools.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pgqd
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/skytools/*.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/*.so

.include <bsd.port.mk>
