# Created by: sgr
# $FreeBSD$

PORTNAME=	ochusha
PORTVERSION=	0.5.8.2
PORTREVISION=	13
CATEGORIES=	japanese
MASTER_SITES=	SFJP/ochusha/16560

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI BBS browser for 2ch.net

USES=		libtool pkgconfig tar:bzip2
USE_GNOME=	glib20 gtk20 libxml2
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

DESKTOP_ENTRIES="Ochusha" "${COMMENT}" \
		"${PREFIX}/share/ochusha/ochusha32.xpm" \
		"ochusha" "Network;" \
		false

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.* | ${XARGS} ${REINPLACE_CMD} -e \
		's|-DG.*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
