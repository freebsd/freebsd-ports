PORTNAME=	calcurse
DISTVERSION=	4.8.2
CATEGORIES=	deskutils
MASTER_SITES=	https://calcurse.org/files/ \
		https://fossies.org/linux/privat/

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Text-based calendar and scheduling application
WWW=		https://calcurse.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses shebangfix pkgconfig
SHEBANG_FILES=	contrib/caldav/calcurse-caldav \
		contrib/caldav/calcurse-caldav.py \
		contrib/vdir/calcurse-vdir \
		contrib/vdir/calcurse-vdir.py
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-asciidoc

OPTIONS_DEFINE=		CALDAV DOCS NLS
OPTIONS_DEFAULT=	CALDAV
OPTIONS_SUB=		yes

CALDAV_DESC=	Support Calendaring Extensions to WebDAV

CALDAV_USES=		python
CALDAV_USES_OFF=	python:env
CALDAV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}httplib2>=0:www/py-httplib2@${PY_FLAVOR}

DOCS_USES=		gmake
DOCS_CONFIGURE_ENABLE=	docs

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|^docdir = .*|docdir = ${DOCSDIR}|' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|-R$$found_dir||' ${WRKSRC}/configure

.include <bsd.port.mk>
