PORTNAME=	${GH_PROJECT:tl}
PORTVERSION=	1.95
DISTVERSIONPREFIX=	v
CATEGORIES=	editors python

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Free fully featured markdown editor
WWW=		https://github.com/jamiemcg/Remarkable \
		https://remarkableapp.github.io/linux.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}beautifulsoup>=0:www/py-beautifulsoup@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=0:textproc/py-markdown@${PY_FLAVOR} \
		webkit2-gtk_40>=0:www/webkit2-gtk@40
# Note to `www/webkit2-gtk' maintainers: feel free to change flavor as needed

USES=		gnome python:run shebangfix
USE_GNOME=	pygobject3 gtk30 gtksourceview3
SHEBANG_FILES=	bin/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	jamiemcg
GH_PROJECT=	Remarkable

NO_ARCH=	yes
NO_BUILD=	yes

# XXX: uncomment once ``install-desktop-entries.sh'' can handle %f in Exec
#DESKTOP_ENTRIES=	"${GH_PROJECT}" "" "${PORTNAME}" "${PORTNAME} %f" \
			"GNOME;Utility;" false

post-patch:
# Inhibit silly linuxish ``sys.path'' dances (unneeded on FreeBSD)
	@${REINPLACE_CMD} -e '30,+33s,^,#,' ${WRKSRC}/bin/remarkable
# Automagically adjust WebKit2 version to match RUN_DEPENDS above
	@${REINPLACE_CMD} -e "/^gi\.require_version('WebKit2'/ \
	    s,4\.[0-9],${_GET_WEBKIT_API_VERSION:sh}," \
		${WRKSRC}/remarkable/RemarkableWindow.py
# Where to look for resources on FreeBSD (respect ${DATADIR})
	@${REINPLACE_CMD} -e "/^__remarkable_data_directories__ = / \
	    s,'.*','${DATADIR}'," \
		${WRKSRC}/remarkable_lib/remarkableconfig.py

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${COPYTREE_SHARE} "pdfkit remarkable remarkable_lib" \
		${STAGEDIR}${PYTHON_SITELIBDIR}
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} "media ui" ${STAGEDIR}${DATADIR}

_GET_WEBKIT_API_VERSION=	${MAKE} -C ${RUN_DEPENDS:Mwebkit2-gtk*:C,.*:,${PORTSDIR}/,:S,@, FLAVOR=,} -V API_VERSION

.include <bsd.port.mk>
