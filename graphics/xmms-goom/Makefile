# New ports collection makefile for:	xmms-goom
# Date created:				20 Jan 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	goom
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	goom
PKGNAMEPREFIX=	xmms-
DISTNAME=	xmms-goom_${PORTVERSION:S/.p/pre/}-2
EXTRACT_SUFX=	.tgz

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A cool XMMS visualization

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms \
		nasm:${PORTSDIR}/devel/nasm
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Visualization/libgoom.so
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gdkpixbuf
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}_${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|gtk-config|${GTK_CONFIG}|g; \
		s|-lgtk|`${GTK_CONFIG} --libs`|g; \
		s|-O9||' \
		${BUILD_WRKSRC}/src/Makefile.in

.include <bsd.port.post.mk>
