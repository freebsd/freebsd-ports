PORTNAME=	devd-controller-rules
PORTVERSION=	2025.11.17
CATEGORIES=	games
MASTER_SITES=	https://raw.githubusercontent.com/libsdl-org/SDL/${SDL_COMMIT}/src/joystick/:headers
DISTFILES=	usb_ids.h:headers \
		controller_list.h:headers
DIST_SUBDIR=	${PORTNAME}/${DISTVERSION}
EXTRACT_ONLY=

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Rules for devd making game controller devices accessible to non-root users
WWW=		https://gist.github.com/shkhln/b39c2f3d609e57d47b7026da2a925aef

# The script itself is MIT, the database comes from SDL
LICENSE=	MIT ZLIB
LICENSE_COMB=	multi

USES=		ruby:build
USE_LOCALE=	en_US.UTF-8

SDL_COMMIT=	a882afafe55501711593d96f8f0f59f0e3adf3ee

PLIST_FILES=	etc/devd/${RULES_FILE}
RULES_FILE=	gamecontrollers.conf

do-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/usb_ids.h \
		${DISTDIR}/${DIST_SUBDIR}/controller_list.h ${WRKDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/freebsd-sdl-controller-devd-rules.rb ${WRKDIR}

do-build:
	cd ${WRKDIR} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} \
		./freebsd-sdl-controller-devd-rules.rb > ${WRKDIR}/${RULES_FILE}

do-install:
	${INSTALL_DATA} ${WRKDIR}/${RULES_FILE} ${STAGEDIR}${PREFIX}/etc/devd/

.include <bsd.port.mk>
