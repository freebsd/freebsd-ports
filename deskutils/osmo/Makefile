# Created by: Charlie Kester <corky1951#comcast.net>
# $FreeBSD$

PORTNAME=	osmo
PORTVERSION=	0.2.10
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}-pim/${PORTNAME}-pim/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A personal organizer

LIB_DEPENDS=	libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libnotify.so:${PORTSDIR}/devel/libnotify \
		libical.so:${PORTSDIR}/devel/libical \
		libtar.so:${PORTSDIR}/devel/libtar \
		libgringotts.so:${PORTSDIR}/security/libgringotts \
		libgtkhtml.so:${PORTSDIR}/www/libgtkhtml

USE_GNOME=	gtk20
USES=		gettext gmake pkgconfig
INSTALLS_ICONS=	yes

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lintl
CFLAGS+=	-I${LOCALBASE}/include/libical

MAN1=		osmo.1

POFILES=	bg ca cs da de el en_GB es fi fr hu it ja lt nl pl pt \
		ru sv tr uk zh_CN

MSGFMT=		${LOCALBASE}/bin/msgfmt

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|-DGTK_DISABLE_DEPRECATED||g' \
		${WRKSRC}/src/Makefile.in

pre-install:
# workaround to problem in po makefile
.for p in ${POFILES}
	${MSGFMT} -c ${WRKSRC}/po/$p.po -o ${WRKSRC}/po/$p.mo
.endfor

.include <bsd.port.mk>
