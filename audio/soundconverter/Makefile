# Created by: Jona Joachim <jaj@hcl-club.lu>
# $FreeBSD$

PORTNAME=	soundconverter
PORTVERSION=	1.5.4
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	BERLIOS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Sound conversion application for the GNOME environment

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gstreamer>=0.10:${PORTSDIR}/multimedia/py-gstreamer

USES=		gettext gmake desktop-file-utils python:2 shebangfix

SHEBANG_FILES=	src/soundconverter.py
python_OLD_CMD=	/usr/bin/python -tt

GNU_CONFIGURE=	yes
USE_GNOME=	intltool pygtk2 pygnome2
MAKE_ENV=	MAKE=${MAKE_CMD}
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|@GMSGFMT@|${LOCALBASE}/bin/msgfmt|; \
		s|itlocaledir = .*|itlocaledir = ${LOCALBASE}/share/locale|g' \
			${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
