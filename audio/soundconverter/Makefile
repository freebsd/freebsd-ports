# Created by: Jona Joachim <jaj@hcl-club.lu>
# $FreeBSD$

PORTNAME=	soundconverter
PORTVERSION=	2.1.6
CATEGORIES=	audio python
MASTER_SITES=	https://launchpad.net/soundconverter/trunk/2.1.6/+download/ \
		http://BSDforge.com/projects/source/audio/soundconverter/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Sound conversion application for the GNOME environment

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gstreamer>=0.10:multimedia/py-gstreamer@${PY_FLAVOR}

NO_ARCH=	yes
USES=		desktop-file-utils gmake python:2 shebangfix tar:xz

SHEBANG_FILES=	bin/soundconverter.py

GNU_CONFIGURE=	yes
USE_GNOME=	intltool pygtk2 pygnome2
MAKE_ENV=	MAKE=${MAKE_CMD}
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} -e 's|@GMSGFMT@|${LOCALBASE}/bin/msgfmt|; \
		s|itlocaledir = .*|itlocaledir = ${LOCALBASE}/share/locale|g' \
			${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
