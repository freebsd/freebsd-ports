# New ports collection makefile for:	ibus-anthy
# Date created:				30 Apr 2009
# Whom:					Daichi GOTO <daichi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ibus-anthy
PORTVERSION=	1.1.0.20090402
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	daichi@freebsd.org
COMMENT=	Anthy engine for IBus

BUILD_DEPENDS=	anthy.1:${PORTSDIR}/japanese/anthy \
		swig:${PORTSDIR}/devel/swig13
RUN_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus \
		anthy.1:${PORTSDIR}/japanese/anthy

USE_GNOME=	pygtk2
USE_GETTEXT=	yes
USE_PYTHON=	yes

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PROJECTHOST=	ibus

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|-I/usr/include|-I${LOCALBASE}/include|" ${WRKSRC}/engine/Makefile.am
	@${REINPLACE_CMD} -e "s|-I/usr/include|-I${LOCALBASE}/include|" ${WRKSRC}/engine/Makefile.in

.include <bsd.port.mk>
