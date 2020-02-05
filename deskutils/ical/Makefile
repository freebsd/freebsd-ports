# Created by: Eric L. Hernes <erich@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ical
PORTVERSION=	3.0.4
CATEGORIES=	deskutils tk
MASTER_SITES=	https://launchpad.net/ical-tcl/+download/ \
		http://opal.com/jr/ical/

MAINTAINER=	fbsd@opal.com
COMMENT=	Calendar application

LICENSE=	GPLv2

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		autoreconf:build gmake tk xorg
USE_XORG=	x11 xext xft xrender xscrnsaver
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tkconfig=${TK_LIBDIR} \
		--with-tclconfig=${TCL_LIBDIR} \
		--with-tclsh=${TCLSH}
MAKE_ENV=	STAGEDIR=${STAGEDIR}
SUB_FILES=	pkg-message
SUB_LIST+=	VERSION=${PORTVERSION}
WRKSRC=		${WRKDIR}/${PORTNAME}-tcl

USER_TCL=	${HOME}/.tk/${PORTNAME}/user.tcl
DIST_VER=	${DISTNAME:S/${PORTVERSION}/${VERSION}/}

post-install:
	@${RM} ${STAGEDIR}/${PREFIX}/lib/ical/v${PORTVERSION}/contrib/*.patch
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
