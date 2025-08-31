PORTNAME=	odoo
PORTVERSION=	18.0.20250719
PORTREVISION=	1
CATEGORIES=	finance www
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Suite of web based open source business apps
WWW=		https://www.odoo.com

LICENSE=	LGPL3

USE_GITHUB=	yes
GH_TAGNAME=	b284046d535c99a33cb0c4ec6a15e7536053ce0c

LIB_DEPENDS=	libxslt.so:textproc/libxslt \
		libevent.so:devel/libevent \
		libsasl2.so:security/cyrus-sasl2
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}Babel>=1.3:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}GeoIP2>0:net/py-GeoIP2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>=0:textproc/py-xlsxwriter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}asn1crypto>=0:devel/py-asn1crypto@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cbor2>0:devel/py-cbor2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}freezegun>0:devel/py-freezegun@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text>=0:textproc/py-html2text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}idna>0:dns/py-idna@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libsass>0:www/py-libsass@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml-html-clean>=0:devel/py-lxml-html-clean@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml5>=0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}num2words>=0:devel/py-num2words@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ofxparse>=0.20:finance/py-ofxparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openssl>0:security/py-openssl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdfminer.six>0:textproc/py-pdfminer.six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polib>=0:devel/py-polib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydot>=0:graphics/py-pydot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pypdf>0:print/py-pypdf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=0:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ldap>=0:net/py-python-ldap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyusb>=0:devel/py-pyusb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=0:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rjsmin>0:archivers/py-rjsmin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stdnum>0:devel/py-stdnum@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>=0:deskutils/py-vobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=1.2.0:textproc/py-xlrd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlwt>=1.3.0:textproc/py-xlwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zeep>=0:net/py-zeep@${PY_FLAVOR}

USES=		cpe gnome ldap python pgsql shebangfix
USE_GNOME=	libxml2
USE_PYTHON=	cryptography distutils

SHEBANG_LANG=	python
SHEBANG_FILES=	${WRKSRC}/${PORTNAME}/addons/web/tooling/*.sh \
		${WRKSRC}/${PORTNAME}/addons/web/tooling/hooks/pre-commit \
		${WRKSRC}/${PORTNAME}/addons/mail/static/scripts/odoo-mailgate.py \
		${WRKSRC}/${PORTNAME}-bin

USERS=		odoo
GROUPS=		${USERS}

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

CONFLICTS=	odoo16 odoo17

ETCDIR=		${PREFIX}/etc/odoo

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 31000
IGNORE=		odoo requires Python 3.10+
.endif

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|(index !== |(index == |g' \
		${WRKSRC}/odoo/addons/web/static/src/core/network/download.js

post-extract:
	@cd ${WRKSRC}/addons/ && ${MV} * ${WRKSRC}/odoo/addons/

pre-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/odoo.conf ${STAGEDIR}${ETCDIR}/odoo.conf.sample

.include <bsd.port.post.mk>
