PORTNAME=	asedit
PORTVERSION=	1.3.2
PORTREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	XCONTRIB/editors

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Text editor for X/Motif

DEPRECATED=	Last upstream release was in 2003
EXPIRATION_DATE=	2024-03-31

USES=		imake:notall motif tar:Z xorg
USE_XORG=	ice sm x11 xext xmu xt

PLIST_FILES=	bin/asedit \
		lib/X11/app-defaults/Asedit \
		lib/X11/app-defaults/Asedit-sgi \
		lib/X11/app-defaults/Asedit_em \
		lib/X11/app-defaults/Asedit_em-sgi \
		lib/X11/asedit.hlp \
		lib/X11/asedit_em.hlp \
		man/man1/asedit.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^XMLIB/s|-lPW|| ; \
		 /^DEFINES/s|-O ||' ${WRKSRC}/Imakefile

.include <bsd.port.post.mk>
