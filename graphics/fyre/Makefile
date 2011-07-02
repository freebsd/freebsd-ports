# New ports collection makefile for:	fyre
# Date created:				2004 11 July
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fyre
PORTVERSION=	1.0.1
CATEGORIES=	graphics
MASTER_SITES=	http://releases.navi.cx/fyre/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chaos map rendering system with GTK+-2 interface

OPTIONS=	OPT_CFLAGS "Enable additional optimizations (x86 only)" off \
		OPENEXR "Enable OpenEXR suport" on \
		GNET "Enable GNet support" on

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USE_BZIP2=	yes
USE_GNOME=	desktopfileutils libglade2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ENV=	LDFLAGS="${LDFLAGS}"
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && defined(WITH_OPT_CFLAGS)
CFLAGS+=	-march=native -O3 -ffast-math -fomit-frame-pointer
.endif

.if defined(WITHOUT_OPENEXR)
CONFIGURE_ARGS+=--disable-openexr
.else
LIB_DEPENDS+=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR
.endif

.if defined(WITHOUT_GNET)
CONFIGURE_ARGS+=--disable-gnet
.else
LIB_DEPENDS+=	gnet-2.0.0:${PORTSDIR}/net/gnet2
.endif

post-patch:
	@${REINPLACE_CMD} -e '/-O3/s|^|#|g' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@-update-desktop-database

.include <bsd.port.post.mk>
