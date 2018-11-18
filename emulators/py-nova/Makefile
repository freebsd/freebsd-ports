# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	nova
PORTVERSION=	14.0.3
PORTREVISION=	2
CATEGORIES=	emulators python
MASTER_SITES=	https://fossies.org/linux/misc/openstack/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack compute service

LICENSE=	APACHE20

BROKEN=		depends on conflicting dependencies
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-12-19

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr@${PY_FLAVOR}

RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0:databases/py-sqlalchemy10@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}boto>=2.32.1:devel/py-boto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0:net/py-eventlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.8:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystonemiddleware>=0:devel/py-keystonemiddleware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.3:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}routes>=0:www/py-routes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.3:www/py-webob@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0.3.2:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:www/py-pastedeploy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Paste>=0:www/py-paste@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0:devel/py-prettytable@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.9.6:databases/py-sqlalchemy-migrate@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.4:net/py-netifaces@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.0:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-cinderclient>=0:net/py-python-cinderclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.10.0:devel/py-keystoneauth1@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-neutronclient>=5.1.0:net/py-python-neutronclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-glanceclient>=0:net/py-python-glanceclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.16.0:devel/py-stevedore@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}websockify>=0.8.0:devel/py-websockify@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.cache>=1.5.0:devel/py-oslo.cache@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.8.0:devel/py-oslo.concurrency@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.9.0:devel/py-oslo.context@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=1.14.0:devel/py-oslo.log@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.reports>=0.6.0:devel/py-oslo.reports@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.db>=0:devel/py-oslo.db@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.rootwrap>=5.0.0:devel/py-oslo.rootwrap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.2.0:devel/py-oslo.messaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.9.0:devel/py-oslo.policy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.privsep>=1.9.0:devel/py-oslo.privsep@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.service>=1.10.0:devel/py-oslo.service@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=0.2.2:www/py-rfc3986@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware>=3.0.0:devel/py-oslo.middleware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil121>=0:sysutils/py-psutil121@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}oslo.versionedobjects>=1.13.0:devel/py-oslo.versionedobjects@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}os-brick>=1.6.1:devel/py-os-brick@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}os-vif>=1.1.0:devel/py-os-vif@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}os-win>=0.2.3:devel/py-os-win@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}castellan>=0.4.0:devel/py-castellan@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}microversion-parse>=0.1.2:devel/py-microversion-parse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wsgi_intercept>=0.6.1:devel/py-wsgi_intercept@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0:databases/py-sqlparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libvirt>=0:devel/py-libvirt@${PY_FLAVOR} \
		e2fsprogs>=0:sysutils/e2fsprogs \
		arping>=0:net/arping \
		bash:shells/bash

EXTRA_PATCHES=	${FILESDIR}/01-firewall-manager.patch:-p1 \
		${FILESDIR}/02-freebsd-l3.patch:-p1 \
		${FILESDIR}/03-nova-conf.patch:-p1 \
		${FILESDIR}/04-xen-phy.patch:-p1 \
		${FILESDIR}/05-online-cpus.patch:-p1 \
		${FILESDIR}/06-freebsd-net.patch:-p1 \
		${FILESDIR}/07-fix-xen-xvd.patch:-p1 \
		${FILESDIR}/08-fix-floating-ips.patch:-p1 \
		${FILESDIR}/09-fix-xen-console.patch:-p1

ONLY_FOR_ARCHS=	amd64

USES=		python shebangfix
SHEBANG_FILES=	nova/tests/live_migration/hooks/*.sh \
		nova/CA/*.sh nova/cloudpipe/bootscript.template
USE_PYTHON=	autoplist distutils noegginfo

USE_RC_SUBR=	nova-api \
		nova-consoleauth \
		nova-conductor \
		nova-scheduler \
		nova-network \
		nova-compute \
		nova-cert \
		nova-cells \
		nova-serialproxy \
		nova-novncproxy
USERS=		nova
GROUPS=		nova

.include <bsd.port.options.mk>

.if ${OPSYS} != FreeBSD
IGNORE=		only supported on FreeBSD
.endif

post-extract:
	@(cd ${WRKSRC}/etc/nova; ${MV} logging_sample.conf logging.conf.sample)
	@(cd ${WRKSRC}/etc/nova; for f in *.conf; do ${MV} $${f} $${f}.sample; done)

post-patch:
	${CP} ${FILESDIR}/nova.conf.sample \
		${WRKSRC}/etc/nova/nova.conf.sample
	${CP} ${FILESDIR}/nova-compute.conf.sample \
		${WRKSRC}/etc/nova/nova-compute.conf.sample
	${REINPLACE_CMD} -e "s|/etc|${PREFIX}/etc|g" \
		${WRKSRC}/nova/api/openstack/placement/wsgi.py \
		${WRKSRC}/nova/conf/base.py \
		${WRKSRC}/nova/conf/cloudpipe.py \
		${WRKSRC}/nova/conf/network.py \
		${WRKSRC}/nova/conf/remote_debug.py \
		${WRKSRC}/nova/conf/xvp.py \
		${WRKSRC}/nova/hacking/checks.py \
		${WRKSRC}/nova/network/linux_net.py \
		${WRKSRC}/nova/network/manager.py \
		${WRKSRC}/nova/virt/disk/api.py \
		${WRKSRC}/nova/virt/disk/vfs/guestfs.py \
		${WRKSRC}/nova/virt/libvirt/driver.py \
		${WRKSRC}/nova/virt/xenapi/agent.py \
		${WRKSRC}/nova/wsgi/nova-api.py \
		${WRKSRC}/nova/wsgi/nova-metadata.py

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${CP} -R ${WRKSRC}/etc/nova/ ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
