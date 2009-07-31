# New ports collection makefile for:	GSnes9x
# Date created:				18 Jun 2000
# Whom:					Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	gsnes9x
PORTVERSION=	3.12
PORTREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	SF
DISTNAME=	GSnes9x-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK front-end for the Snes9X SNES emulator

RUN_DEPENDS=	snes9x:${PORTSDIR}/emulators/snes9x

USE_GNOME=	gnomehack gnomeprefix gnomelibs
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^SUBDIRS = intl|SUBDIRS =|g ; \
		 s|@INTLLIBS@|-lintl|g ; \
		 s|@INTLDEPS@||g'

.include <bsd.port.mk>
