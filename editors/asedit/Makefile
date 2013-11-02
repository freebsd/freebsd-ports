# Created by: Andreas Kohout <shanee@augusta.de>
# $FreeBSD$

PORTNAME=	asedit
PORTVERSION=	1.3.2
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	XCONTRIB/editors
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text editor for X/Motif

USES=		imake:notall motif
USE_XORG=	ice sm x11 xext xmu xp xt

PLIST_FILES=	bin/asedit \
		lib/X11/app-defaults/Asedit \
		lib/X11/app-defaults/Asedit-sgi \
		lib/X11/app-defaults/Asedit_em \
		lib/X11/app-defaults/Asedit_em-sgi \
		lib/X11/asedit.hlp \
		lib/X11/asedit_em.hlp \
		man/man1/asedit.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		'/^XMLIB/s|-lPW|| ; \
		 /^DEFINES/s|-O ||' ${WRKSRC}/Imakefile

.include <bsd.port.mk>
