# New ports collection makefile for:	GSnes9x
# Date created:				18 Jun 2000
# Whom:					Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	gsnes9x
PORTVERSION=	3.12
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	GSnes9x-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK front-end for the Snes9X SNES emulator

RUN_DEPENDS=	snes9x:${PORTSDIR}/emulators/snes9x

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnomelibs
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^SUBDIRS = intl|SUBDIRS =|g ; \
		 s|@INTLLIBS@|-lintl|g ; \
		 s|@INTLDEPS@||g'

.include <bsd.port.mk>
