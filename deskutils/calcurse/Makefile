# Created by: Herbert J. Skuhra <h.skuhra@gmail.com>
# $FreeBSD$

PORTNAME=	calcurse
PORTVERSION=	4.5.1
CATEGORIES=	deskutils
MASTER_SITES=	https://calcurse.org/files/

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Text-based calendar and scheduling application

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	CALDAV DOCS NLS
OPTIONS_DEFAULT=CALDAV
OPTIONS_SUB=	yes

USES=		gmake ncurses shebangfix
SHEBANG_FILES=	contrib/caldav/calcurse-caldav \
		contrib/caldav/calcurse-caldav.py \
		contrib/vdir/calcurse-vdir \
		contrib/vdir/calcurse-vdir.py
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-asciidoc

DOCS_CONFIGURE_ENABLE=	docs
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext

CALDAV_DESC=		Support Calendaring Extensions to WebDAV
CALDAV_USES=		python:3.4+
CALDAV_USES_OFF=	python:3.4+,env
CALDAV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httplib2>=0:www/py-httplib2@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}oauth2client>=0:security/py-oauth2client@${PY_FLAVOR}

post-patch:
	@${REINPLACE_CMD} -e 's|^docdir = .*|docdir = ${DOCSDIR}|' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|-R$$found_dir||' ${WRKSRC}/configure

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1/${PORTNAME}.1

.include <bsd.port.mk>
