PORTNAME=	odoo
PORTVERSION=	13.0
PORTREVISION=	2
CATEGORIES=	finance www
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Suite of web based open source business apps

LICENSE=	LGPL3

USE_GITHUB=	yes
GH_TAGNAME=	0b6a2569920b6584652c39b3465998649fe305b4

LIB_DEPENDS=	libxml2.so:textproc/libxml2 \
		libxslt.so:textproc/libxslt \
		libevent.so:devel/libevent \
		libsasl2.so:security/cyrus-sasl2
RUN_DEPENDS=	wkhtmltopdf>0:converters/wkhtmltopdf \
		${PYTHON_PKGNAMEPREFIX}psycopg2>0:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyserial>=0:comms/py-pyserial@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>=0:deskutils/py-vobject@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Babel>=1.3:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gevent>=0:devel/py-gevent@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0:devel/py-greenlet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mako>=0:textproc/py-mako@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}num2words>=0:devel/py-num2words@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}polib>=0:devel/py-polib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyusb>=0:devel/py-pyusb@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vatnumber>=0:finance/py-vatnumber@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pydot>=0:graphics/py-pydot@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ldap>=0:net/py-ldap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zeep>=0:net/py-zeep@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>=0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=0:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}html2text>=0:textproc/py-html2text@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markupsafe>=0:textproc/py-markupsafe@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=0:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=0:textproc/py-xlrd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlwt>=0:textproc/py-xlwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>=0:textproc/py-xlsxwriter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}decorator>0:devel/py-decorator@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pdf2>0:print/py-pdf2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>0:print/py-reportlab@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}libsass>0:www/py-libsass@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}werkzeug>0:www/py-werkzeug@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}secure-cookie>0:www/py-secure-cookie@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}XlsxWriter>=0:textproc/py-xlsxwriter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlrd>=1.2.0:textproc/py-xlrd@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xlwt>=1.3.0:textproc/py-xlwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ofxparse>=0.20:finance/py-ofxparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ebaysdk>=2.1.3:finance/py-ebaysdk@${PY_FLAVOR}

USES=		python:3.5+ pgsql shebangfix
USE_PYTHON=	distutils
USE_OPENLDAP=	yes

SHEBANG_LANG=	python
SHEBANG_FILES=  ${WRKSRC}/${PORTNAME}-bin

USERS=		odoo
GROUPS=         ${USERS}

USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message

ETCDIR=		${PREFIX}/etc/odoo

post-patch:
	@${REINPLACE_CMD} -i "" -e '25d' ${WRKSRC}/odoo/service/wsgi_server.py
	@${REINPLACE_CMD} -i "" -e 's|werkzeug.url_quote_plus|werkzeug.urls.url_quote_plus|g' \
		${WRKSRC}/odoo/addons/base/models/ir_ui_view.py 
	@${REINPLACE_CMD} -i "" -e 's|werkzeug.url_unquote_plus|werkzeug.urls.url_quote_plus|g' \
		${WRKSRC}/odoo/addons/base/models/ir_http.py \
		${WRKSRC}/odoo/addons/http_routing/models/ir_http.py
	@${REINPLACE_CMD} -i "" -e 's|from werkzeug import url_encode|from werkzeug.urls import url_encode|g' \
		${WRKSRC}/odoo/addons/mail/models/mail_thread.py \
		${WRKSRC}/odoo/addons/mail/controllers/main.py \
		${WRKSRC}/odoo/addons/hr/models/hr_employee.py \
		${WRKSRC}/odoo/addons/hr_expense/wizard/hr_expense_sheet_register_payment.py
	@${REINPLACE_CMD} -i "" -e 's|werkzeug|werkzeug.urls|g' \
		${WRKSRC}/odoo/addons/web_editor/models/ir_attachment.py \
		${WRKSRC}/odoo/addons/odoo_referral/models/res_users.py

post-extract:
	@cd ${WRKSRC}/addons/ && ${MV} * ${WRKSRC}/odoo/addons/

pre-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}

post-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/odoo.conf ${STAGEDIR}${ETCDIR}/odoo.conf.sample

.include <bsd.port.mk>
