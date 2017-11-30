# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tel
PORTVERSION=	0.1.7.1
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}.berlios

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Little console-based phone book manager

LICENSE=	MIT

NO_ARCH=	yes

USES=		gettext python:2.7 shebangfix tar:bzip2
SHEBANG_FILES=	src/tel.py
USE_PYTHON=	distutils

post-patch:
	@${REINPLACE_CMD} -e \
		's|distutils\.command\.install |setuptools\.command\.install |' \
		${WRKSRC}/appdistutils.py
	@${REINPLACE_CMD} -e \
		's|$${install_messages}|${PREFIX}/share/locale| ; \
		 s|$${install_app_modules}|${PREFIX}/lib/tel| ; \
		 s|$${install_app_data}|${DATADIR}|' \
		${WRKSRC}/src/tel.py

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/bin -type l -delete
	@${LN} -sf ../lib/tel/tel.py ${STAGEDIR}${PREFIX}/bin/tel

.include <bsd.port.mk>
