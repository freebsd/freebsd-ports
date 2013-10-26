# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	swift
PORTVERSION=	1.9.1
CATEGORIES=	databases python
MASTER_SITES=	http://launchpadlibrarian.net/147458777/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gslin@gslin.org
COMMENT=	Highly available, distributed, eventually consistent object/blob store

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PasteDeploy>0:${PORTSDIR}/www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}dnspython>=1.10.0:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0.9.8:${PORTSDIR}/net/py-eventlet \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0:${PORTSDIR}/net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.8:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}xattr>=0:${PORTSDIR}/devel/py-xattr \
		rsync>=3.0:${PORTSDIR}/net/rsync

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
USE_RC_SUBR=	swift

MAN1=		swift-account-auditor.1 \
		swift-account-reaper.1 \
		swift-account-replicator.1 \
		swift-account-server.1 \
		swift-container-auditor.1 \
		swift-container-replicator.1 \
		swift-container-server.1 \
		swift-container-sync.1 \
		swift-container-updater.1 \
		swift-dispersion-populate.1 \
		swift-dispersion-report.1 \
		swift-get-nodes.1 \
		swift-init.1 \
		swift-object-auditor.1 \
		swift-object-expirer.1 \
		swift-object-info.1 \
		swift-object-replicator.1 \
		swift-object-server.1 \
		swift-object-updater.1 \
		swift-orphans.1 \
		swift-proxy-server.1 \
		swift-recon.1 \
		swift-ring-builder.1

MAN5=		account-server.conf.5 \
		container-server.conf.5 \
		dispersion.conf.5 \
		object-expirer.conf.5 \
		object-server.conf.5 \
		proxy-server.conf.5

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|/etc/swift|${PREFIX}/etc/${PORTNAME}|" \
		${WRKSRC}/bin/swift-account-audit \
		${WRKSRC}/bin/swift-dispersion-populate \
		${WRKSRC}/bin/swift-dispersion-report \
		${WRKSRC}/bin/swift-get-nodes \
		${WRKSRC}/bin/swift-object-info \
		${WRKSRC}/bin/swift-recon \
		${WRKSRC}/bin/swift-recon-cron \
		${WRKSRC}/doc/manpages/account-server.conf.5 \
		${WRKSRC}/doc/manpages/container-server.conf.5 \
		${WRKSRC}/doc/manpages/dispersion.conf.5 \
		${WRKSRC}/doc/manpages/object-expirer.conf.5 \
		${WRKSRC}/doc/manpages/object-server.conf.5 \
		${WRKSRC}/doc/manpages/proxy-server.conf.5 \
		${WRKSRC}/doc/manpages/swift-dispersion-populate.1 \
		${WRKSRC}/doc/manpages/swift-dispersion-report.1 \
		${WRKSRC}/doc/manpages/swift-get-nodes.1 \
		${WRKSRC}/doc/manpages/swift-recon.1 \
		${WRKSRC}/etc/account-server.conf-sample \
		${WRKSRC}/etc/container-server.conf-sample \
		${WRKSRC}/etc/dispersion.conf-sample \
		${WRKSRC}/etc/object-expirer.conf-sample \
		${WRKSRC}/etc/object-server.conf-sample \
		${WRKSRC}/etc/proxy-server.conf-sample \
		${WRKSRC}/swift/account/reaper.py \
		${WRKSRC}/swift/common/constraints.py \
		${WRKSRC}/swift/common/db_replicator.py \
		${WRKSRC}/swift/common/manager.py \
		${WRKSRC}/swift/common/middleware/memcache.py \
		${WRKSRC}/swift/common/middleware/recon.py \
		${WRKSRC}/swift/common/middleware/staticweb.py \
		${WRKSRC}/swift/common/utils.py \
		${WRKSRC}/swift/container/sync.py \
		${WRKSRC}/swift/container/updater.py \
		${WRKSRC}/swift/obj/expirer.py \
		${WRKSRC}/swift/obj/replicator.py \
		${WRKSRC}/swift/obj/server.py \
		${WRKSRC}/swift/obj/updater.py \
		${WRKSRC}/swift/proxy/server.py \
		${WRKSRC}/test/__init__.py \
		${WRKSRC}/test/functional/tests.py \
		${WRKSRC}/test/probe/common.py \
		${WRKSRC}/test/probe/test_account_failures.py \
		${WRKSRC}/test/probe/test_container_failures.py \
		${WRKSRC}/test/probe/test_empty_device_handoff.py \
		${WRKSRC}/test/probe/test_object_async_update.py \
		${WRKSRC}/test/probe/test_object_failures.py \
		${WRKSRC}/test/probe/test_object_handoff.py \
		${WRKSRC}/test/sample.conf \
		${WRKSRC}/test/unit/common/middleware/test_memcache.py
	@${FIND} ${WRKSRC} -type f -name "*.bak" -delete

post-install:
	${MKDIR} ${PREFIX}/etc/${PORTNAME}
	${CP} -R ${WRKSRC}/etc/ ${PREFIX}/etc/${PORTNAME}
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/doc/manpages/${i} ${MANPREFIX}/man/man1/${i}
.endfor
.for i in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/doc/manpages/${i} ${MANPREFIX}/man/man5/${i}
.endfor

.include <bsd.port.mk>
