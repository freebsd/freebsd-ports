# Created by: Michael Johnson <ahze@FreeBSD.org>
# $FreeBSD$
#    $MCom: ports/accessibility/java-access-bridge/Makefile,v 1.2 2007/03/06 14:03:02 ahze Exp $

PORTNAME=	java-access-bridge
PORTVERSION=	1.18.0
PORTREVISION=	8
CATEGORIES=	accessibility java gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Gnome Java Accessibility Bridge

BUILD_DEPENDS=	xprop:x11/xprop
RUN_DEPENDS=	xprop:x11/xprop

USES=		gmake pathfix pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	atspi
USE_JAVA=	yes
JAVA_OS=	native
CONFIGURE_ARGS=	--without-gcj-compile --with-jardir=${JAVAJARDIR}
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${prefix}/share/jar|${JAVAJARDIR}|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/bridge/Makefile.in

.include <bsd.port.mk>
