# New ports collection makefile for:	gnomepim
# Date created:				17 Jan 1999
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomepim
PORTVERSION=	1.4.9
PORTREVISION=	3
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.jroger.in-berlin.de/gnome-pim/
DISTNAME=	gnome-pim-${PORTVERSION}
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome pim package

USE_X_PREFIX=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs libcapplet
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LIBS=		-L${LOCALBASE}/lib
.if !defined(WITHOUT_PILOT)
CONFIGURE_ARGS=	--with-pisock=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
.endif
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LIBS="${LIBS}"

pre-extract:
	@${ECHO_MSG}
.if defined(WITHOUT_PILOT)
	@${ECHO_MSG} "Palm Pilot support disabled. You will not be able to syncronize"
	@${ECHO_MSG} "your palm with gnomecard and gnomecal."
.else
	@${ECHO_MSG} "You can disable Palm Pilot support by defining WITHOUT_PILOT."
.endif
	@${ECHO_MSG}

post-patch:
.for file in vcc.y vobject.c
	@${REINPLACE_CMD} -e "s/malloc[.]h/stdlib.h/g" ${WRKSRC}/libversit/${file}
.endfor

pre-install:
	${MKDIR} ${PREFIX}/share/gnome/help/gnomecard/C \
		${PREFIX}/share/gnome/help/gnomecard/eu

.include <bsd.port.mk>
