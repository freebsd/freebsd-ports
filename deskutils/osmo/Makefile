# New ports collection makefile for: osmo
# Date created:                      29 Sep 2009
# Whom:                              Charlie Kester <corky1951#comcast.net>
#
# $FreeBSD$
#

PORTNAME=	osmo
PORTVERSION=	0.2.10
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}-pim/${PORTNAME}-pim/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	corky1951@comcast.net
COMMENT=	A personal organizer

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		notify:${PORTSDIR}/devel/libnotify \
		ical:${PORTSDIR}/devel/libical \
		tar:${PORTSDIR}/devel/libtar \
		gringotts:${PORTSDIR}/security/libgringotts

USE_GNOME=	gtk20
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"

USE_GMAKE=	yes

MAN1=		osmo.1

POFILES=	ca cs de el es fi fr hu it ja lt nl pl pt \
		ru sv tr uk zh_CN

MSGFMT=		${LOCALBASE}/bin/msgfmt

post-patch:
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/Makefile.in

pre-install:
# workaround to problem in po makefile
.for p in ${POFILES}
	${MSGFMT} -c ${WRKSRC}/po/$p.po -o ${WRKSRC}/po/$p.mo
.endfor

.include <bsd.port.mk>
