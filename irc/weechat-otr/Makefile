PORTNAME=	weechat-otr
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.2
CATEGORIES=	irc security python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	WeeChat script for Off-the-Record (OTR) messaging
WWW=		https://github.com/mmb/weechat-otr

LICENSE=	GPLv3

DEPRECATED=	Depends on expired security/py-pycrypto (via security/py-potr)
EXPIRATION_DATE=2022-12-31

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}potr>=1.0.1:security/py-potr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}potr>=1.0.1:security/py-potr@${PY_FLAVOR} \
		weechat:irc/weechat

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	mmb

NO_BUILD=	yes

PLIST_FILES=	${PYTHON_SITELIBDIR}/weechat/weechat_otr.py

do-install:
	${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/weechat
	${INSTALL_DATA} ${WRKSRC}/weechat_otr.py \
		${STAGEDIR}${PYTHON_SITELIBDIR}/weechat/weechat_otr.py

.include <bsd.port.mk>
