# New ports collection makefile for:	nano
# Date created:				12 June 2000
# Whom:				Philippe Lefebvre <nemesis@balistik.net>
#
# $FreeBSD$
#

PORTNAME=	nano
PORTVERSION=	1.2.2
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	http://www.nano-editor.org/dist/v1.2/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Nano's ANOther editor, an enhanced free Pico clone

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-all
USE_GETTEXT=	yes

INFO=		nano
MAN1=		nano.1
MAN5=		nanorc.5

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/nanorc.sample ${EXAMPLESDIR}

.include <bsd.port.mk>
