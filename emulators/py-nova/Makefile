# Created by: Alexander Nusov <alexander.nusov@nfvexpress.com>
# $FreeBSD$

PORTNAME=	nova
PORTVERSION=	14.0.3
CATEGORIES=	emulators python
MASTER_SITES=	https://fossies.org/linux/misc/openstack/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	alexander.nusov@nfvexpress.com
COMMENT=	OpenStack compute service

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=1.6:devel/py-pbr

RUN_DEPENDS:=	${BUILD_DEPENDS}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}sqlalchemy10>=0:databases/py-sqlalchemy10 \
		${PYTHON_PKGNAMEPREFIX}boto>=2.32.1:devel/py-boto \
		${PYTHON_PKGNAMEPREFIX}decorator>=3.4.0:devel/py-decorator \
		${PYTHON_PKGNAMEPREFIX}eventlet>=0:net/py-eventlet \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.8:devel/py-Jinja2 \
		${PYTHON_PKGNAMEPREFIX}keystonemiddleware>=0:devel/py-keystonemiddleware \
		${PYTHON_PKGNAMEPREFIX}lxml>=2.3:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}routes>=0:www/py-routes \
		${PYTHON_PKGNAMEPREFIX}cryptography>=0:security/py-cryptography \
		${PYTHON_PKGNAMEPREFIX}webob>=1.2.3:www/py-webob \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0.3.2:devel/py-greenlet \
		${PYTHON_PKGNAMEPREFIX}PasteDeploy>=1.5.0:www/py-pastedeploy \
		${PYTHON_PKGNAMEPREFIX}Paste>=0:www/py-paste \
		${PYTHON_PKGNAMEPREFIX}prettytable>=0:devel/py-prettytable \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy-migrate>=0.9.6:databases/py-sqlalchemy-migrate \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0:net/py-netaddr \
		${PYTHON_PKGNAMEPREFIX}netifaces>=0.10.4:net/py-netifaces \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.0:security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.3.4:devel/py-babel \
		${PYTHON_PKGNAMEPREFIX}iso8601>=0.1.11:devel/py-iso8601 \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=0:devel/py-jsonschema \
		${PYTHON_PKGNAMEPREFIX}python-cinderclient>=0:net/py-python-cinderclient \
		${PYTHON_PKGNAMEPREFIX}keystoneauth1>=2.10.0:devel/py-keystoneauth1 \
		${PYTHON_PKGNAMEPREFIX}python-neutronclient>=5.1.0:net/py-python-neutronclient \
		${PYTHON_PKGNAMEPREFIX}python-glanceclient>=0:net/py-python-glanceclient \
		${PYTHON_PKGNAMEPREFIX}requests>=2.10.0:www/py-requests \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}stevedore>=1.16.0:devel/py-stevedore \
		${PYTHON_PKGNAMEPREFIX}websockify>=0.8.0:devel/py-websockify \
		${PYTHON_PKGNAMEPREFIX}oslo.cache>=1.5.0:devel/py-oslo.cache \
		${PYTHON_PKGNAMEPREFIX}oslo.concurrency>=3.8.0:devel/py-oslo.concurrency \
		${PYTHON_PKGNAMEPREFIX}oslo.config>=3.14.0:devel/py-oslo.config \
		${PYTHON_PKGNAMEPREFIX}oslo.context>=2.9.0:devel/py-oslo.context \
		${PYTHON_PKGNAMEPREFIX}oslo.log>=1.14.0:devel/py-oslo.log \
		${PYTHON_PKGNAMEPREFIX}oslo.reports>=0.6.0:devel/py-oslo.reports \
		${PYTHON_PKGNAMEPREFIX}oslo.serialization>=1.10.0:devel/py-oslo.serialization \
		${PYTHON_PKGNAMEPREFIX}oslo.utils>=3.16.0:devel/py-oslo.utils \
		${PYTHON_PKGNAMEPREFIX}oslo.db>=0:devel/py-oslo.db \
		${PYTHON_PKGNAMEPREFIX}oslo.rootwrap>=5.0.0:devel/py-oslo.rootwrap \
		${PYTHON_PKGNAMEPREFIX}oslo.messaging>=5.2.0:devel/py-oslo.messaging \
		${PYTHON_PKGNAMEPREFIX}oslo.policy>=1.9.0:devel/py-oslo.policy \
		${PYTHON_PKGNAMEPREFIX}oslo.privsep>=1.9.0:devel/py-oslo.privsep \
		${PYTHON_PKGNAMEPREFIX}oslo.i18n>=2.1.0:devel/py-oslo.i18n \
		${PYTHON_PKGNAMEPREFIX}oslo.service>=1.10.0:devel/py-oslo.service \
		${PYTHON_PKGNAMEPREFIX}rfc3986>=0.2.2:www/py-rfc3986 \
		${PYTHON_PKGNAMEPREFIX}oslo.middleware>=3.0.0:devel/py-oslo.middleware \
		${PYTHON_PKGNAMEPREFIX}psutil121>=0:sysutils/py-psutil121 \
		${PYTHON_PKGNAMEPREFIX}oslo.versionedobjects>=1.13.0:devel/py-oslo.versionedobjects \
		${PYTHON_PKGNAMEPREFIX}os-brick>=1.6.1:devel/py-os-brick \
		${PYTHON_PKGNAMEPREFIX}os-vif>=1.1.0:devel/py-os-vif \
		${PYTHON_PKGNAMEPREFIX}os-win>=0.2.3:devel/py-os-win \
		${PYTHON_PKGNAMEPREFIX}castellan>=0.4.0:devel/py-castellan \
		${PYTHON_PKGNAMEPREFIX}microversion-parse>=0.1.2:devel/py-microversion-parse \
		${PYTHON_PKGNAMEPREFIX}wsgi_intercept>=0.6.1:devel/py-wsgi_intercept \
		${PYTHON_PKGNAMEPREFIX}sqlparse>=0:databases/py-sqlparse \
		${PYTHON_PKGNAMEPREFIX}libvirt>=0:devel/py-libvirt \
		e2fsprogs>=0:sysutils/e2fsprogs \
		arping>=0:net/arping

EXTRA_PATCHES=	${FILESDIR}/01-firewall-manager.patch:-p1 \
		${FILESDIR}/02-freebsd-l3.patch:-p1 \
		${FILESDIR}/03-nova-conf.patch:-p1 \
		${FILESDIR}/04-xen-phy.patch:-p1 \
		${FILESDIR}/05-online-cpus.patch:-p1 \
		${FILESDIR}/06-freebsd-net.patch:-p1 \
		${FILESDIR}/07-fix-xen-xvd.patch:-p1

ONLY_FOR_ARCHS=	amd64

USES=		python
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

.if ${OSVERSION} < 1100055
IGNORE=		only supported on recent FreeBSD 11
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
