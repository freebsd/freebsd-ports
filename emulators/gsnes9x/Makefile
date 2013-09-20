# Created by: Kelly Yancey <kbyanc@posi.net>
# $FreeBSD$

PORTNAME=	gsnes9x
PORTVERSION=	3.12
PORTREVISION=	10
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/GSnes9x/${PORTVERSION}
DISTNAME=	GSnes9x-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK front-end for the Snes9X SNES emulator

RUN_DEPENDS=	snes9x:${PORTSDIR}/emulators/snes9x

USES=        pathfix
USE_GNOME=	gnomeprefix gnomelibs
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^SUBDIRS = intl|SUBDIRS =|g ; \
		 s|@INTLLIBS@|-lintl|g ; \
		 s|@INTLDEPS@||g'

.include <bsd.port.mk>
