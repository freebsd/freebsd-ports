# Created by: sgr
# $FreeBSD$

PORTNAME=	ochusha
PORTVERSION=	0.5.8.2
PORTREVISION=	10
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=		ochusha/16560

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI BBS browser for 2ch.net

MAN1=		ochusha.1
MANCOMPRESSED=	no

USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_PKGCONFIG=	yes

DESKTOP_ENTRIES="Ochusha" "${COMMENT}" \
		"${PREFIX}/share/ochusha/ochusha32.xpm" \
		"ochusha" "Network;" \
		false

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.* | ${XARGS} ${REINPLACE_CMD} -e \
		's|-DG.*_DISABLE_DEPRECATED||g'
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure \
		${WRKSRC}/libmodifiedghttp/configure ${WRKSRC}/libmodifiedgtk2/configure

.include <bsd.port.mk>
