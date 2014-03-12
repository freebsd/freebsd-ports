# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	swift
PORTVERSION=	1.13.0
CATEGORIES=	databases python
MASTER_SITES=	http://launchpadlibrarian.net/168204360/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gslin@gslin.org
COMMENT=	Highly available, distributed, eventually consistent object/blob store

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=0.5.21:${PORTSDIR}/devel/py-pbr

RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}PasteDeploy>0:${PORTSDIR}/www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}dnspython>=1.10.0:${PORTSDIR}/dns/py-dnspython \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0.9.8:${PORTSDIR}/net/py-eventlet \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0:${PORTSDIR}/net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}swiftclient>=0:${PORTSDIR}/databases/py-swiftclient \
		${PYTHON_PKGNAMEPREFIX}simplejson>=0:${PORTSDIR}/devel/py-simplejson \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}webob>=0.9.8:${PORTSDIR}/www/py-webob \
		${PYTHON_PKGNAMEPREFIX}xattr>=0:${PORTSDIR}/devel/py-xattr \
		memcached>=0:${PORTSDIR}/databases/memcached \
		rsync>=3.0:${PORTSDIR}/net/rsync

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes
USE_RC_SUBR=	swift
USERS=		swift
GROUPS=		swift

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
	    ${WRKSRC}/swift/common/middleware/account_quotas.py \
	    ${WRKSRC}/swift/common/middleware/container_sync.py \
	    ${WRKSRC}/swift/common/middleware/gatekeeper.py \
	    ${WRKSRC}/swift/common/middleware/list_endpoints.py \
	    ${WRKSRC}/swift/common/middleware/memcache.py \
	    ${WRKSRC}/swift/common/middleware/recon.py \
	    ${WRKSRC}/swift/common/middleware/staticweb.py \
	    ${WRKSRC}/swift/common/utils.py \
	    ${WRKSRC}/swift/container/server.py \
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
	    ${WRKSRC}/test/sample.conf \
	    ${WRKSRC}/test/unit/common/middleware/test_memcache.py
	@${FIND} ${WRKSRC} -type f -name "*.bak" -delete

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${CP} -R ${WRKSRC}/etc/ ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
.for n in 1 5
	${INSTALL_MAN} ${WRKSRC}/doc/manpages/*.${n} \
	    ${STAGEDIR}${MANPREFIX}/man/man${n}
.endfor

.include <bsd.port.mk>
